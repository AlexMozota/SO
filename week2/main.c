#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>
#include "pokedex.h"

 
#define OPTSTR "a:s:r:h"
#define WELCOME_MSG (printf("===[ Pokemon Management Service ]===\n\
Welcome to the PMS! How can I help?\n\
================================================================\n"))
#define USAGE_FMT "%s options: \n\
-add [pokemon_id] [name] [height] [weight] [type1] [type2] \n\
Add a Pokemon to the Pokedex \n\
-show [position]] \n\
Display details of the Pokemon with position in the pokedex = posiiton \n\
-remove [position] \n\
Delete the Pokemon with position in the pokedex = posiiton\n\
-help\n"
#define ERR_ADD_POKEMON "add_pokemon blew up"
#define ERR_REMOVE_POKEMON "remove pokemon blew up"
#define ERR_SHOW_POKEMON "show pokemon blew up"
#define DEFAULT_PROGNAME "pokemon_management_service"
 
extern int errno;
 
void usage(char *progname, int opt);
int add_pokemon();
int show_pokemon();
int remove_pokemon();
 
int main(int argc, char *argv[]) {
int opt;
opterr = 0;
WELCOME_MSG;
init_pokedex();


while ((opt = getopt(argc, argv, OPTSTR)) != EOF)
switch(opt) {
case 'a':
if (add_pokemon(atoi(argv[2]),argv[3],atof(argv[4]),atof(argv[5]) ) != EXIT_SUCCESS) {
perror(ERR_ADD_POKEMON);
exit(EXIT_FAILURE);
}
break;
case 's':
if (show_pokemon(atoi(argv[2]) != EXIT_SUCCESS)) {
perror(ERR_SHOW_POKEMON);
exit(EXIT_FAILURE);
}
break;
case 'r':
if (remove_pokemon() != EXIT_SUCCESS) {
perror(ERR_REMOVE_POKEMON);
exit(EXIT_FAILURE);
}
break;
case 'h':
default:
usage(basename(argv[0]), opt);
/* NOTREACHED */
break;
}
return EXIT_SUCCESS;
}
 
void usage(char *progname, int opt) {
fprintf(stderr, USAGE_FMT, progname?progname:DEFAULT_PROGNAME);
exit(EXIT_FAILURE);
/* NOTREACHED */
}
 

/*
Pokemon p = malloc(sizeof(struct pokemon));

p->pokemon_id = 01;
p->name = "charmander";
p->weight = 33;
p->height = 22;

Pokemon p = new_pokemon(atoi(argv[1]), argv[2], atof(argv[3]), atof(argv[4]));

printf("id: %d \n", pokemon_id(p));
printf("name: %s \n", pokemon_name(p));
printf("weight: %lf \n", pokemon_weight(p));
printf("height: %lf \n", pokemon_height(p));
*/


