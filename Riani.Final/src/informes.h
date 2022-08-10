/*
 * informes.h
 *
 *  Created on: 10 ago. 2022
 *      Author: brian
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int ePokemon_filtrarPorFuego(void* pokemon);
int ePokemon_filtrarPorTamanioYVeneno(void* pokemon);
void ePokemon_mapeoAtaqueCargado(void* pokemon);

int ePokemon_cantidadPokemonFuego(ePokemon* pokemon);
int ePokemon_cantidadPokemonWater(ePokemon* pokemon);
#endif /* INFORMES_H_ */
