/*
 ============================================================================
 Name        : finalLabo_2022_feb.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eParticipantes.h"
#include "controller.h"
#include "utn_inputs.h"
#include "utn_validaciones.h"

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int flagCargado;
	int flagGuardado;
	int flagPromedio;
	int flagOpcion5;

	LinkedList* listaParticipantes;
	LinkedList* listaFiltrada;

	flagOpcion5=0;
	flagCargado=0;
	flagGuardado=0;
	flagPromedio=0;

	listaParticipantes=ll_newLinkedList();
	listaFiltrada=ll_newLinkedList();

	do
	{
		pedirNumeroEnteroValidado(&opcion,
											"--------------------------\n"
											"1. cargar archivo\n"
											"2. listar participantes\n"
											"3. asignar promedios\n"
											"4. filtrar por tipo\n"
											"5. mostrar posiciones\n"
											"6. guardar posiciones\n"
											"7. salir\n"
											"----------------------------\n"
											"Ingrese una opcion: ",
											"-----------------------------\n"
											"1. cargar archivo\n"
											"2. listar participantes\n"
											"3. asignar promedios\n"
											"4. filtrar por tipo\n"
											"5. mostrar posiciones\n"
											"6. guardar posiciones\n"
											"7. salir\n"
											"-------------------------------\n"
											"Error. Ingrese una opcion correcta: ", 1, 7);

		switch(opcion)
		{
			case 1:
				if(flagCargado == 0)
				{
					if(controller_validateLoadFromText("enduro.csv", listaParticipantes) != -1)
					{
						flagCargado=1;
					}
				}
				else
				{
					printf("\nEl archivo ya se encuentra cargado!!!\n");
				}

				break;
			case 2:
				if(flagCargado == 1)
				{
					controller_listarParticipantes(listaParticipantes);
				}
				else
				{
					printf("\nPrimero debe Cargar el archivo (opcion 1)!!!!\n");
				}
				break;
			case 3:
				if(flagCargado == 1)
				{
					controller_asignarPromedio(listaParticipantes);
					printf("\n Los promedios han sido aignados correctamente!!!\n");
					flagPromedio=1;
				}
				else
				{
					printf("\nPrimero debe Cargar el archivo (opcion 1)!!!!\n");
				}
				break;
			case 4:
				if(flagCargado == 1)
				{
					controller_filtrarPorCategoria(listaFiltrada);
				}
				else
				{
					printf("\nPrimero debe Cargar el archivo (opcion 1)!!!!\n");
				}
				break;
			case 5:
				if(flagCargado == 1 && flagPromedio == 1)
				{
					controller_participantesOrdenadoPorCategoria(listaParticipantes);
					flagOpcion5=1;
				}
				else
				{
					printf("\nPrimero debe Cargar el archivo (opcion 1)!!!!\n");
				}
				break;
			case 6:
				if(flagCargado == 1 && flagOpcion5 == 1)
				{
					controller_saveAsText("listaNueva.csv", listaParticipantes);
					flagGuardado=1;
				}
				else
				{
					printf("\nPrimero debe Cargar el archivo (opcion 1)!!!!\n");
				}
				break;
			case 7:
				if(flagGuardado == 1)
				{
					printf("\nElegio salir del programa.......\n");
				}
				else
				{
					printf("\nPrimero debe guardar el archivo (opcion 6)!!!!\n");
					opcion=0;
				}
				break;
		}

		if(opcion != 7)
		{
			system("pause");
		}
	}while(opcion != 7);


	return EXIT_SUCCESS;
}
