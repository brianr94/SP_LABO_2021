/*
 * informes.h
 *
 *  Created on: 7 ago. 2022
 *      Author: brian
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int eParticipantes_filterByMX1(void* eParticipante);
int eParticipantes_filterByMX2(void* eParticipante);
int eParticipantes_filterByMX3(void* eParticipante);
int eParticipantes_filterBySuperATV(void* eParticipante);
void eParticipantes_asignarPromedio(void* eParticipante);
int eParticipantes_SortByCategoryAndAverage(void* participante1, void* participante2);


#endif /* INFORMES_H_ */
