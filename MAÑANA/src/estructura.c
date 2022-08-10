#include "estructura.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


estructura* e_newEstructura()
{
	estructura* nuevo;

	nuevo= (estructura*)malloc(sizeof(estructura));

	return nuevo;
}

estructura* e_newParametros(char* a, char* b, char* c, char* d, char* e)
{
	estructura* nueva=NULL;
	int idAux;
	int eAux;
	float cAux;
	float dAux;

	nueva=e_newEstructura();

	if(a != NULL && b != NULL && c != NULL && d != NULL && e != NULL)
	{

		//setters
		e_setId(nueva, idAux);


	}
	else
	{
		e_borrar(nueva);
	}

	return nueva;
}



/*
int e_setId(e* this,int id)
{
	int seCargo=-1;

	if(this != NULL && id >= 0)
	{
		this->id=id;
		seCargo=0;
	}

	return seCargo;

}

int e_getId(estructura* this,int* id)
{
	int seCargo=-1;

	if(this != NULL && id != NULL)
	{
		*id=this->id;
		seCargo=0;
	}

	return seCargo;
}


int e_setchar(e* this,char* palabra)
{
	int seCargo=-1;

	if(this != NULL && palabra != NULL)
	{
		strcpy(this->palabra,palabra);
		seCargo=0;
	}

	return seCargo;
}
int e_getchar(eServicios* this,char* pala)
{
	int seCargo=-1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(pala,this->pala);
		seCargo=0;
	}

	return seCargo;
}

int e_setfloat(e* this,float precioUnitario)
{
	int seCargo=-1;

	if(this != NULL && flot > 0)
	{
		this->precioUnitario=precioUnitario;
		seCargo=0;
	}

	return seCargo;
}
int e_getfloat(e* this,float* flot)
{
	int seCargo=-1;

	if(this != NULL && flot != NULL)
	{
		*flot=this->flot;
		seCargo=0;
	}

	return seCargo;
}

*/

/*
void e_imprimir(e* this)
{
	int id;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float total;


	if(this != NULL)
	{
		e_getId(this, &id);
		e_get(this, descripcion);
		e_get(this, &tipo);
		e_get(this, &precioUnitario);
		e_get(this, &cantidad);
		e_get(this, &total);


		printf("%-5d %-15s %-20d %-20.2f %-15d %-20.2f \n", id, de, t, p, ca, to);

	}
}
*/

void e_borrar(estructura* this)
{
	if(this != NULL)
	{
		free(this);
		this=NULL;
	}
}
