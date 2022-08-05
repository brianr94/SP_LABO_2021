/*
 * ePerrito.c
 *
 *  Created on: 3 ago. 2022
 *      Author: brian
 */

#include "ePerrito.h"
#include <stdlib.h>
#include <stdio.h>


ePerrito* ePerrito_newPerrito()
{
	ePerrito* perrito=NULL;

	perrito=(ePerrito*)malloc(sizeof(ePerrito));

	return perrito;
}

ePerrito* ePerrito_newParametros(char* idStr, char* nombre, char* pesoStr, char* edadStr, char* raza)
{
	int idAux;
	float pesoAux;
	int edadAux;
	ePerrito* newPerrito=NULL;

	newPerrito=ePerrito_newPerrito();

	if(idStr != NULL && nombre != NULL && pesoStr != NULL && edadStr != NULL && raza != NULL)
	{

		idAux=atoi(idStr);
		pesoAux=atof(pesoStr);
		edadAux=atoi(edadStr);

		ePerrito_setId(newPerrito, idAux);
		ePerrito_setNombre(newPerrito, nombre);
		ePerrito_setPeso(newPerrito, pesoAux);
		ePerrito_setEdad(newPerrito, edadAux);
		ePerrito_setRaza(newPerrito, raza);

	}
	else
	{
		ePerrito_deletePerrito(newPerrito);
	}

	return newPerrito;
}


int ePerrito_setId(ePerrito* this, int id)
{
	int seCargo=-1;

	if(this != NULL && id >= 0)
	{
		this->id=id;
		seCargo=0;
	}

	return seCargo;
}

int ePerrito_getId(ePerrito* this, int* id)
{
	int seCargo=-1;

	if(this != NULL && id != NULL)
	{
		*id=this->id;
		seCargo=0;
	}

	return seCargo;
}

int ePerrito_setNombre(ePerrito* this, char* nombre)
{
	int seCargo=-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		seCargo=0;
	}

	return seCargo;
}

int ePerrito_getNombre(ePerrito* this, char* nombre)
{
	int seCargo=-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		seCargo=0;
	}

	return seCargo;
}

int ePerrito_setPeso(ePerrito* this, float peso)
{
	int seCargo=-1;

	if(this != NULL && peso >= 0)
	{
		this->peso=peso;
		seCargo=0;
	}

	return seCargo;
}

int ePerrito_getPeso(ePerrito* this, float* peso)
{
	int seCargo=-1;

	if(this != NULL && peso != NULL)
	{
		*peso=this->peso;
		seCargo=0;
	}

	return seCargo;
}



int ePerrito_setEdad(ePerrito* this, int edad)
{
	int seCargo=-1;

	if(this != NULL && edad >= 0)
	{
		this->edad=edad;
		seCargo=0;
	}

	return seCargo;
}

int ePerrito_getEdad(ePerrito* this, int* edad)
{
	int seCargo=-1;

	if(this != NULL && edad != NULL)
	{
		*edad=this->edad;
		seCargo=0;
	}

	return seCargo;
}

int ePerrito_setRaza(ePerrito* this, char* raza)
{
	int seCargo=-1;

	if(this != NULL && raza != NULL)
	{
		strcpy(this->raza,raza);
		seCargo=0;
	}

	return seCargo;
}

int ePerrito_getRaza(ePerrito* this, char* raza)
{
	int seCargo=-1;

	if(this != NULL && raza != NULL)
	{
		strcpy(raza,this->raza);
		seCargo=0;
	}

	return seCargo;
}

int ePerrito_setCantidadRacion(ePerrito* this, float cantidadRacion)
{
	int seCargo=-1;

	if(this != NULL && cantidadRacion >= 0)
	{
		this->cantidadComidaRacion=cantidadRacion;
		seCargo=0;
	}

	return seCargo;
}

int ePerrito_getCantidadRacion(ePerrito* this, float* cantidadRacion)
{
	int seCargo=-1;

	if(this != NULL && cantidadRacion != NULL)
	{
		*cantidadRacion=this->cantidadComidaRacion;
		seCargo=0;
	}

	return seCargo;
}

void ePerrito_imprimirPerrito(ePerrito* this)
{
	int id;
	char nombre[50];
	float peso;
	int edad;
	char raza[50];

	if(this != NULL)
	{

		ePerrito_getId(this, &id);
		ePerrito_getNombre(this, nombre);
		ePerrito_getPeso(this, &peso);
		ePerrito_getEdad(this, &edad);
		ePerrito_getRaza(this, raza);

		printf("%-5d %-15s %-20.2f %-20d %-15s\n", id, nombre, peso, edad, raza);
	}
}


void ePerrito_imprimirPerritoRacion(ePerrito* this)
{
	int id;
	char nombre[50];
	float peso;
	int edad;
	char raza[50];
	float cantidadComidaRacion;

	if(this != NULL)
	{

		ePerrito_getId(this, &id);
		ePerrito_getNombre(this, nombre);
		ePerrito_getPeso(this, &peso);
		ePerrito_getEdad(this, &edad);
		ePerrito_getRaza(this, raza);
		ePerrito_getCantidadRacion(this, &cantidadComidaRacion);

		printf("%-5d %-15s %-20.2f %-20d %-15s %-20.2f\n", id, nombre, peso, edad, raza, cantidadComidaRacion);
	}
}

int ePerrito_sortByName(void* perritoI, void* perritoJ)
{
	int retorno;
	char nombreI[100];
	char nombreJ[100];

	ePerrito* pPerritoI;
	ePerrito* pPerritoJ;

	if(perritoI != NULL && perritoJ != NULL)
	{
		pPerritoI=(ePerrito*)perritoI;
		pPerritoJ=(ePerrito*)perritoJ;

		ePerrito_getNombre(pPerritoI, nombreI);
		ePerrito_getNombre(pPerritoJ, nombreJ);

		retorno=strcmp(nombreI,nombreJ);
		if(retorno < 0)
		{
			retorno=-1;
		}
		else
		{
			if(retorno> 0)
			{
				retorno=1;
			}
		}
	}

	return retorno;
}

void ePerrito_calculoComidaRacion(void* perrito)
{
	ePerrito* pPerrito;
	float peso;
	float totalComidaRacion;

	if(perrito != NULL)
	{
		pPerrito=(ePerrito*)perrito;

		ePerrito_getPeso(pPerrito, &peso);

		totalComidaRacion= peso*23;

		ePerrito_setCantidadRacion(pPerrito, totalComidaRacion);

	}
}


void ePerrito_deletePerrito(ePerrito* this)
{
	if(this != NULL)
	{
		free(this);
		this=NULL;
	}

}
