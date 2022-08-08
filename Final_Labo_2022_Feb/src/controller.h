/*
 * controller.h
 *
 *  Created on: 7 ago. 2022
 *      Author: brian
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

int controller_validateLoadFromText(char* path , LinkedList* pArrayListParticipantes);
int controller_saveAsText(char* path , LinkedList* pArrayListParticipantes);
int controller_listarParticipantes(LinkedList* pArrayListParticipantes);
int controller_asignarPromedio(LinkedList* pArrayListParticipantes);
int controller_filtrarPorCategoria(LinkedList* pArrayListParticipantes);
int controller_participantesOrdenadoPorCategoria(LinkedList* pArrayListParticipantes);

#endif /* CONTROLLER_H_ */
