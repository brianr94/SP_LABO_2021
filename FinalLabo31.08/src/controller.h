/*
 * controller.h
 *
 *  Created on: 10 ago. 2022
 *      Author: brian
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"

int riani_controller_validateLoadFromText(char* path , LinkedList* pArrayListPokemon);
int riani_controller_listarPokemones(LinkedList* pArrayListPokemon);
int riani_controller_filtrarPorAguaVarioColor(LinkedList* pArrayListPokemon);
int riani_controller_eliminarPokemon(LinkedList* pArrayListPokemon);
LinkedList* riani_controller_asignarNuevoValorAtaque(LinkedList* pArrayListPokemon);
int riani_controller_saveAsText(char* path , LinkedList* pArrayListPokemon);
int riani_controller_batallaPokemon(LinkedList* pArrayListPokemon);
#endif /* CONTROLLER_H_ */
