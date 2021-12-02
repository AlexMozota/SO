#include <stdlib.h>

#include <stdio.h>

#include <signal.h>

#include <string.h>

#include <unistd.h>

#include <sys/types.h>

#include <sys/wait.h>

#include <errno.h>

 

// Definim dues variables per controlar la situació de la partida. 

int atrapats = 0;

int jugant = 1;

 

char *color_blue = "\033[01;34m";

char *color_end = "\033[00m";

char *color_red = "\033[01;31m";

char *color_green = "\033[01;32m";

 

char *args[] = {"jugador", "jugador", NULL};

// Rutina de tractament de l'alarma, notifiquem per stdout amb color vermell el missatge de DING DONG i modifiquem les variables globals jugant i atrapats per poder procés la situació de la partida.

void alarm_handler();

void alarm_handler(){

char s[100];

sprintf(s, "%s**********DING DONG %s\n", color_red, color_end);

write(1,s,strlen(s));

atrapats=1;

jugant=0;

}

 

int main(int argc, char *argv[])

{

int fd[2];

char s[100];

// Per poder utilitzar el programa passarem 3 arguments: el temps de la partida, el nombre de jugadors i la clau per obrir el candau. Per tant, comprovem que ens passin el nombre correcte d'arguments.

if (argc < 4) {

fprintf(stderr, "Usage: %s tempsPartida numJugadors clau \n", argv[0]);

exit(1);

}

 

int numJugadors = atoi(argv[2]);

int tempsPartida = atoi(argv[1]);

char* clau = argv[3];

// Ens guardarem els pids dels n processos en un array (int *). Recordeu que amb malloc reservem de forma dinàmica la memòria d'aquest array.

int* pids = malloc(numJugadors * sizeof(int));

// Definirem l'alarma utilitzant el segons entrats com a paràmetre d'entrada.

signal(SIGALRM, alarm_handler);


// Obrirem una pipe per comunicar amb els processos fills

if (pipe(fd)<0)

{

perror("El procés [Sala]::Error de creació del pipe");

exit(1);

}

 

sprintf(s, "Inici del Room Escape [%d] (%d segons) \n",getpid(),tempsPartida);

if (write(1, s, strlen(s)) < 0) perror("write");

 

sprintf(s, "--- Entren %d jugadors a la sala \n",numJugadors);

if (write(1, s, strlen(s)) < 0) perror("write");

 

sprintf(s, "--- La paraula a endevinar és = %s\n",clau);

if (write(1, s, strlen(s)) < 0) perror("write");

 

// Crearem els processos fills i ens guardarem els seus pids.

for(int i = 0; i<numJugadors; i=i+1){

 

switch (pids[i]=fork()){

 

case -1:  /* Error en la creació del procés fill */

perror("Sala::fork()");

exit(2);

break;

 

case 0:

// Tanquem la sortida de lectura, el procés fill únicament ha d'escriure.

if (close(fd[0]) < 0) perror("close");

// Dupliquem l'escriptura del pipe al descriptor de fitxer 3, en cas de tenir-lo assignat primer el tancarà.

if (dup2(fd[1], 3) < 0) perror("dup2");

// Tanquem la sortida escriptura del pipe, ara ja no la necessitem.

if (close(fd[1]) < 0) perror("close");

// Fem el recubriment amb el codi de jugador

execv(args[0], args);

exit(-1);

default:

sprintf(s, "%s EscapeRoom[%d] ha entrat el jugador[%d] %s\n", color_blue, getpid(), pids[i], color_end);

if (write(1, s, strlen(s)) < 0) perror("write");

}

}

// Tanquem la sortida escriptura, el procés para únicament ha de llegir.

close(fd[1]);

// Iniciem la partida

alarm(tempsPartida);

 

char car[4];

int leidos;

 

while((jugant==1)&&(read(fd[0],&car,sizeof(car))>0))

{

if ( car[0] == clau[0] && car[1] == clau[1] && car[2] == clau[2] && car[3] == clau[3]){

sprintf(s,"--- Els jugadors obren el candau amb la clau %s \n",clau);

if (write(1, s, strlen(s)) < 0) perror("write");

jugant=0;

break;

}

}

 

for(int i = 0; i<numJugadors; i++){

if (atrapats==1){

sprintf(s, "%s El jugador [%d] ha quedat atrapat i surt de EscapeRoom[%d]. %s\n", color_red, pids[i],getpid(), color_end);

if (write(1, s, strlen(s)) < 0) perror("write");

}

else{

sprintf(s, "%s El jugador [%d] ha escapat i surt de EscapeRoom[%d]. %s\n", color_green, pids[i],getpid(), color_end);

if (write(1, s, strlen(s)) < 0) perror("write");

}

kill(pids[i], SIGUSR1);

wait(NULL);

}

 

if (atrapats==1){

sprintf(s, "--- El jugadors han perdut la partida. Fins aviat. \n");

if (write(1, s, strlen(s)) < 0) perror("write");

}

else {

sprintf(s, "--- El jugadors ha guanyat la partida en %d segons. \n", tempsPartida - alarm(tempsPartida));

if (write(1, s, strlen(s)) < 0) perror("write");

}

close(fd[0]);

exit(0);

}