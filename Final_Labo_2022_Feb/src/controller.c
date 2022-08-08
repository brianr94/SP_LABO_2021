
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "controller.h"
#include "informes.h"
#include "parser.h"
#include "eParticipantes.h"
#include "utn_inputs.h"

int controller_validateLoadFromText(char* path , LinkedList* pArrayListParticipantes)
{

	int retorno=-1;
	char file[51];
	FILE* pFile;

	pedirCadena(file, "Ingrese el archivo a cargar(incluir el formato en el nombre .csv): ", "Error. Ingrese nuevamente el nombre del archivo: ", 51);

	if(strcmp(path,file) != 0)
	{
		printf("\nArchivo ingresado no existe!!!!. Cargue nuevamente el arhivo\n");
	}
	else
	{
		printf("\nArchivo encontrado.Cargando....!!!\n");

		pFile= fopen(path,"r");

		if(path != NULL && pArrayListParticipantes != NULL)
		{
			retorno=parser_participanteFromText(pFile, pArrayListParticipantes);
			printf("\nSe cargo el arhivo %s correctamente!!!\n",path);
		}

	}

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListParticipantes)
{
	int retorno=1;
	int i;
	int length;
	int idAux;
	char nombre[50];
	char categoria[50];
	int tiempoAux;
	int promedioAux;


	eParticipantes* participante;

	FILE* pFile;

	pFile=fopen(path,"w");

	if(path != NULL && pArrayListParticipantes != NULL)
	{
		length=ll_len(pArrayListParticipantes);
		if(pFile != NULL)
		{
			fprintf(pFile,"%s\n","id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio");
			for(i=0;i<length;i++)
			{
				participante=ll_get(pArrayListParticipantes, i);

				if(participante != NULL)
				{
					eParticipantes_getId(participante, &idAux);
					eParticipantes_getNombre(participante, nombre);
					eParticipantes_getCategoria(participante, categoria);
					eParticipantes_getTiempo(participante,&tiempoAux);
					eParticipantes_getPromedio(participante, &promedioAux);

					fprintf(pFile,"%d,%s,%s,%d,%d\n",idAux,nombre,categoria,tiempoAux,promedioAux);
				}
			}

			fclose(pFile);
			printf("\nArchivo '%s' guardado correctamente.\n",path);
		}
		else
		{
			printf("\nError.Archivo no creado!!!\n");
		}

		retorno=0;
	}
    return retorno;
}

int controller_listarParticipantes(LinkedList* pArrayListParticipantes)
{
	int retorno=-1;
	int len;
	eParticipantes* particiante=NULL;


	if(pArrayListParticipantes != NULL)
	{
		len=ll_len(pArrayListParticipantes);
		printf("\n%-5s %-15s %-20s %-20s %-15s\n","ID", "Nombre", "Categoria", "Tiempo", "Promedio");
		for(int i=0;i<len;i++)
		{
			particiante=ll_get(pArrayListParticipantes, i);

			eParticipantes_imprimirParticipante(particiante);
		}

		retorno=0;
	}
	return retorno;
}

int controller_asignarPromedio(LinkedList* pArrayListParticipantes)
{
	int retorno=-1;

	if(pArrayListParticipantes != NULL)
	{
		ll_map(pArrayListParticipantes, eParticipantes_asignarPromedio);
		retorno=0;
	}

	return retorno;
}

int controller_filtrarPorCategoria(LinkedList* pArrayListParticipantes)
{
	int retorno=-1;
	int opcion;
	LinkedList* listaFiltrada=NULL;
	int (*pFuncion)(void* elemento);
	char path[50];

	pFuncion=NULL;

	if(pArrayListParticipantes != NULL)
	{

		pedirNumeroEnteroValidado(&opcion,
											"-------------------------------------\n"
											"1. Filtrar por categoria MX1\n"
											"2. Filtrar por categoria MX2\n"
											"3. Filtrar por categoria MX3\n"
											"4. Filtrar por categoria SUPER ATV\n"
											"-------------------------------------\n"
											"Ingrese una opcion: ",
											"-------------------------------------\n"
											"1. Filtrar por categoria MX1\n"
											"2. Filtrar por categoria MX2\n"
											"3. Filtrar por categoria MX3\n"
											"4. Filtrar por categoria SUPER ATV\n"
											"---------------------------------------\n"
											"Error.Ingrese opcion correcta: ", 1, 4);


		switch(opcion)
		{
			case 1:
				pFuncion=eParticipantes_filterByMX1;
				strcpy(path,"MX1.csv");
				retorno=0;
				break;
			case 2:
				pFuncion=eParticipantes_filterByMX2;
				strcpy(path,"MX2.csv");
				retorno=0;
				break;
			case 3:
				pFuncion=eParticipantes_filterByMX3;
				strcpy(path,"MX3.csv");
				retorno=0;
				break;
			case 4:
				pFuncion=eParticipantes_filterBySuperATV;
				strcpy(path,"SUPER_ATV.csv");
				retorno=0;
				break;
		}

		listaFiltrada= ll_filter(pArrayListParticipantes, pFuncion);

		if(listaFiltrada != NULL)
		{
			controller_saveAsText(path, listaFiltrada);
		}

	}

	return retorno;
}

int controller_participantesOrdenadoPorCategoria(LinkedList* pArrayListParticipantes)
{
	int retorno=-1;

	if(pArrayListParticipantes != NULL)
	{
		if(ll_sort(pArrayListParticipantes, eParticipantes_SortByCategoryAndAverage, 1) != -1)
		{
			controller_listarParticipantes(pArrayListParticipantes);
			retorno=0;
		}
	}

	return retorno;
}
