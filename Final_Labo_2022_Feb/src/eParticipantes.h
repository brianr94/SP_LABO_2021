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


#endif /* EPARTICIPANTES_H_ */
