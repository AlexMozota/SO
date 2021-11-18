#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "pokemon.h"

struct pokemon {
int id;
char name[32];
char type[2][32];
int total;
int hp;
int attack;
int defense;
int spAttack;
int spDefense;
int speed;
int generation;
int legendary;
int seen;
int captured;
};
/*
Pokemon create_pokemon()
{
    FILE* f = fopen("./pokedex.csv", "w");
    Pokemon newP;
    
    printf("Enter pokemon id: ");
    scanf("%d", newP.pokemon_id);

    printf("Enter pokemon name: ");
    scanf("%s", newP.pokemon_name);

    printf("Enter pokemon height: ");
    scanf("%lf", newP.pokemon_height);

    printf("Enter pokemon weight: ");
    scanf("%d", newP.pokemon_weight);

    sprintf(f, newP.pokemon_id()),strlen(newP.pokemon_id());
    sprintf(f, ",");
    sprintf(f, newP.pokemon_name(),strlen(newP.pokemon_name()));
    sprintf(f, ",");
    sprintf(f, newP.pokemon_height(),strlen(newP.pokemon_height()));
    sprintf(f, ",");
    sprintf(f, newP.pokemon_weight(),strlen(newP.pokemon_weight()));
    sprintf(f, "\n");
}
*/

Pokemon new_pokemon(int pokemon_id, char *name, double height,double weight)
{  
    Pokemon pokemon = malloc(sizeof(struct pokemon));
    pokemon->pokemon_id = pokemon_id;
    pokemon->name = name;
    pokemon->height = height;
    pokemon->weight = weight;

    return pokemon;
    
}

int pokemon_id(Pokemon pokemon)
{
    return pokemon->pokemon_id;
}
char *pokemon_name(Pokemon pokemon)
{
    return pokemon->name;
}
double pokemon_height(Pokemon pokemon)
{
    return pokemon->height;
}
double pokemon_weight(Pokemon pokemon)
{
    return pokemon->weight;
}
