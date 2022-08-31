/*
 ============================================================================
 Name        : Final.LABO1.Riani.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "ePokemon.h"
#include "utn_inputs.h"

int main(void) {
	setbuf(stdout,NULL);

	LinkedList* listaPokemon;
	LinkedList* listaMapeada;
	int opcion;
	int flagCargado;
	int flagOpcion5;

	flagCargado=0;
	flagOpcion5=0;

	listaMapeada=ll_newLinkedList();
	listaPokemon=ll_newLinkedList();

	do
	{
		pedirNumeroEnteroValidado(&opcion,
											"-------------------------\n"
											"1. Cargar archivo pokemones\n"
											"2. Eliminar pokemon\n"
											"3. Imprimir pokemones\n"
											"4. Filtrar de tipo Agua variocolor\n"
											"5. Mapear ataque cargado\n"
											"6. Batalla pokemon\n"
											"7. \n"
											"8. \n"
											"9. \n"
											"10. Salir\n"
											"---------------------------\n"
											"Ingrese una opcion: ",
											"---------------------------\n"
											"1. Cargar archivo pokemones\n"
											"2. Eliminar pokemon\n"
											"3. Imprimir pokemones\n"
											"4. Filtrar de tipo Agua variocolor\n"
											"5. Mapear ataque cargado\n"
											"6. Batalla pokemon\n"
											"7. \n"
											"8. \n"
											"9. \n"
											"10. Salir\n"
											"----------------------------\n"
											"Error. Ingrese una opcion correcta: ", 1, 10);

		switch(opcion)
		{
			case 1:
				if(flagCargado == 0)
				{

					if(riani_controller_validateLoadFromText("Data_Pokemones.csv", listaPokemon) != -1)
					{
						flagCargado=1;
					}

				}
				else
				{
					printf("\nEl arhivo ya fue cargado!!!\n");
				}

				break;
			case 2:
				if(flagCargado == 1)
				{
					riani_controller_eliminarPokemon(listaPokemon);
				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 3:
				if(flagCargado == 1)
				{
					riani_controller_listarPokemones(listaPokemon);
				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 4:
				if(flagCargado == 1)
				{
					riani_controller_filtrarPorAguaVarioColor(listaPokemon);
				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 5:
				if(flagCargado == 1)
				{
					if(flagOpcion5 == 0)
					{
						printf("\nNuevos valores aignados!!!\n");
						listaMapeada=riani_controller_asignarNuevoValorAtaque(listaPokemon);
						if(listaMapeada != NULL)
						{
							flagOpcion5=1;
							riani_controller_listarPokemones(listaMapeada);
						}
					}
					else
					{
						printf("\nLos valores ya fueron asignados!!!!\n");
					}

				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1) !!!\n");
				}
				break;
			case 6:
				if(flagCargado == 1)
				{
					if(flagOpcion5 == 1)
					{
						printf("\nIniciando Batalla Pokemon!!!\n");
						riani_controller_batallaPokemon(listaMapeada);
					}
					else
					{
						printf("\nDebe Asignar nuevos valores de ataque(opcion 5), Antes de iniciar la Batalla Pokemon!!!!\n");
					}

				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 7:
				if(flagCargado == 1 )
				{

				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 8:

				break;
			case 9:

				break;
			case 10:
				ll_deleteLinkedList(listaPokemon);
				printf("\nElegio salir del programa....\n");
				break;
		}

		if(opcion != 10)
		{
			system("pause");
		}

	}while(opcion != 10);

    return EXIT_SUCCESS;
}

