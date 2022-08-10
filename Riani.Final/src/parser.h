/*
 * parser.h
 *
 *  Created on: 10 ago. 2022
 *      Author: brian
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int parser_pokemonFromText(FILE* pFile , LinkedList* pArrayListPokemon);

#endif /* PARSER_H_ */
