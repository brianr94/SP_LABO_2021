/*
 ============================================================================
 Name        : final_labo_mañana.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(void) {
	setbuf(stdout,NULL);

	LinkedList* lista;
	int opcion;
	int flagCargado;
	int flagGuardado;

	flagCargado=0;
	flagGuardado=0;

	lista=ll_newLinkedList();

	do
	{
		pedirNumeroEnteroValidado(&opcion,
											"-------------------------\n"
											"1. cargar archivo\n"
											"2. b\n"
											"3. a\n"
											"4. c\n"
											"5. s\n"
											"6. q\n"
											"7. salir\n"
											"---------------------------\n"
											"Ingrese una opcion: ",
											"---------------------------\n"
											"1. cargar archivo\n"
											"2. b\n"
											"3. a\n"
											"4. c\n"
											"5. s\n"
											"6. q\n"
											"7. salir\n"
											"----------------------------\n"
											"Error. Ingrese una opcion correcta: ", 1, 7);

		switch(opcion)
		{
			case 1:
				if(flagCargado == 0)
				{
					if()//controller
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
					//controller
				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 3:
				if(flagCargado == 1)
				{
					//controller
				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 4:
				if(flagCargado == 1)
				{
					//controller
				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 5:
				if(flagCargado == 1)
				{

				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 6:
				if(flagCargado == 1)
				{
					if()//save
					{
						flagGuardado= 1;
					}
				}
				else
				{

				}
				break;
			case 7:
				if(flagGuardado == 1)
				{
					ll_deleteLinkedList(lista);
					printf("\nElegio salir del programa....\n")
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
