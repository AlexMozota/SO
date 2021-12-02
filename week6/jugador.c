#include <time.h>

#include <stdlib.h>

#include <stdio.h>

#include <signal.h>

#include <string.h>

#include <unistd.h>

#include <sys/types.h>

#include <sys/wait.h>

#include <errno.h>

 

// El jugador acabarà únicament per una notificació del pare. El temps s'ha exhaurit i cap jugador ha encertat la combinació del candau, o bé un dels jugadors han encertat la combinació i guanyen la partida.

void end_handler();

void end_handler(){

   exit(0);

}

 

int main()

{

signal(SIGUSR1, end_handler);

int n = 4;

char pass[n];

 

// Assignem una llavor aleatòria per cada procés

srand((unsigned int)(time(NULL)));

 

int i = 0;

// Realitzem un bucle infinit per evitar que el procés acabi.

while(1){


// Generem n caràcters de forma aleatòria. Utilitzem els seus codis ASCII (https://www.rapidtables.org/ca/code/text/ascii-table.html)
// Generarem codis amb lletres majúscules, minúscules i els símbols [ \ ] ^ _ '

for(i = 0; i < n; i++) {

pass[i] = 65 + rand() % 62; 

}

// Enviarem la combinació al procés pare utilitzant la pipe. Prèviament el procés ha duplicat la pipe al descriptor de fitxer número 3 assignat a aquest procés.

write(3,pass,n);

}

}