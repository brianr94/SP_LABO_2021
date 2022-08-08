
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "controller.h"
#include "eParticipantes.h"
#include "utn_inputs.h"

int controller_cargaDeArhivoTexto(char* path, LinkedList* pArrayListParticipantes)
{
	int retorno=-1;
	FILE* pFile;

	pFile= fopen(path,"r");

	if(path != NULL && pArrayListParticipantes != NULL)
	{
		retorno=parser_PerritoFromText(pFile, pArrayListParticipantes);
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

	pFuncion=NULL;

	if(pArrayListParticipantes != NULL)
	{

		pedirNumeroEnteroValidado(&opcion,
											"-------------------------------------\n"
											"1. Filtrar por categoria MX1\n"
											"2. Filtrar por categoria MX2\n"
											"3. Filtrar por categoria MX3\n"
											"4. Filtrar por categoria SUPER ATV\n"
											"5. volver\n"
											"-------------------------------------\n"
											"Ingrese una opcion: ",
											"-------------------------------------\n"
											"1. Filtrar por categoria MX1\n"
											"2. Filtrar por categoria MX2\n"
											"3. Filtrar por categoria MX3\n"
											"4. Filtrar por categoria SUPER ATV\n"
											"5. volver\n"
											"---------------------------------------\n"
											"Error.Ingrese opcion correcta: ", 1, 5);


		switch(opcion)
		{
			case 1:
				pFuncion=eParticipantes_filterByMX1;
				retorno=0;
				break;
			case 2:
				pFuncion=eParticipantes_filterByMX2;
				break;
			case 3:
				pFuncion=eParticipantes_filterByMX3;
				break;
			case 4:
				pFuncion=eParticipantes_filterBySuperATV;
				break;
			case 5:
				break;
		}

		listaFiltrada= ll_filter(pArrayListParticipantes, pFuncion);

		if(listaFiltrada != NULL)
		{
			//controller_saveAsText(
		}

	}


}
