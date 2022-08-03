#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Pokemon.h"
#include "Parser.h"

/** \brief Carga los datos de los pokemones desde el archivo Data_Pokemones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int (0) si no funciona, (1) si funciona correctamente
 */
int montes_pokemon_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int ok;
	ok=0;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pFile = fopen(path,"r");

		if(pFile != NULL)
		{
			parser_PokemonFromText(pFile, pArrayListPassenger);
			ok=1;
		}

		fclose(pFile);
	}

    return ok;
}

/** \brief Modificar el valor de ataque de un pokemon
 * \param pArrayListPassenger LinkedList*
 * \return int (0) si no funciona, (1) si funciona correctamente
 *
 */
int montes_pokemon_modificaValorAtaque(LinkedList* pArrayListPassenger)
{
	int ok;
	int numero;
	int numeroAux;
	int len;
	ok=0;

	Pokemon* unPokemon = NULL;
	int valorAtaque;

	if(pArrayListPassenger!=NULL)
	{
		printf("Ingrese el numero del pokemon que quiere modificar el valor del ataque (1-151): ");
		fflush(stdin);
		scanf("%d",&numero);
		validarEntero(&numero, 1, 151);

		len = ll_len(pArrayListPassenger);

		if(len > 0)
		{
			for(int i=0; i<len; i++)
			{
				unPokemon = (Pokemon*) ll_get(pArrayListPassenger,i);

				if(unPokemon != NULL)
				{
					if(Pokemon_getNumero(unPokemon, &numeroAux) == 1)
					{
						if(numeroAux == numero)
						{
							printf("Ingrese el nuevo valor de ataque: ");
							fflush(stdin);
							scanf("%d",&valorAtaque);
							validarEntero(&valorAtaque, 0, 100000000);

							if(Pokemon_setValorAtaque(unPokemon, valorAtaque) == 1)
							{
								ok = 1;
							}
						}
					}
				}
			}
		}
	}

    return ok;
}

/** \brief Listar pokemones
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int (0) si no funciona, (1) si funciona correctamente
 *
 */
int montes_pokemon_ListPokemones(LinkedList* pArrayListPassenger)
{
	Pokemon* unPokemon;
	int len;
	int ok;
	ok=0;

	if(pArrayListPassenger!=NULL)
	{
		len = ll_len(pArrayListPassenger);

		if(len > 0)
		{
			printf("NUMERO |     NOMBRE     |     TIPO    | TAMANIO |   ATAQUE CARGADO  | VALOR ATAQUE | ES VARIO COLOR |\n"
					"-----------------------------------------------------------------------------------------------------\n");
			for(int i=0; i<len; i++)
			{
				unPokemon = (Pokemon*) ll_get(pArrayListPassenger, i);

				if(unPokemon!=NULL)
				{
					Pokemon_printOne(unPokemon);
				}
			}
			ok=1;
		}
	}

    return ok;
}

/** \brief Crea un nuevo archivo .csv con la lista de los pokemones filtrados del tipo fuego
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int (0) si no funciona, (1) si funciona correctamente
 *
 */
int montes_pokemon_filtroFuego(char* path, LinkedList* pArrayListPassenger)
{
	int ok;
	LinkedList* listaFiltrada = NULL;
	int len;
	Pokemon* unPokemon;
	ok = 0;

	int numero;
	char nombre[20];
	char tipo[30];
	char tamanio[10];
	char ataqueCargado[30];
	int valorAtaque;
	int esVarioColor;

	int getNumero;
	int getNombre;
	int getTipo;
	int getTamanio;
	int getAtaqueCargado;
	int getValorAtaque;
	int getEsVarioColor;


	if(path != NULL && pArrayListPassenger != NULL)
	{
		listaFiltrada = ll_filter(pArrayListPassenger, filtroFuego);

		if(listaFiltrada != NULL)
		{
			FILE* pFile = fopen(path, "w");

			if(pFile != NULL)
			{
				len = ll_len(listaFiltrada);

				if(len > 0)
				{
					for(int i=0; i<len; i++)
					{
						unPokemon = (Pokemon*) ll_get(listaFiltrada, i);

						if(unPokemon != NULL)
						{
							getNumero = Pokemon_getNumero(unPokemon, &numero);
							getNombre = Pokemon_getNombre(unPokemon, nombre);
							getTipo = Pokemon_getTipo(unPokemon, tipo);
							getTamanio = Pokemon_getTamanio(unPokemon, tamanio);
							getAtaqueCargado = Pokemon_getAtaqueCargado(unPokemon, ataqueCargado);
							getValorAtaque = Pokemon_getValorAtaque(unPokemon, &valorAtaque);
							getEsVarioColor = Pokemon_getEsVarioColor(unPokemon, &esVarioColor);

							if(getNumero==1 && getNombre==1 && getTipo==1 && getTamanio==1 && getAtaqueCargado==1 && getValorAtaque==1 && getEsVarioColor==1)
							{
								fprintf(pFile,"%d,%s,%s,%s,%s,%d,%d\n",numero
														   			  ,nombre
																	  ,tipo
																	  ,tamanio
																	  ,ataqueCargado
																	  ,valorAtaque
																	  ,esVarioColor);
								ok=1;
							}
						}
					}
				}
			}
			fclose(pFile);
		}
	}
	return ok;
}

/** \brief Filtra los pokemones del tamaño XL y del tipo poison y los imprime por pantalla
 *
 * \param pArrayListPassenger LinkedList*
 * \return int (0) si no funciona, (1) si funciona correctamente
 *
 */
int montes_pokemon_filtroXLyPoison(LinkedList* pArrayListPassenger)
{
	int ok;
	LinkedList* listaFiltrada = NULL;
	int len;
	Pokemon* unPokemon;
	ok = 0;

	if(pArrayListPassenger != NULL)
	{
		listaFiltrada = ll_filter(pArrayListPassenger, filtroXLyPoison);

		if(listaFiltrada != NULL)
		{
			len = ll_len(listaFiltrada);

			if(len > 0)
			{
				printf("NUMERO |     NOMBRE     |     TIPO    | TAMANIO |   ATAQUE CARGADO  | VALOR ATAQUE | ES VARIO COLOR |\n"
						"-----------------------------------------------------------------------------------------------------\n");
				for(int i=0; i<len; i++)
				{
					unPokemon = (Pokemon*) ll_get(listaFiltrada, i);

					if(unPokemon!=NULL)
					{
						Pokemon_printOne(unPokemon);
					}
				}
				ok=1;
			}
		}
	}
	return ok;
}

/** \brief Mapea los pokemones que pasan el filtro de la modificacion de ataque.
 *
 * \param pArrayListPassenger LinkedList*
 * \return int (0) si no funciona, (1) si funciona correctamente
 *
 */
int montes_pokemon_ataqueMapeado(LinkedList* pArrayListPassenger)
{
	int ok;
	if(pArrayListPassenger != NULL)
	{
		ok = ll_map(pArrayListPassenger, modificacionValorAtaque);
	}
	return ok;
}

/** \brief Cuenta la cantidad de pokemones que pasan la funcion de pasoParametro.
 *
 * \param pArrayListPassenger LinkedList*
 * \return La cantidad de pokemones que pueden pelear la batalla.
 *
 */
int montes_pokemon_cantidadPokemonesParaBatalla(LinkedList* pArrayListPassenger)
{
	int contador = 0;

	if(pArrayListPassenger != NULL)
	{
		contador = ll_count(pArrayListPassenger, pasoParametro);

		printf("%d son los pokemones que cumplen las caracteristicas para la batalla.\n", contador);
	}
	return contador;
}




