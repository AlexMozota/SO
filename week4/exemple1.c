#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main () {
        pid_t p1 = fork();
        if (p1 > 0){
                printf("Hola sóc el procés amb pid %d \n", getpid());fflush(stdout);

               
        }else{
                
                printf("Hola soc el fill amb pid %d \n", getpid( ));fflush(stdout);
                exit(0);
        }

        wait(NULL);
        exit(0);
}