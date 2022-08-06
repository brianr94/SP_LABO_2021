/*
 ============================================================================
 Name        : Labo2doParcial2021.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"
#include "ePerrito.h"
#include "utn_inputs.h"
#include "utn_validaciones.h"
#include <ctype.h>
#include <string.h>

int main(void) {
	setbuf(stdout,NULL);


	int opcion;
	int textoCargado;
	int flagRacionComida;
	int flagListaFiltrada;
	int flagGuardado;

	LinkedList* perritos;
	LinkedList* listaFiltrada;

	flagGuardado=0;
	textoCargado=0;
	flagRacionComida=0;
	flagListaFiltrada=0;

	perritos=ll_newLinkedList();
	listaFiltrada=ll_newLinkedList();



	do
	{
		pedirNumeroEnteroValidado(&opcion, "----------------------------------\n"
											"1.Cargar Archivos de Perritos\n"
											"2. Mostrar perritos por nombre Ascendente\n"
											"3. Calcular cantidad comida racionada\n"
											"4. mostrar perritos con comidas raciondas\n"
											"5. filtrar perritos galgos flacos\n"
											"6. Guardar Arhivo\n"
											"7. Salir\n"
											"----------------------------------\n"
											"Ingrese una opcion: ",
											"----------------------------------\n"
											"1.Cargar Archivos de Perritos\n"
											"2. Mostrar perritos por nombre Ascendente\n"
											"3. Calcular cantidad comida racionada\n"
											"4. mostrar perritos con comidas raciondas\n"
											"5. filtrar perritos galgos flacos\n"
											"6. Guardar archivo\n"
											"7. Salir\n"
											"-------------------------------------\n"
											"Error. Ingrese opcion correcta: ", 1, 7);



		switch(opcion)
		{

			case 1:
				if(controller_cargaDeArhivoTexto("perritos.csv", perritos) != -1)
				{
					textoCargado=1;
				}
				break;
			case 2:

				if(textoCargado==1)
				{
					controller_ordenarPerroPorNombre(perritos);
					controller_listarPerritos(perritos);
				}
				else
				{
					printf("\nPrimero de debe cargar el Archivo con la opcion 1!!!\n");
				}
				break;

			case 3:
				if(textoCargado==1)
				{
					controller_listarPerritosRacionComida(perritos);
					flagRacionComida=1;
				}
				else
				{
					printf("\nPrimero de debe cargar el Archivo con la opcion 1!!!\n");
				}
				break;
			case 4:
				if(textoCargado== 1 && flagRacionComida==1)
				{
					controller_listarPerritosRacionComida(perritos);
				}
				else
				{
					printf("\nPrimero de debe cargar el Archivo(opcion 1) o asignar la cantidad de racion(opcion 3)!!!\n");
				}

				break;

			case 5:
				if(textoCargado== 1 && flagRacionComida==1)
				{
					printf("\n\nFiltrado correctamente!!!!\n\n");
					if(controller_filterByGalgo(listaFiltrada) != -1)
					{
						controller_listarPerritosRacionComida(listaFiltrada);
						flagListaFiltrada=1;
					}
				}
				else
				{
					printf("\nPrimero de debe cargar el Archivo(opcion 1) o asignar la cantidad de racion(opcion 3)!!!\n");
				}
				break;

			case 6:
				if(textoCargado==1 && flagListaFiltrada==1)
				{
					controller_saveAsText(listaFiltrada, "galgosFlaquits.csv");
					flagGuardado=1;
				}
				else
				{
					printf("\nPrimero de debe cargar el Archivo(opcion 1) y debe filtrar la lista(opcion 5)!!!\n");
				}

				break;

			case 7:
				if(flagGuardado==1)
				{
					ll_deleteLinkedList(perritos);
					ll_deleteLinkedList(listaFiltrada);
					printf("\nEligio salir del programa....\n");
				}
				else
				{
					printf("\nPrimero debe guardar el archivo (opcion 6)!!!\n");
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
