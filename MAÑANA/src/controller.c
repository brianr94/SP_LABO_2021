#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>


//carga archivo sin validar el ingreso del archivo
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	int retorno=1;
	FILE* pFile;

	pFile= fopen(path,"r");

	if(path != NULL && pArrayList != NULL)
	{
		retorno=parser_estructuraFromText(pFile, pArrayList);
		printf("\nSe cargo el arhivo %s correctamente!!!\n",path);
	}

    return retorno;
}

//carga un arvhivo validando el ingreso del archivo
int controller_validateLoadFromText(char* path , LinkedList* pArrayList)
{

	int retorno=-1;
	char file[51];
	FILE* pFile;

	pedirCadena(file, "Ingrese el archivo a cargar(incluir el formato en el nombre .csv): ", "Error. Ingrese nuevamente el nombre del archivo: ", 51);

	if(strcmp(path,file) != 0)
	{
		printf("\nArchivo ingresado no existe!!!!. Cargue nuevamente el arhivo\n");
	}
	else
	{
		printf("\nArchivo encontrado.Cargando....!!!\n");

		pFile= fopen(path,"r");

		if(path != NULL && pArrayList != NULL)
		{
			retorno=parser_estrucFromText(pFile, pArrayList);
			printf("\nSe cargo el arhivo %s correctamente!!!\n",path);
		}

	}

    return retorno;
}



//Guarda el archivo ADAPTAR!!!!!!
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	int retorno=1;
	int i;
	int len;
	int idAux;
	char descripcion[50];
	float precioAux;
	int tipoAux;
	int cantidadAux;
	float totalAux;


	e* servicio;

	FILE* pFile;

	pFile=fopen(path,"w");

	if(path != NULL && pArrayList != NULL)
	{
		len=ll_len(pArrayList);
		if(pFile != NULL)
		{
			fprintf(pFile,"%s\n","id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio");//cambiar el encabezado segun el csv que nos dan
			for(i=0;i<len;i++)
			{
				servicio=ll_get(pArrayList, i);

				if(servicio != NULL)
				{
					e_getId(servicio, &idAux);


					fprintf(pFile,"%d,%s,%d,%.2f,%d,%.2f\n",idAux,de,ti,pre,can,to);
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

//listar la lista
int controller_Listar(LinkedList* pArrayList)
{
	int retorno=-1;
	int i;
	int len;
	e* servicio;

	if(pArrayList != NULL)
	{
		len=ll_len(pArrayList);//cambiar el print segun los datos a mostrar
		printf("\n%-5s %-15s %-20s %-20s %-15s %-20s\n","ID", "Descripcion", "Tipo", "Precio Unitario", "Cantidad","Total Servicios");
		for(i=0;i<len;i++)
		{
			servicio=ll_get(pArrayList, i);
			e_imprimir(servicio);
		}
		retorno=0;
	}

    return retorno;
}


//asigna valores a la lista sin retornar una lista. ASIGNA VALORES A LA LISTA ACTUAL!!!
int controller_asignarAlgo(LinkedList* pArrayList)
{
	int retorno=-1;

	if(pArrayList != NULL)
	{
		ll_map(pArrayList, criterioasignacion);
		retorno=0;
	}

	return retorno;
}


// Asigna valores a la lista y retorna una lista nueva a la original para poder guardarla en una nueva!!!. No modifica la actual!!
LinkedList* controller_asignarPromedio(LinkedList* pArrayList)
{
	LinkedList* listafiltrada;

	if(pArrayList != NULL)
	{
		listafiltrada=ll_map(pArrayList, criterioasignacion);
	}

	return listafiltrada;
}

//ordenar lista por un solo criterio
int controller_SortBy(LinkedList* pArrayList)
{
	int retorno=-1;


	if(pArrayList != NULL)
	{
		retorno = ll_sort(pArrayList, criterio,1);
	}

	return retorno;
}


//ordena una lista por doble criterio en este caso por categoria en ASC, y si son iguales por promedio ASC
int controller_participantesOrdenadoPorCategoria(LinkedList* pArrayList)
{
	int retorno=-1;

	if(pArrayList != NULL)
	{
		if(ll_sort(pArrayList, criterio1, 1) == 0 && ll_sort(pArrayList, criterio2, 1) == 0)
		{
			controller_listarParticipantes(pArrayList);//esto es opcional!!
			retorno=0;
		}
	}

	return retorno;
}

//controller para filtrar una lista y guardarla en la misma funcion
int controller_listFilterByTotal(LinkedList* pArrayList)
{
	int retorno=-1;
	LinkedList* listaFiltrada = NULL;

		if(pArrayList != NULL)
		{
			listaFiltrada=ll_filter(pArrayList, eServicio_buscarTotalMayor);


			if(listaFiltrada != NULL)
			{
				controller_saveAsText("listaFiltradaPorTotales.csv",listaFiltrada);
				printf("Lista filtrada por clase y guardada con exito.\n");
			}


		}

	return retorno;
}

// filtra en una lista pero por varios tipos que contenga la lista
int controller_filtrarPorCategoria(LinkedList* pArrayList)
{
	int retorno=-1;
	int opcion;
	LinkedList* listaFiltrada=NULL;
	int (*pFuncion)(void* elemento);
	char path[50];

	pFuncion=NULL;

	if(pArrayList != NULL)
	{

		pedirNumeroEnteroValidado(&opcion,
											"-------------------------------------\n"
											"1. Filtrar por categoria MX1\n"
											"2. Filtrar por categoria MX2\n"
											"3. Filtrar por categoria MX3\n"
											"4. Filtrar por categoria SUPER ATV\n"
											"-------------------------------------\n"
											"Ingrese una opcion: ",
											"-------------------------------------\n"
											"1. Filtrar por categoria MX1\n"
											"2. Filtrar por categoria MX2\n"
											"3. Filtrar por categoria MX3\n"
											"4. Filtrar por categoria SUPER ATV\n"
											"---------------------------------------\n"
											"Error.Ingrese opcion correcta: ", 1, 4);


		switch(opcion)
		{
			case 1:
				pFuncion=eParticipantes_filterByMX1;
				strcpy(path,"MX1.csv");
				retorno=0;
				break;
			case 2:
				pFuncion=eParticipantes_filterByMX2;
				strcpy(path,"MX2.csv");
				retorno=0;
				break;
			case 3:
				pFuncion=eParticipantes_filterByMX3;
				strcpy(path,"MX3.csv");
				retorno=0;
				break;
			case 4:
				pFuncion=criterio;
				strcpy(path,"SUPER_ATV.csv");
				retorno=0;
				break;
		}

		listaFiltrada= ll_filter(pArrayList, pFuncion);

		if(listaFiltrada != NULL)
		{
			controller_saveAsText(path, listaFiltrada);
		}

	}

	return retorno;
}

//en caso de tener que levantar una lista que se creo/filtro anteriormente para asignar algo en este caso descuento
int controller_TotalConDescuento(LinkedList* pArrayList, char* path)
{
	int retorno=-1;
	LinkedList* listaFiltrada;

	if(pArrayList != NULL)
	{

		if(controller_loadFromText(path, pArrayList) != -1)
		{
			listaFiltrada=ll_map(pArrayList, eServicio_totalConDescuento);
		}


		if(listaFiltrada != NULL)
		{
			controller_saveAsText("listaConDescuento.csv", pArrayList);
			retorno=0;
		}

	}

	return retorno;
}

