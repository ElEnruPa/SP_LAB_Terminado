#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Pokemon.h"
#include "LinkedList.h"


Pokemon* Pokemon_new() //Constructor
{
	Pokemon* unPasajero;
	unPasajero = (Pokemon*) malloc(sizeof(Pokemon)); //Crea el espacio en memoria dinamica
	return unPasajero;
}

Pokemon* Pokemon_newParametros(char* numeroStr, char* nombreStr, char* tipoStr, char* tamanioStr, char* ataqueCargadoStr, char* valorAtaqueStr, char* esVarioColorStr) //Constructor
{
	Pokemon* unPokemon;

	unPokemon = Pokemon_new();

	Pokemon_setNumero(unPokemon, atoi(numeroStr));
	Pokemon_setNombre(unPokemon, nombreStr);
	Pokemon_setTipo(unPokemon, tipoStr);
	Pokemon_setTamanio(unPokemon, tamanioStr);
	Pokemon_setAtaqueCargado(unPokemon, ataqueCargadoStr);
	Pokemon_setValorAtaque(unPokemon, atoi(valorAtaqueStr));
	Pokemon_setEsVarioColor(unPokemon, atoi(esVarioColorStr));

	if((numeroStr==NULL) && (nombreStr==NULL) && (tipoStr==NULL) && (tamanioStr==NULL) && (ataqueCargadoStr==NULL) && (valorAtaqueStr==NULL) && (esVarioColorStr==NULL))
	{
		Pokemon_delete(unPokemon);

		if(unPokemon==NULL)
		{
			Pokemon_delete(unPokemon);
		}
	}

	return unPokemon;
}

void Pokemon_delete(Pokemon* this) //Destructor
{
	free(this);
}

void Pokemon_printOne(Pokemon* this)
{
	if(this!=NULL)
	{
		int numero;
		char nombre[20];
		char tipo[30];
		char tamanio[10];
		char ataqueCargado[30];
		int valorAtaque;
		int esVarioColor;

		int getnumero;
		int getNombre;
		int gettipo;
		int getTamanio;
		int getAtaqueCargado;
		int getValorAtaque;
		int getEsVarioColor;

		getnumero = Pokemon_getNumero(this, &numero);
		getNombre = Pokemon_getNombre(this, nombre);
		gettipo = Pokemon_getTipo(this, tipo);
		getTamanio = Pokemon_getTamanio(this, tamanio);
		getAtaqueCargado = Pokemon_getAtaqueCargado(this, ataqueCargado);
		getValorAtaque = Pokemon_getValorAtaque(this, &valorAtaque);
		getEsVarioColor = Pokemon_getEsVarioColor(this, &esVarioColor);

		if(getnumero==1 && getNombre==1 && gettipo==1 && getTamanio==1 && getAtaqueCargado==1 && getValorAtaque==1 && getEsVarioColor==1)
		{
			printf("%6d | %14s | %11s | %7s | %17s | %12d | %14d |\n", numero,
																	  nombre,
																	  tipo,
																	  tamanio,
																	  ataqueCargado,
																	  valorAtaque,
																	  esVarioColor);
		}
	}
}



int Pokemon_setNumero(Pokemon* this,int numero)
{
	int ok;
	ok=0;

	if(this!=NULL && numero>0)
	{
		this->numero = numero;
		ok=1;
	}

	return ok;
}

int Pokemon_getNumero(Pokemon* this,int* numero)
{
	int ok;
	ok=0;

	if(this!=NULL && numero!=NULL)
	{
		*numero = this->numero;
		ok=1;
	}

	return ok;
}

int Pokemon_setNombre(Pokemon* this,char* nombre)
{
	int ok;
	ok=0;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		ok=1;
	}

	return ok;
}

int Pokemon_getNombre(Pokemon* this,char* nombre)
{
	int ok;
	ok=0;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		ok=1;
	}

	return ok;
}

int Pokemon_setTipo(Pokemon* this,char* tipo)
{
	int ok;
	ok=0;

	if(this!=NULL && tipo!=NULL)
	{
		strcpy(this->tipo,tipo);
		ok=1;
	}

	return ok;
}

int Pokemon_getTipo(Pokemon* this,char* tipo)
{
	int ok;
	ok=0;

	if(this!=NULL && tipo!=NULL)
	{
		strcpy(tipo,this->tipo);
		ok=1;
	}

	return ok;
}

int Pokemon_setTamanio(Pokemon* this,char* tamanio)
{
	int ok;
	ok=0;

	if(this!=NULL && tamanio!=NULL)
	{
		strcpy(this->tamanio,tamanio);
		ok=1;
	}

	return ok;
}

int Pokemon_getTamanio(Pokemon* this,char* tamanio)
{
	int ok;
	ok=0;

	if(this!=NULL && tamanio!=NULL)
	{
		strcpy(tamanio,this->tamanio);
		ok=1;
	}

	return ok;
}

int Pokemon_setAtaqueCargado(Pokemon* this,char* ataqueCargado)
{
	int ok;
	ok=0;

	if(this!=NULL && ataqueCargado!=NULL)
	{
		strcpy(this->ataqueCargado,ataqueCargado);
		ok=1;
	}

	return ok;
}

int Pokemon_getAtaqueCargado(Pokemon* this,char* ataqueCargado)
{
	int ok;
	ok=0;

	if(this!=NULL && ataqueCargado!=NULL)
	{
		strcpy(ataqueCargado,this->ataqueCargado);
		ok=1;
	}

	return ok;
}

int Pokemon_setValorAtaque(Pokemon* this,int valorAtaque)
{
	int ok;
	ok=0;

	if(this!=NULL && valorAtaque>0)
	{
		this->valorAtaque = valorAtaque;
		ok=1;
	}

	return ok;
}

int Pokemon_getValorAtaque(Pokemon* this,int* valorAtaque)
{
	int ok;
	ok=0;

	if(this!=NULL && valorAtaque!=NULL)
	{
		*valorAtaque = this->valorAtaque;
		ok=1;
	}

	return ok;
}

int Pokemon_setEsVarioColor(Pokemon* this,int esVarioColor)
{
	int ok;
	ok=0;

	if(this!=NULL && esVarioColor>=0)
	{
		this->esVarioColor = esVarioColor;
		ok=1;
	}

	return ok;
}

int Pokemon_getEsVarioColor(Pokemon* this,int* esVarioColor)
{
	int ok;
	ok=0;

	if(this!=NULL && esVarioColor!=NULL)
	{
		*esVarioColor = this->esVarioColor;
		ok=1;
	}

	return ok;
}

void limpiar()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int filtroFuego(void* p1)
{
	int ok;
	ok = 0;
	Pokemon* this;
	this = (Pokemon*) p1;
	char tipo[20];

	Pokemon_getTipo(this, tipo);

	if(strcmp(tipo,"Fire") == 0)
	{
		ok = 1;
	}
	return ok;
}

int filtroXLyPoison(void* p1)
{
	int ok;
	ok = 0;
	Pokemon* this;
	this = (Pokemon*) p1;
	char tamanio[10];
	char tipo[20];

	Pokemon_getTamanio(this, tamanio);
	Pokemon_getTipo(this, tipo);


	if((strcmp(tamanio, "XL") == 0) && (strcmp(tipo, "Poison") == 0))
	{
		ok = 1;
	}

	return ok;
}

int modificacionValorAtaque(void* p1)
{
	int ok;
	ok = 0;
	Pokemon* this;
	this = (Pokemon*) p1;
	char tamanio[10];
	char tipo[20];
	int valorAtaque;

	Pokemon_getTamanio(this, tamanio);
	Pokemon_getTipo(this, tipo);
	Pokemon_getValorAtaque(this, &valorAtaque);

	if((strcmp(tipo, "Bug") == 0) || (strcmp(tipo, "Fire") == 0) || (strcmp(tipo, "Grass") == 0))
	{
		if((strcmp(tamanio, "XL") == 0))
		{
			valorAtaque*=1.2;
			Pokemon_setValorAtaque(this, valorAtaque);
		}
		else
		{
			if((strcmp(tamanio, "L") == 0))
			{
				valorAtaque*=1.1;
				Pokemon_setValorAtaque(this, valorAtaque);
			}
			else
			{
				valorAtaque*=1.05;
				Pokemon_setValorAtaque(this, valorAtaque);
			}
		}
	}

	return ok;
}

int pasoParametro(void* p1)
{
	int ok = 0;

	Pokemon* this;
	this = (Pokemon*) p1;
	char tipo[20];
	char tamanio[10];
	char ataqueCargado[30];
	int valorAtaque;

	Pokemon_getTipo(this, tipo);
	Pokemon_getTamanio(this, tamanio);
	Pokemon_getAtaqueCargado(this, ataqueCargado);
	Pokemon_getValorAtaque(this, &valorAtaque);

	if(((strcmp(tipo, "Fire") == 0) && (strcmp(tamanio, "XL") == 0) && (strcmp(ataqueCargado, "Lanzallamas") == 0) && valorAtaque >= 80) ||
	((strcmp(tipo, "Water") == 0) && (strcmp(tamanio, "L") == 0) && (strcmp(ataqueCargado, "Hidrobomba") == 0) && valorAtaque >= 80))
	{
		ok = 1;
	}
	return ok;
}

void validarEntero(int* numero, int minimo, int maximo)
{
	while(*numero < minimo || *numero > maximo)
	{
		printf("Ingrese un numero valido (%d-%d): ",minimo, maximo);
		fflush(stdin);
		scanf("%d",numero);
	}
}




