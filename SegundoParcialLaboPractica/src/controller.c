/*
 * controller.c
 *
 *  Created on: 4 ago. 2022
 *      Author: brian
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "parser.h"
#include "LinkedList.h"
#include "ePerrito.h"

int controller_cargaDeArhivoTexto(char* path , LinkedList* pArrayListPerrito)
{
	int retorno=-1;
	FILE* pFile;

	pFile= fopen(path,"r");

	if(path != NULL && pArrayListPerrito != NULL)
	{
		retorno=parser_perritoFromText(pFile, pArrayListPerrito);

	}


    return retorno;
}

int controller_saveAsText(LinkedList* pArrayListPerrito, char* path)
{
	int retorno=1;
	int i;
	int len;
	int idAux;
	char nombre[50];
	float pesoAux;
	int edadAux;
	char raza[50];
	float cantidadAux;


	ePerrito* perrito;

	FILE* pFile;

	pFile=fopen(path,"w");

	if(path != NULL && pArrayListPerrito != NULL)
	{
		len=ll_len(pArrayListPerrito);
		if(pFile != NULL)
		{
			fprintf(pFile,"%s\n","ID,nombre,peso,edad,raza,cantidadComidaRacion");

			for(i=0;i<len;i++)
			{
				perrito=ll_get(pArrayListPerrito, i);

				if(perrito != NULL)
				{
					ePerrito_getId(perrito, &idAux);
					ePerrito_getNombre(perrito, nombre);
					ePerrito_getPeso(perrito, &pesoAux);
					ePerrito_getEdad(perrito,&edadAux);
					ePerrito_getRaza(perrito, raza);
					ePerrito_getCantidadRacion(perrito, &cantidadAux);

					fprintf(pFile,"%d,%s,%.2f,%d,%s,%.2f\n",idAux,nombre,pesoAux,edadAux,raza,cantidadAux);
				}
			}

			fclose(pFile);
			printf("Archivo '%s' guardado correctamente. \n",path);
		}
		else
		{
			printf("\nError.Archivo no creado!!!\n");
		}

		retorno=0;
	}

    return retorno;
}


int controller_listarPerritos(LinkedList* pArrayListPerrito)
{

	int retorno=-1;
	int len;

	ePerrito perrito;

	if(pArrayListPerrito != NULL)
	{
		len=ll_len(pArrayListPerrito);
		printf("\n%-5s %-15s %-20s %-20s %-15s %-20s\n","ID", "Nombre", "Peso", "Edad", "Raza");
		for(int i=0; i<len;i++)
		{
			perrito=ll_get(pArrayListPerrito, i);

			ePerrito_imprimirPerrito(perrito);
		}
		retorno= 0;
	}

	return retorno;
}

int controller_listarPerritosRacionComida(LinkedList* pArrayListPerrito)
{

	int retorno=-1;
	int len;

	ePerrito perrito;

	if(pArrayListPerrito != NULL)
	{
		len=ll_len(pArrayListPerrito);
		printf("\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n","ID", "Nombre", "Peso", "Edad", "Raza","CantidadComidaRacion");
		for(int i=0; i<len;i++)
		{
			perrito=ll_get(pArrayListPerrito, i);

			ePerrito_imprimirPerritoRacion(perrito);
		}
		retorno= 0;
	}

	return retorno;
}

int controller_asignacionTotalComidaRacion(LinkedList* pArrayListPerrito)
{
	int retorno=-1;

	if(pArrayListPerrito != NULL)
	{

		ll_map(pArrayListPerrito, ePerrito_calculoComidaRacion);
		retorno=0;
	}

	return retorno;
}

int controller_filterByGalgo(LinkedList* pArrayListPerrito)
{
	int retorno=-1;

	LinkedList* listaFiltrada=NULL;

	if(pArrayListPerrito != NULL)
	{

		ll_filter(listaFiltrada, ePerrito_filtrarGalgos);
		retorno=0;
	}

	return retorno;
}

int controller_ordenarPerroPorNombre(LinkedList* pArrayListPerrito)
{
	int retorno=-1;

	if(pArrayListPerrito != NULL)
	{
		ll_sort(pArrayListPerrito, ePerrito_sortByName, 1);
		retorno=0;
	}

	return retorno;
}

