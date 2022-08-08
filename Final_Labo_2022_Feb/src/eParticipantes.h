/*
 * eParticipantes.h
 *
 *  Created on: 7 ago. 2022
 *      Author: brian
 */

#ifndef EPARTICIPANTES_H_
#define EPARTICIPANTES_H_

#define TAMSTR 21

typedef struct{

	int id_cuatri;
	char nombre[TAMSTR];
	char categoria[TAMSTR];
	int tiempo;
	int promedio;

}eParticipantes;

eParticipantes* newParticipantes();
eParticipantes* eParticipantes_newParametros(char* id_cuatri, char* nombre, char* categoria, char* tiempo, char* promedio);

int eParticipantes_getId(eParticipantes* this, int* id);
int eParticipantes_setId(eParticipantes* this, int id);

int eParticipantes_setNombre(eParticipantes* this, char* nombre);
int eParticipantes_getNombre(eParticipantes* this, char* nombre);

int eParticipantes_setCategoria(eParticipantes* this, char* categoria);
int eParticipantes_getCategoria(eParticipantes* this, char* categoria);

int eParticipantes_setTiempo(eParticipantes* this, int tiempo);
int eParticipantes_getTiempo(eParticipantes* this, int* tiempo);

int eParticipantes_setPromedio(eParticipantes* this, int promedio);
int eParticipantes_getPromedio(eParticipantes* this, int* promedio);

void eParticipantes_deleteParticipante(eParticipantes* this);
void eParticipantes_imprimirParticipante(eParticipantes* this);

#endif /* EPARTICIPANTES_H_ */
