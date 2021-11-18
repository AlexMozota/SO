#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include "pokemon.h"
 
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
int endFlag=1;
int codiretorn;
 
while (endFlag == 1) {
 
char s[100];
char choice;
sprintf(s, "################\n# E. Explore \n# Q. Quit\n################\n");
if (write(1, s, strlen(s)) < 0) perror("Error writting the menu");
scanf(" %c", &choice);
 

switch (choice) {
case 'Q':
endFlag=0;
break;
case 'E':

int pid = fork(); 
if (pid == 0 ){

int num = getrandom();
FILE* f = fopen("./Llpekomon.csv", "r");
while (fgets(buf, 100, f) != NULL) {
    if ((strlen(buf)>0) && (buf[strlen (buf) - 1] == '\n'))
        buf[strlen (buf) - 1] = '\0';
    info = strtok(buf, ",");
    int id = atoi(info);
    printf("%d ", id);
    info = strtok(NULL, ",");
    char *name = info;
    printf("%s ", name);

    info = strtok(NULL, ",");
    char *type  = atof(info);
    printf("type1: %s,type2;%s ",type[1],type[2] );
    info = strtok(NULL, ",");
    int total = atof(info);
    printf("%d \n" ,total);
    info = strtok(NULL, ",");
    int hp =  atof(info);
    printf("%d \n" ,hp);

    Pokemon p = new_pokemon(id, name, type, total, ,hp ,attack, defense,spAttack,spDefense, speed, generation, legendary);
    pokemons[i] = p;
    i++;

}
fclose(f);

wait(&codiretorn);
int pidfill =WEXITSTATUS(codiretorn);
printf("Wild pokemon appeared %d" ,pidfill);
printf();
wait();


}else{

int elegir;
int pidfill=getpid();
exit(pidfill);
sprintf(s, "################\n# P. Trhow Pokeball \n# R. Run\n################\n");
scanf ("%c",&elegir);
switch(elegir){
    case 'P':

    case 'R':
    kill

}

}
break;
default:
sprintf(s, "%s!!!!Invalid option. Try again. %s\n", KRED, KNRM);
if (write(1, s, strlen(s)) < 0) perror("Error writting invalid option");
}
}
 
char s[100];
sprintf(s, "%s!!!!I'm tired from all the fun... %s\n", KMAG, KNRM);
if (write(1, s, strlen(s)) < 0) perror("Error writting the ending msg");
exit(0);
 
}