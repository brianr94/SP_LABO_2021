#include <stdlib.h>
#include <stdio.h>
#include "ePokemon.h"
#include <string.h>

int ePokemon_filtrarPorAguaVarioColor(void* pokemon)
{
	int retorno=-1;
	char tipo[100];
	int esVarioColor;

	ePokemon* pPokemon;

	if(pokemon != NULL)
	{
		pPokemon=(ePokemon*) pokemon;


		ePokemon_getTipo(pPokemon, tipo);
		ePokemon_getVarioColor(pPokemon, &esVarioColor);

		if(strcmp(tipo,"Water")==0 && esVarioColor==1)
		{
			retorno=0;
		}

	}

	return retorno;
}


void ePokemon_mapeoAtaqueCargado(void* pokemon)
{
	ePokemon* pPokemon;
	char tipoAux[50];
	int valorAtaque;
	int aumentoPoder;

	if(pokemon != NULL)
	{
		pPokemon=(ePokemon*)pokemon;

		ePokemon_getTipo(pPokemon, tipoAux);
		ePokemon_getValorAtaque(pPokemon, &valorAtaque);

		if(strcmp(tipoAux,"Fire")== 0 || strcmp(tipoAux,"Ground")== 0 || strcmp(tipoAux,"Grass") == 0)
		{
			aumentoPoder=(valorAtaque*10) / 100;
			valorAtaque=aumentoPoder + valorAtaque;
		}
		ePokemon_setValorAtaque(pPokemon, valorAtaque);
	}
}

//criterio para el ll_count tener cuidado con los retornos porque la funcion los utiliza
//siempre fijarse segun el caso, pero que retornen 0 si no cumple con el criterio y 1 si lo cumple.
//el retorno sirve segun la funcion de criterio. No siempre es 1 o 0. siempre hay que ver el Enunciado!!!
//va a utilizar el retorno como acumulador o "contador"
int ePokemon_cantidadPokemonFuego(ePokemon* pokemon)
{
	ePokemon* pPokemon;
	int valorAtaque;
	char ataqueCargado[50];
	char tamanio[50];
	char tipo[50];
	int retorno=0;

	if(pokemon != NULL)
	{
		pPokemon=(ePokemon*)pokemon;

		ePokemon_getValorAtaque(pPokemon, &valorAtaque);
		ePokemon_getAtaqueCargado(pPokemon, ataqueCargado);
		ePokemon_getTipo(pPokemon, tipo);
		ePokemon_getTamanio(pPokemon, tamanio);

		if(strcmp(tipo,"Fire")==0 && strcmp(ataqueCargado,"Lanzallamas")==0 && strcmp(tamanio,"XL")==0 && valorAtaque>80)
		{
			retorno=1;
		}
	}

	return retorno;
}

//criterio para el ll_count tener cuidado con los retornos porque la funcion los utiliza
//siempre fijarse segun el caso, pero que retornen 0 si no cumple con el criterio y 1 si lo cumple.
//el retorno sirve segun la funcion de criterio. No siempre es 1 o 0. siempre hay que ver el Enunciado!!!
//va a utilizar el retorno como acumulador o "contador"
int ePokemon_cantidadPokemonWater(ePokemon* pokemon)
{
	ePokemon* pPokemon;
	int valorAtaque;
	char ataqueCargado[50];
	char tamanio[50];
	char tipo[50];
	int retorno=0;

	if(pokemon != NULL)
	{
		pPokemon=(ePokemon*)pokemon;

		ePokemon_getValorAtaque(pPokemon, &valorAtaque);
		ePokemon_getAtaqueCargado(pPokemon, ataqueCargado);
		ePokemon_getTipo(pPokemon, tipo);
		ePokemon_getTamanio(pPokemon, tamanio);

		if(strcmp(tipo,"Water")==0 && strcmp(ataqueCargado,"Hidrobomba")==0 && strcmp(tamanio,"L")==0 && valorAtaque >= 80)
		{
			retorno=1;
		}
	}

	return retorno;
}
