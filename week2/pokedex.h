

#ifndef _POKEDEX_H_
#define _POKEDEX_H_



int add_pokemon(int id, char *name, char *type, int total, int hp , int attack , int defense , int spAttack, iint spDefense , int speed, int generation, int captured );
int remove_pokemon();
int show_pokemon(int pos);
int init_pokedex();
#endif 