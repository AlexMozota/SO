#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <signal.h>

#include <sys/wait.h>

 

int main(){

int i, j, status;

i = fork();

if (i > 0) {

printf("Hola soc el pare i el meu pid=%d \n", getpid());

fflush( stdout );

waitpid(-1, 0, WUNTRACED);

printf("Hola soc el pare i he de continuar... però millor que ho faci el meu fill xD\n ...Enviant SIGCONT...\n");

fflush( stdout );;

kill(i, SIGCONT);

waitpid(-1, 0, WUNTRACED);

waitpid(-1, 0, WUNTRACED);

} else {

printf("Hola soc el fill i el meu pid=%d \n", getpid());

fflush( stdout );

kill(getpid(), SIGSTOP);

printf("Hola soc el fill he rebut SIGCONT... ha treballar\n");

fflush( stdout );

exit(0);

}

printf("Hola soc el pare acabem el programa\n");

fflush( stdout );

exit(0);

}

