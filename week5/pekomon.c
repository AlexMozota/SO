#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RUNINDIR "./"
#define LOGFILE RUNINDIR "log.txt"

enum accions {pokemonEscaped = 7,pokemonCaptured = 2};

void logger ( char* missatge){
    time_t now;
    time(&now);
    FILE* f = fopen(LOGFILE, "a");
    fprintf(f,"%s:%s \n",ctime(&now) ,missatge );
    fclose(f);
}


int getrandom(){
    
    return rand()%151;
}


void tractament(){
    int num= getrandom();
    char log[100];
    sprintf(log," el valor de la variable es :%d \n",num);
    logger(log);
    if(num==pokemonEscaped){
        exit(pokemonEscaped);
    }
    if(num==pokemonCaptured){
    exit(pokemonCaptured);
    }
    else {
        kill (getpid(), SIGSTOP);
    }

}

        


    
int main(){
signal(SIGUSR1,tractament);

    srand (getpid());

    while(1){

    }
}