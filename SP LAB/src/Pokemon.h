#ifndef POKEMON_H_
#define POKEMON_H_

typedef struct
{
	int numero;
	char nombre[20];
	char tipo[20];
	char tamanio[10];
	char ataqueCargado[30];
	int valorAtaque;
	int esVarioColor;

}Pokemon;

Pokemon* Pokemon_new();
Pokemon* Pokemon_newParametros(char* numeroStr, char* nombreStr, char* tipoStr, char* tamanioStr, char* ataqueCargadoStr, char* valorAtaqueStr, char* esVarioColorStr);
void Pokemon_delete(Pokemon* this);
void Pokemon_printOne(Pokemon* this);

int Pokemon_setNumero(Pokemon* this,int numero);
int Pokemon_getNumero(Pokemon* this,int* numero);

int Pokemon_setNombre(Pokemon* this,char* nombre);
int Pokemon_getNombre(Pokemon* this,char* nombre);

int Pokemon_setTipo(Pokemon* this,char* tipo);
int Pokemon_getTipo(Pokemon* this,char* tipo);

int Pokemon_setTamanio(Pokemon* this,char* tamanio);
int Pokemon_getTamanio(Pokemon* this,char* tamanio);

int Pokemon_setAtaqueCargado(Pokemon* this,char* ataqueCargado);
int Pokemon_getAtaqueCargado(Pokemon* this,char* ataqueCargado);

int Pokemon_setValorAtaque(Pokemon* this,int valorAtaque);
int Pokemon_getValorAtaque(Pokemon* this,int* valorAtaque);

int Pokemon_setEsVarioColor(Pokemon* this,int esVarioColor);
int Pokemon_getEsVarioColor(Pokemon* this,int* esVarioColor);

void limpiar();
int filtroFuego(void* p1);
int filtroXLyPoison(void* p1);
int modificacionValorAtaque(void* p1);
int pasoParametro(void* p1);
void validarEntero(int* numero, int minimo, int maximo);


#endif /* POKEMON_H_ */
