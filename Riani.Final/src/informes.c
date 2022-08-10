#include <stdlib.h>
#include <stdio.h>
#include "ePokemon.h"
#include <string.h>

int ePokemon_filtrarPorFuego(void* pokemon)
{
	int retorno=-1;
	char tipo[100];

	ePokemon* pPokemon;

	if(pokemon != NULL)
	{
		pPokemon=(ePokemon*) pokemon;


		ePokemon_getTipo(pPokemon, tipo);

		if(strcmp(tipo,"Fire")==0)
		{
			retorno=0;
		}

	}

	return retorno;
}

int ePokemon_filtrarPorTamanioYVeneno(void* pokemon)
{
	int retorno=-1;
	char tipo[100];
	char tamanio[100];

	ePokemon* pPokemon;

	if(pokemon != NULL)
	{
		pPokemon=(ePokemon*) pokemon;


		ePokemon_getTipo(pPokemon, tipo);
		ePokemon_getTamanio(pPokemon, tamanio);

		if(strcmp(tipo,"Poison")==0 && strcmp(tamanio,"XL")==0)
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
	char tamanioAux[50];
	int valorAtaque;
	int aumentoPoder;

	if(pokemon != NULL)
	{
		pPokemon=(ePokemon*)pokemon;

		ePokemon_getTipo(pPokemon, tipoAux);
		ePokemon_getTamanio(pPokemon, tamanioAux);
		ePokemon_getValorAtaque(pPokemon, &valorAtaque);

		if(strcmp(tipoAux,"Bug")==0 || strcmp(tipoAux,"Fire")==0 || strcmp(tipoAux,"Grass") == 0)
		{
			if(strcmp(tamanioAux,"XL")==0)
			{

				aumentoPoder=(valorAtaque*20) / 100;
				valorAtaque=aumentoPoder + valorAtaque;
			}
			else
			{
				if(strcmp(tamanioAux,"L")==0)
				{

					aumentoPoder=(valorAtaque*10) / 100;
					valorAtaque=aumentoPoder + valorAtaque;
				}
				else
				{
					aumentoPoder=(valorAtaque*5) / 100;
					valorAtaque=aumentoPoder+ valorAtaque;
				}

			}
		}
		ePokemon_setValorAtaque(pPokemon, valorAtaque);
	}
}

int ePokemon_cantidadPokemonFuego(ePokemon* pokemon)
{
	ePokemon* pPokemon;
	int valorAtaque;
	char ataqueCargado[50];
	char tamanio[50];
	char tipo[50];
	int retorno=-1;

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

int ePokemon_cantidadPokemonWater(ePokemon* pokemon)
{
	ePokemon* pPokemon;
	int valorAtaque;
	char ataqueCargado[50];
	char tamanio[50];
	char tipo[50];
	int retorno=-1;

	if(pokemon != NULL)
	{
		pPokemon=(ePokemon*)pokemon;

		ePokemon_getValorAtaque(pPokemon, &valorAtaque);
		ePokemon_getAtaqueCargado(pPokemon, ataqueCargado);
		ePokemon_getTipo(pPokemon, tipo);
		ePokemon_getTamanio(pPokemon, tamanio);

		if(strcmp(tipo,"Water")==0 && strcmp(ataqueCargado,"Hidrobomba")==0 && strcmp(tamanio,"L")==0 && valorAtaque > 80)
		{
			retorno=1;
		}
	}

	return retorno;
}
