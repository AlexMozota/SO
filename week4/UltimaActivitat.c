#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


int genrandom()  {
srand(getpid()); 
int r = rand()%2; 

return r;
}

int main(){
    int causaMortFill;

    int causaMortNet;

    int morts;

    int esperarmorts;

int pid1 = fork(); 

    if (pid1 > 0){


    printf("Hola sóc Rickard Stark casat amb Lyarra Stark amb pid %d\n", getpid());
    wait(&morts);
    int esperarmorts= WEXITSTATUS(morts);
    if(esperarmorts==1){
        printf("Els dos han estat apunyalats\n");
    }
    if(esperarmorts==2){
        printf("Els dos han estat decapitats\n");
    }
    if(esperarmorts==3){
        printf("El Ned ha estat apunyalat i eel Robb decapitat\n");
    }
    if(esperarmorts==4){
        printf("El Ned ha estat decapitat i el Robb apunyalat\n");
    }

    }else{

    int pid2 = fork();

    int codiRetorn;


    if (pid2 > 0){

    int causaMortFill = genrandom();

    printf("Hola sóc en Ned fill del matrimoni del Richard i la Lyarra amb pid %d\n", getpid());
    wait(&codiRetorn); //Desbloqujem amb el SIGCHLD exit1
    int causaMortNet = WEXITSTATUS(codiRetorn) ;
      if(causaMortFill==1){
        printf("Soc en Ned amb pid %d i he estat decapitat\n", getpid());

    }else{
        printf("Soc en Ned amb pid %d i he estat apunyalat\n", getpid());
    }
    
    if (causaMortFill == 0 && causaMortNet == 0){
        exit(1); // exit2 (SIGCHLD)
    }
    if (causaMortFill==1 && causaMortNet==1){
        exit(2);
    }
    if (causaMortFill==0 && causaMortNet==1){
        exit(3);
        }
     if (causaMortFill==1 && causaMortNet==0){
        exit(4);
        }

    }else{

    // NET (FILL)
    int causaMortNet = genrandom();

    printf("Hola sóc en Robb Stark amb pid %d , soc un fill del matrimoni de la Catelyn Stark i Ned Stark\n", getpid());
    
    if(causaMortNet==1){
        printf("Soc en Robb amb pid %d i he estat decapitat\n", getpid());
    }else{
        printf("Soc en Robb amb pid %d i he estat apunyalat\n", getpid());
    }

    exit(causaMortNet); // exit1 (SIGCHLD)

        }
    }
    return 0;
}