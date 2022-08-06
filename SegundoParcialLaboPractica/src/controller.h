/*
 * controller.h
 *
 *  Created on: 4 ago. 2022
 *      Author: brian
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_ordenarPerroPorNombre(LinkedList* pArrayListPerrito);
int controller_filterByGalgo(LinkedList* pArrayListPerrito);
int controller_asignacionTotalComidaRacion(LinkedList* pArrayListPerrito);
int controller_listarPerritosRacionComida(LinkedList* pArrayListPerrito);
int controller_listarPerritos(LinkedList* pArrayListPerrito);
int controller_saveAsText(LinkedList* pArrayListPerrito, char* path);
int controller_cargaDeArhivoTexto(char* path , LinkedList* pArrayListPerrito);

#endif /* CONTROLLER_H_ */
