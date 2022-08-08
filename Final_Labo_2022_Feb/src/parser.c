#include "parser.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include "eParticipantes.h"

int parser_participanteFromText(FILE* pFile, LinkedList* pArrayListParticipantes)
{
	eParticipantes* participante=NULL;
	char id[50];
	char nombre[50];
	char categoria[50];
	char tiempo[50];
	char promedio[50];
	int cantidadLineas;

	int retorno=-1;

	if(pFile != NULL && pArrayListParticipantes != NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, categoria, tiempo, promedio);

		do
		{

			cantidadLineas=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, categoria, tiempo, promedio);

			if(cantidadLineas==5)
			{
				participante=eParticipantes_newParametros(id, nombre, categoria, tiempo, promedio);

				if(participante != NULL)
				{
					ll_add(pArrayListParticipantes, participante);
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

