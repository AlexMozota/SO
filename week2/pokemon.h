


//Pokemon *p;

typedef struct pokemon *Pokemon;

Pokemon create_pokemon();

Pokemon new_pokemon(int pokemon_id, char *name, double height,double weight);
int pokemon_id(Pokemon pokemon);
char *pokemon_name(Pokemon pokemon);
double pokemon_height(Pokemon pokemon);
double pokemon_weight(Pokemon pokemon);