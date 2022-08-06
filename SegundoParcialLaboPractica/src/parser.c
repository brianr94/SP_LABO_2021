/*
 * parser.c
 *
 *  Created on: 4 ago. 2022
 *      Author: brian
 */


#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "parser.h"
#include "ePerrito.h"
#include "controller.h"
#include <ctype.h>


int parser_PerritoFromText(FILE* pFile, LinkedList* pArrayListPerrito)
{
	ePerrito* perrito=NULL;
	char id[50];
	char nombre[50];
	char peso[50];
	char edad[50];
	char raza[50];
	int cantidadLineas;

	int retorno=-1;

	if(pFile != NULL && pArrayListPerrito != NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, peso, edad, raza);

		do
		{

			cantidadLineas=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, peso, edad, raza);

			if(cantidadLineas==5)
			{
				perrito=ePerrito_newParametros(id, nombre, peso, edad, raza);

				if(perrito != NULL)
				{
					ll_add(pArrayListPerrito, perrito);
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
