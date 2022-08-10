#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "parser.h"
#include "ePokemon.h"
#include "informes.h"
#include "utn_inputs.h"
#include "controller.h"

int riani_controller_validateLoadFromText(char* path , LinkedList* pArrayListPokemon)
{

	int retorno=-1;
	char file[51];
	FILE* pFile;

	printf("Ingrese el archivo a cargar(incluir el formato en el nombre .csv): ");
	fflush(stdin);
	scanf("%s", file);


	if(strcmp(path,file) != 0)
	{
		printf("\nArchivo ingresado no existe!!!!. Cargue nuevamente el arhivo\n");
	}
	else
	{
		printf("\nArchivo encontrado.Cargando....!!!\n");

		pFile= fopen(path,"r");

		if(path != NULL && pArrayListPokemon != NULL)
		{
			retorno=parser_pokemonFromText(pFile, pArrayListPokemon);
			printf("\nSe cargo el arhivo %s correctamente!!!\n",path);
		}

	}

    return retorno;
}

int riani_controller_listarPokemones(LinkedList* pArrayListPokemon)
{
	int retorno=-1;
	int i;
	int len;
	ePokemon* newPokemon;

	if(pArrayListPokemon != NULL)
	{
		len=ll_len(pArrayListPokemon);
		printf("\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n","Numero", "Nombre", "Tipo", "Tama�o", "AtaqueCargado","ValorAtaque", "VarioColor");
		for(i=0;i<len;i++)
		{
			newPokemon=ll_get(pArrayListPokemon, i);
			ePokemon_imprimirPokemon(newPokemon);
		}
		retorno=0;
	}

    return retorno;
}

int riani_controller_filtrarPorFuego(LinkedList* pArrayListPokemon)
{
	int retorno=-1;
	LinkedList* listaFiltrada = NULL;

		if(pArrayListPokemon != NULL)
		{
			listaFiltrada=ll_filter(pArrayListPokemon, ePokemon_filtrarPorFuego);


			if(listaFiltrada != NULL)
			{
				riani_controller_saveAsText("pokemonFuego.csv",listaFiltrada);
				retorno=0;
				printf("\nLista filtrada y guardada con exito.\n");
			}


		}

	return retorno;
}

int riani_controller_filtrarPorTamanioYVeneno(LinkedList* pArrayListPokemon)
{
	int retorno=-1;
	LinkedList* listaFiltrada = NULL;

		if(pArrayListPokemon != NULL)
		{
			listaFiltrada=ll_filter(pArrayListPokemon, ePokemon_filtrarPorTamanioYVeneno);


			if(listaFiltrada != NULL)
			{
				riani_controller_listarPokemones(listaFiltrada);
				retorno=0;
			}


		}

	return retorno;
}

int riani_controller_saveAsText(char* path , LinkedList* pArrayListPokemon)
{
	int retorno=1;
	int i;
	int len;
	int numeroAux;
	char nombre[50];
	char tipoAux[50];
	char tamanioAux[50];
	char ataqueCargadoAux[50];
	int valorAtaqueAux;
	int varioColorAux;


	ePokemon* newPokemon;

	FILE* pFile;

	pFile=fopen(path,"w");

	if(path != NULL && pArrayListPokemon != NULL)
	{
		len=ll_len(pArrayListPokemon);
		if(pFile != NULL)
		{
			fprintf(pFile,"%s\n","Numero,Nombre,Tipo,Tama�o,ataqueCargado,valorAtaque,VarioColor");
			for(i=0;i<len;i++)
			{
				newPokemon=ll_get(pArrayListPokemon, i);

				if(newPokemon != NULL)
				{
					ePokemon_getNumero(newPokemon, &numeroAux);
					ePokemon_getNombre(newPokemon, nombre);
					ePokemon_getTipo(newPokemon, tipoAux);
					ePokemon_getTamanio(newPokemon, tamanioAux);
					ePokemon_getAtaqueCargado(newPokemon, ataqueCargadoAux);
					ePokemon_getValorAtaque(newPokemon, &valorAtaqueAux);
					ePokemon_getVarioColor(newPokemon, &varioColorAux);


					fprintf(pFile,"%d,%s,%s,%s,%s,%d,%d\n",numeroAux,nombre,tipoAux,tamanioAux,ataqueCargadoAux,valorAtaqueAux,varioColorAux);
				}
			}

			fclose(pFile);
			printf("Archivo '%s' guardado correctamente. \n",path);
		}
		else
		{
			printf("\nError.Archivo no creado!!!\n");
		}

		retorno=0;
	}
    return retorno;
}

int riani_controller_modificarValorAtaque(LinkedList* pArrayListPokemon)
{
	int retorno=1;
	int index;
	int numeroPokemon;
	ePokemon* pokemon=NULL;

	if(pArrayListPokemon != NULL)
	{
		riani_controller_listarPokemones(pArrayListPokemon);

		pedirNumeroValidado(&numeroPokemon, "Ingrese el numero del pokemon a modificar: ", "Error. Ingrese correctamente el numero: ");

		pokemon= ePokemon_buscarPokemonNumero(pArrayListPokemon, numeroPokemon, &index);

		if(pokemon != NULL && index != -1)
		{
			if(ePokemon_modificarValorAtaque(pokemon)==0)
			{
				ll_set(pArrayListPokemon, index, pokemon);
				retorno=0;
			}

		}
		else
		{
			printf("\nError. El Numero del pokemon ingresado no existe!!!\n");
		}

	}


    return retorno;
}

LinkedList* riani_controller_asignarNuevoValorAtaque(LinkedList* pArrayListPokemon)
{
	//int retorno=-1;
	LinkedList* listaMapeada;

	if(pArrayListPokemon != NULL)
	{
		listaMapeada=ll_map(pArrayListPokemon, ePokemon_mapeoAtaqueCargado);
		//retorno=0;
	}

	return listaMapeada;
}

int riani_controller_batallaPokemon(LinkedList* pArrayListPokemon)
{
	int retorno=-1;
	int pokemonFuego;
	int pokemonWater;
	int equipoCompleto;

	if(pArrayListPokemon != NULL)
	{

		pokemonFuego=ll_count(pArrayListPokemon, ePokemon_cantidadPokemonFuego);
		pokemonWater=ll_count(pArrayListPokemon, ePokemon_cantidadPokemonWater);

		equipoCompleto= pokemonFuego + pokemonWater;
		printf("%d\n", pokemonFuego);
		printf("%d\n", pokemonWater);
		retorno=0;
		if(equipoCompleto > 3)
		{
			printf("\nFelicidades ganamos la batalla Pokemon!!!!\n");
		}
		else
		{
			printf("\nMala Suerte no ganamos la batalla Pokemon!!!!\n");
		}

	}

	return retorno;
}
