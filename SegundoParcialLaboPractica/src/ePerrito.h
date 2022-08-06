/*
 * ePerrito.h
 *
 *  Created on: 3 ago. 2022
 *      Author: brian
 */

#ifndef EPERRITO_H_
#define EPERRITO_H_

#define TAMSTR 21

typedef struct
{
	int id;
	char nombre[TAMSTR];
	float peso;
	int edad;
	char raza[TAMSTR];
	float cantidadComidaRacion;

}ePerrito;

ePerrito* ePerrito_newPerrito();
ePerrito* ePerrito_newParametros(char* idStr, char* nombre, char* pesoStr, char* edadStr, char* raza);
int ePerrito_setId(ePerrito* this, int id);
int ePerrito_getId(ePerrito* this, int* id);
int ePerrito_setNombre(ePerrito* this, char* nombre);
int ePerrito_getNombre(ePerrito* this, char* nombre);
int ePerrito_setPeso(ePerrito* this, float peso);
int ePerrito_getPeso(ePerrito* this, float* peso);
int ePerrito_setEdad(ePerrito* this, int edad);
int ePerrito_getEdad(ePerrito* this, int* edad);
int ePerrito_setRaza(ePerrito* this, char* raza);
int ePerrito_getRaza(ePerrito* this, char* raza);
int ePerrito_setCantidadRacion(ePerrito* this, float cantidadRacion);
int ePerrito_getCantidadRacion(ePerrito* this, float* cantidadRacion);
void ePerrito_imprimirPerrito(ePerrito* this);
void ePerrito_imprimirPerritoRacion(ePerrito* this);
int ePerrito_sortByName(void* perritoI, void* perritoJ);
void ePerrito_calculoComidaRacion(void* perrito);
int ePerrito_filtrarGalgos(void* perritos);
void ePerrito_deletePerrito(ePerrito* this);




#endif /* EPERRITO_H_ */
