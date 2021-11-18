#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pokedex.h"
#include "pokemon.h"
#include <string.h>
#define MAX_POKEMON 10

Pokemon pokemons[MAX_POKEMON];

char*info;
int init_pokedex(){
int i = 0;
char* buf = malloc(100);

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

return EXIT_SUCCESS;
}


int add_pokemon(int id, char *name, double weight, double height){
    new_pokemon(id, name, weight, height);


    FILE* f = fopen("./pokedex.csv", "a");

    fprintf(f,"\n %d,%s,%lf,%lf\n",id,name,weight,height);
    fclose(f);



return EXIT_SUCCESS;
}
 
int show_pokemon(int pos){
    Pokemon p = pokemons[pos];

    printf("id: %d \n", pokemon_id(p));
    printf("name: %s \n", pokemon_name(p));
    printf("weight: %lf \n", pokemon_weight(p));
    printf("height: %lf \n", pokemon_height(p));


return EXIT_SUCCESS;
}
 
int remove_pokemon(){
printf("[remove_pokemon]: @NOT IMPLEMENTED \n");
return EXIT_SUCCESS;
}
 

