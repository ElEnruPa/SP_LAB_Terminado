#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Pokemon.h"

/** \brief Parsea los datos los datos de los pokemones desde el archivo Data_Pokemones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PokemonFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int ok;
	int escaneo;
	ok=0;

	Pokemon* unPokemon;
	char numero[10];
	char nombre[40];
	char tipo[40];
	char tamanio[10];
	char ataqueCargado[30];
	char valorAtaque[10];
	char esVarioColor[10];

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{

		while(!feof(pFile))
		{
			escaneo = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n",numero,
																						nombre,
																						tipo,
																						tamanio,
																						ataqueCargado,
																						valorAtaque,
																						esVarioColor);

			if(escaneo==7)
			{
				unPokemon = Pokemon_newParametros(numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVarioColor);

				if(unPokemon!=NULL)
				{
					ll_add(pArrayListPassenger, unPokemon);
				}
			}
		}

		ok=1;
	}

    return ok;
}
