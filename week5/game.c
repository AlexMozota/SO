

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include "pokedex/pokedex.h"
 
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
 
char *args[] = {"pokemon", "pokemon", NULL};
 
int main(int arc, char *arv[])
{
    
char s[100];
int endFlag=1;
 
    while (endFlag == 1) {
    
   
    char choice;
    sprintf(s, "################\n# E. Explore \n# Q. Quit\n################\n");
        if (write(1, s, strlen(s)) < 0) perror("Error writting the menu");
        fflush(stdout);
        scanf(" %c", &choice);
        

        switch (choice) {
        case 'Q':
        endFlag=0;
        break;
        case 'E':
        ;
        int pid = fork();

        if (pid > 0) {

        //show_pokemon();
        int endflag2 = 1 ; 
        while (endflag2 == 1) {
        
            char choice2;
            sprintf(s, "################\n# P. Trhow pokeball \n# R. Run\n################\n");
            if (write(1, s, strlen(s)) < 0) perror("Error writting the menu");
            scanf(" %c", &choice2);

            switch (choice2) {
                case 'R':
                 endflag2 = 0 ;
                 break;
                case 'P': 
                ;
                int st ; 
                waitpid(pid, &st , WUNTRACED);

                int status = WEXITSTATUS(st);

                if ( status == 2 ){
                    endflag2 = 0 ;
                }
                if ( status == 7 ){
                    endflag2 = 0 ;
                }
                else{

                    kill ( pid , SIGCONT);
                }
                break;
            }
        }
        }
        if (pid == 0) {

        execv("./pekomon", args) ;

        }



        break;
    default:
    sprintf(s, "%s!!!!Invalid option. Try again. %s\n", KRED, KNRM);
    if (write(1, s, strlen(s)) < 0) perror("Error writting invalid option");
    }
    }
    
    
    sprintf(s, "%s!!!!I'm tired from all the fun... %s\n", KMAG, KNRM);
    if (write(1, s, strlen(s)) < 0) perror("Error writting the ending msg");
    exit(0);
    
    
    
}
