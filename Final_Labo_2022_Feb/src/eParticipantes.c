
#include <stdlib.h>
#include <stdio.h>
#include "eParticipantes.h"


eParticipantes* newParticipantes()
{
	eParticipantes* participante=NULL;

	participante=(eParticipantes*)malloc(sizeof(eParticipantes));

	return participante;
}


eParticipantes* eParticipantes_newParametros(char* id_cuatri, char* nombre, char* categoria, char* tiempo, char* promedio)
{

	eParticipantes* participante=NULL;
	int idAux;
	int tiempoAux;
	int promedioAux;

	participante=newParticipantes();

	if(id_cuatri != NULL && nombre != NULL && categoria != NULL && tiempo != NULL && promedio != NULL)
	{

		idAux=atoi(id_cuatri);
		tiempoAux=atoi(tiempo);
		promedioAux=atoi(promedio);

		eParticipantes_setId(participante, idAux);
		eParticipantes_setNombre(participante, nombre);
		eParticipantes_setCategoria(participante, categoria);
		eParticipantes_setTiempo(participante, tiempoAux);
		eParticipantes_setPromedio(participante, promedioAux);

	}
	else
	{
		eParticipantes_deleteParticipante(participante);
	}

	return participante;
}

int eParticipantes_setId(eParticipantes* this, int id)
{
	int seCargo=-1;

	if(this != NULL && id >= 0)
	{
		this->id_cuatri=id;
		seCargo=0;
	}

	return seCargo;
}

int eParticipantes_getId(eParticipantes* this, int* id)
{
	int seCargo=-1;

	if(this != NULL && id != NULL)
	{
		*id=this->id_cuatri;
		seCargo=0;
	}

	return seCargo;
}

int eParticipantes_setNombre(eParticipantes* this, char* nombre)
{
	int seCargo=-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		seCargo=0;
	}

	return seCargo;
}

int eParticipantes_getNombre(eParticipantes* this, char* categoria)
{
	int seCargo=-1;

	if(this != NULL && categoria != NULL)
	{
		strcpy(categoria,this->categoria);
		seCargo=0;
	}

	return seCargo;
}

int eParticipantes_setCategoria(eParticipantes* this, char* categoria)
{
	int seCargo=-1;

	if(this != NULL && categoria != NULL)
	{
		strcpy(this->categoria,categoria);
		seCargo=0;
	}

	return seCargo;
}

int eParticipantes_getCategoria(eParticipantes* this, char* categoria)
{
	int seCargo=-1;

	if(this != NULL && categoria != NULL)
	{
		strcpy(categoria,this->categoria);
		seCargo=0;
	}

	return seCargo;
}

int eParticipantes_setTiempo(eParticipantes* this, int tiempo)
{
	int seCargo=-1;

	if(this != NULL && tiempo >= 0)
	{
		this->tiempo=tiempo;
		seCargo=0;
	}

	return seCargo;
}

int eParticipantes_getTiempo(eParticipantes* this, int* tiempo)
{
	int seCargo=-1;

	if(this != NULL && tiempo != NULL)
	{
		*tiempo=this->tiempo;
		seCargo=0;
	}

	return seCargo;
}

int eParticipantes_setPromedio(eParticipantes* this, int promedio)
{
	int seCargo=-1;

	if(this != NULL && promedio >= 0)
	{
		this->promedio=promedio;
		seCargo=0;
	}

	return seCargo;
}

int eParticipantes_getPromedio(eParticipantes* this, int* promedio)
{
	int seCargo=-1;

	if(this != NULL && promedio != NULL)
	{
		*promedio=this->promedio;
		seCargo=0;
	}

	return seCargo;
}

void eParticipantes_deleteParticipante(eParticipantes* this)
{

	if(this != NULL)
	{
		free(this);
		this=NULL;
	}

}

void eParticipantes_imprimirParticipante(eParticipantes* this)
{
	int id;
	char nombre[50];
	char categoria[50];
	int tiempo;
	int promedio;

	if(this != NULL)
	{

		eParticipantes_getId(this, &id);
		eParticipantes_getNombre(this, nombre);
		eParticipantes_getCategoria(this, categoria);
		eParticipantes_getTiempo(this, &tiempo);
		eParticipantes_getPromedio(this, &promedio);

		printf("%-5d %-15s %-20s %-20d %-15d\n", id, nombre, categoria, tiempo, promedio);
	}
}
