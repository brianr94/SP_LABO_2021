/*
 * controller.c
 *
 *  Created on: 4 ago. 2022
 *      Author: brian
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller.c"
#include "parser.h"


int controller_cargaDeArhivoTexto(char* path , LinkedList* pArrayListPerrito)
{
	int retorno=1;
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
					ePeerito_getNombre(perrito, nombre);
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
