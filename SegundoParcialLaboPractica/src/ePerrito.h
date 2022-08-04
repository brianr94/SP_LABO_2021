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

}ePerrito;


#endif /* EPERRITO_H_ */
