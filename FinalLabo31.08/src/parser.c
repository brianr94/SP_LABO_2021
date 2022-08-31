#include "parser.h"
#include "LinkedList.h"
#include "ePokemon.h"
#include <stdlib.h>
#include <stdio.h>

int parser_pokemonFromText(FILE* pFile , LinkedList* pArrayListPokemon)
{
	ePokemon* newPokemon=NULL;
	char numero[50];
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	char valorAtaque[50];
	char varioColor[50];
	int cantidadLineas;

	int retorno=-1;

	if(pFile != NULL && pArrayListPokemon != NULL)
	{

		do
		{

			cantidadLineas=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,], %[^,], %[^\n]\n", numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, varioColor);

			if(cantidadLineas==7)
			{
				newPokemon=ePokemon_newParametros(numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, varioColor);

				if(newPokemon != NULL)
				{
					ll_add(pArrayListPokemon, newPokemon);
					retorno=0;
				}
			}
			else
			{
				break;
			}


		}while(!feof(pFile));

		fclose(pFile);

	}
    return retorno;
}

