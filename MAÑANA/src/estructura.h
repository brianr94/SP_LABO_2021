/*
 * estructura.h
 *
 *  Created on: 9 ago. 2022
 *      Author: Usuario
 */

#ifndef ESTRUCTURA_H_
#define ESTRUCTURA_H_

typedef struct
{
	int num;
	char palabra[50];
	float flot;

}estructura;

estructura* e_newEstructura();
estructura* e_newParametros(char* a, char* b, char* c, char* d, char* e);

#endif /* ESTRUCTURA_H_ */
