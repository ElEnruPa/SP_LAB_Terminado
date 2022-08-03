#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int montes_pokemon_loadFromText(char* path , LinkedList* pArrayListPassenger);
int montes_pokemon_modificaValorAtaque(LinkedList* pArrayListPassenger);
int montes_pokemon_ListPokemones(LinkedList* pArrayListPassenger);
int montes_pokemon_filtroFuego(char* path, LinkedList* pArrayListPassenger);
int montes_pokemon_filtroXLyPoison(LinkedList* pArrayListPassenger);
int montes_pokemon_ataqueMapeado(LinkedList* pArrayListPassenger);
int montes_pokemon_cantidadPokemonesParaBatalla(LinkedList* pArrayListPassenger);

#endif /* CONTROLLER_H_ */
