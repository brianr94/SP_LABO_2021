#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "eParticipantes.h"
#include "informes.h"
#include <string.h>



int eParticipantes_filterByMX1(void* eParticipante)
{
	int retorno=-1;
	char categoria[100];

	eParticipantes* participante;

	if(eParticipante != NULL)
	{
		participante=(eParticipantes*) eParticipante;


		eParticipantes_getCategoria(participante, categoria);

		if(strcmp(categoria,"MX1")==0)
		{
			retorno=0;
		}

	}

	return retorno;
}

int eParticipantes_filterByMX2(void* eParticipante)
{
	int retorno=-1;
	char categoria[100];

	eParticipantes* participante;

	if(eParticipante != NULL)
	{
		participante=(eParticipantes*) eParticipante;


		eParticipantes_getCategoria(participante, categoria);

		if(strcmp(categoria,"MX2")==0)
		{
			retorno=0;
		}

	}

	return retorno;
}

int eParticipantes_filterByMX3(void* eParticipante)
{
	int retorno=-1;
	char categoria[100];

	eParticipantes* participante;

	if(eParticipante != NULL)
	{
		participante=(eParticipantes*) eParticipante;


		eParticipantes_getCategoria(participante, categoria);

		if(strcmp(categoria,"MX3")==0)
		{
			retorno=0;
		}

	}

	return retorno;
}

int eParticipantes_filterBySuperATV(void* eParticipante)
{
	int retorno=-1;
	char categoria[100];

	eParticipantes* participante;

	if(eParticipante != NULL)
	{
		participante=(eParticipantes*) eParticipante;


		eParticipantes_getCategoria(participante, categoria);

		if(strcmp(categoria,"SUPER_ATV")==0)
		{
			retorno=0;
		}

	}

	return retorno;
}

void eParticipantes_asignarPromedio(void* eParticipante)
{
	eParticipantes* participante;
	int tiempoAux;
	int promedioAux;

	if(eParticipante != NULL)
	{
		participante=(eParticipantes*)eParticipante;

		eParticipantes_getTiempo(participante, &tiempoAux);
		eParticipantes_getPromedio(participante, &promedioAux);


		if(tiempoAux>20)
		{
			promedioAux=10;
		}
		else
		{
			if(tiempoAux<=20 && tiempoAux>=15)
			{
				promedioAux=8;
			}
			else
			{
				promedioAux=6;
			}
		}

		eParticipantes_setPromedio(participante, promedioAux);
	}
}

int eParticipantes_SortByAverage(void* participante1, void* participante2)
{
	int retorno=-1;
	int promedioI;
	int promedioJ;
	char categoriaI[100];
	char categoriaJ[100];

	eParticipantes* pParticipanteI;
	eParticipantes* pParticipanteJ;

	if(participante1 != NULL && participante2 != NULL)
	{

		pParticipanteI=(eParticipantes*)participante1;
		pParticipanteJ=(eParticipantes*)participante2;

		eParticipantes_getCategoria(pParticipanteI, categoriaI);
		eParticipantes_getCategoria(pParticipanteJ, categoriaJ);
		eParticipantes_getPromedio(pParticipanteI, &promedioI);
		eParticipantes_getPromedio(pParticipanteJ, &promedioJ);



		if(strcmp(categoriaI,categoriaJ) == 0 && promedioI > promedioJ)
		{
			retorno= 1;
		}

	}

	return retorno;
}

int eParticipantes_SortByCategory(void* participante1, void* participante2)
{
	int retorno=-1;
	char categoriaI[100];
	char categoriaJ[100];

	eParticipantes* pParticipanteI;
	eParticipantes* pParticipanteJ;

	if(participante1 != NULL && participante2 != NULL)
	{

		pParticipanteI=(eParticipantes*)participante1;
		pParticipanteJ=(eParticipantes*)participante2;

		eParticipantes_getCategoria(pParticipanteI, categoriaI);
		eParticipantes_getCategoria(pParticipanteJ, categoriaJ);



		if(strcmp(categoriaI,categoriaJ) > 0)
		{
			retorno= 1;
		}

	}

	return retorno;
}
