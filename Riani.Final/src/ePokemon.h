/*
 * ePokemon.h
 *
 *  Created on: 10 ago. 2022
 *      Author: brian
 */

#ifndef EPOKEMON_H_
#define EPOKEMON_H_

#define TAMSTR 51

#include "LinkedList.h"
typedef struct{

	int numero;
	char nombre[TAMSTR];
	char tipo[TAMSTR];
	char tamanio[TAMSTR];
	char ataqueCargado[TAMSTR];
	int valorAtaque;
	int esVarioColor;

}ePokemon;

ePokemon* ePokemon_newPokemon();
ePokemon* ePokemon_newParametros(char* numeroStr, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, char* valorAtaqueStr, char* varioColorStr);

int ePokemon_setNumero(ePokemon* this,int numero);
int ePokemon_getNumero(ePokemon* this,int* numero);

int ePokemon_setNombre(ePokemon* this,char* nombre);
int ePokemon_getNombre(ePokemon* this,char* nombre);

int ePokemon_setTipo(ePokemon* this,char* tipo);
int ePokemon_getTipo(ePokemon* this,char* tipo);

int ePokemon_setTamanio(ePokemon* this,char* tamanio);
int ePokemon_getTamanio(ePokemon* this,char* tamanio);

int ePokemon_setAtaqueCargado(ePokemon* this,char* ataque);
int ePokemon_getAtaqueCargado(ePokemon* this,char* ataque);

int ePokemon_setValorAtaque(ePokemon* this,int valor);
int ePokemon_getValorAtaque(ePokemon* this,int* valor);

int ePokemon_setVarioColor(ePokemon* this,int varioColor);
int ePokemon_getVarioColor(ePokemon* this,int* varioColor);

void ePokemon_imprimirPokemon(ePokemon* this);

ePokemon* ePokemon_buscarPokemonNumero(LinkedList* pArrayPokemon, int numero ,int* index);
int ePokemon_modificarValorAtaque(ePokemon* this);

void ePokemon_borrarPokemon(ePokemon* this);

#endif /* EPOKEMON_H_ */
