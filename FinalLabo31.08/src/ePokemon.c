#include <stdlib.h>
#include <stdlib.h>
#include "ePokemon.h"
#include "LinkedList.h"
#include "utn_inputs.h"
#include "utn_validaciones.h"


ePokemon* ePokemon_newPokemon()
{
	ePokemon* newPokemon;

	newPokemon=(ePokemon*)malloc(sizeof(ePokemon));

	return newPokemon;
}

ePokemon* ePokemon_newParametros(char* numeroStr, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, char* valorAtaqueStr, char* varioColorStr)
{
	ePokemon* newPokemon=NULL;
	int numeroAux;
	int valorAux;
	int varioColorAux;

	newPokemon=ePokemon_newPokemon();

	if(numeroStr != NULL && nombre != NULL && tipo != NULL && tamanio != NULL && ataqueCargado != NULL && valorAtaqueStr != NULL && varioColorStr != NULL)
	{

		numeroAux=atoi(numeroStr);
		valorAux=atoi(valorAtaqueStr);
		varioColorAux=atoi(varioColorStr);

		ePokemon_setNumero(newPokemon, numeroAux);
		ePokemon_setNombre(newPokemon, nombre);
		ePokemon_setTipo(newPokemon, tipo);
		ePokemon_setTamanio(newPokemon, tamanio);
		ePokemon_setAtaqueCargado(newPokemon, ataqueCargado);
		ePokemon_setValorAtaque(newPokemon, valorAux);
		ePokemon_setVarioColor(newPokemon, varioColorAux);


	}
	else
	{
		ePokemon_borrarPokemon(newPokemon);
	}

	return newPokemon;
}


int ePokemon_setNumero(ePokemon* this,int numero)
{
	int seCargo=-1;

	if(this != NULL && numero > 0)
	{
		this->numero=numero;
		seCargo=0;
	}

	return seCargo;

}

int ePokemon_getNumero(ePokemon* this,int* numero)
{
	int seCargo=-1;

	if(this != NULL && numero != NULL)
	{
		*numero=this->numero;
		seCargo=0;
	}

	return seCargo;
}

int ePokemon_setNombre(ePokemon* this,char* nombre)
{
	int seCargo=-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		seCargo=0;
	}

	return seCargo;
}
int ePokemon_getNombre(ePokemon* this,char* nombre)
{
	int seCargo=-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		seCargo=0;
	}

	return seCargo;
}

int ePokemon_setTipo(ePokemon* this,char* tipo)
{
	int seCargo=-1;

	if(this != NULL && tipo != NULL)
	{
		strcpy(this->tipo,tipo);
		seCargo=0;
	}

	return seCargo;
}
int ePokemon_getTipo(ePokemon* this,char* tipo)
{
	int seCargo=-1;

	if(this != NULL && tipo != NULL)
	{
		strcpy(tipo,this->tipo);
		seCargo=0;
	}

	return seCargo;
}

int ePokemon_setTamanio(ePokemon* this,char* tamanio)
{
	int seCargo=-1;

	if(this != NULL && tamanio != NULL)
	{
		strcpy(this->tamanio,tamanio);
		seCargo=0;
	}

	return seCargo;
}
int ePokemon_getTamanio(ePokemon* this,char* tamanio)
{
	int seCargo=-1;

	if(this != NULL && tamanio != NULL)
	{
		strcpy(tamanio,this->tamanio);
		seCargo=0;
	}

	return seCargo;
}

int ePokemon_setAtaqueCargado(ePokemon* this,char* ataque)
{
	int seCargo=-1;

	if(this != NULL && ataque != NULL)
	{
		strcpy(this->ataqueCargado,ataque);
		seCargo=0;
	}

	return seCargo;
}
int ePokemon_getAtaqueCargado(ePokemon* this,char* ataque)
{
	int seCargo=-1;

	if(this != NULL && ataque != NULL)
	{
		strcpy(ataque,this->ataqueCargado);
		seCargo=0;
	}

	return seCargo;
}

int ePokemon_setValorAtaque(ePokemon* this,int valor)
{
	int seCargo=-1;

	if(this != NULL && valor >= 0)
	{
		this->valorAtaque=valor;
		seCargo=0;
	}

	return seCargo;

}

int ePokemon_getValorAtaque(ePokemon* this,int* valor)
{
	int seCargo=-1;

	if(this != NULL && valor != NULL)
	{
		*valor=this->valorAtaque;
		seCargo=0;
	}

	return seCargo;
}


int ePokemon_setVarioColor(ePokemon* this,int varioColor)
{
	int seCargo=-1;

	if(this != NULL && varioColor >= 0)
	{
		this->esVarioColor=varioColor;
		seCargo=0;
	}

	return seCargo;

}

int ePokemon_getVarioColor(ePokemon* this,int* varioColor)
{
	int seCargo=-1;

	if(this != NULL && varioColor != NULL)
	{
		*varioColor=this->esVarioColor;
		seCargo=0;
	}

	return seCargo;
}

void ePokemon_imprimirPokemon(ePokemon* this)
{
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int varioColor;


	if(this != NULL)
	{
		ePokemon_getNumero(this, &numero);
		ePokemon_getNombre(this, nombre);
		ePokemon_getTipo(this, tipo);
		ePokemon_getTamanio(this, tamanio);
		ePokemon_getAtaqueCargado(this, ataqueCargado);
		ePokemon_getValorAtaque(this, &valorAtaque);
		ePokemon_getVarioColor(this, &varioColor);


		printf("%-5d %-15s %-20s %-20s %-15s %-20d %-20d\n", numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, varioColor);

	}
}

ePokemon* ePokemon_buscarPokemonNumero(LinkedList* pArrayPokemon, int numero ,int* index)
{
	int length;
	int numeroAux;
	int i;
	ePokemon* pokemon=NULL;

	*index=-1;
	if(pArrayPokemon != NULL)
	{
		length=ll_len(pArrayPokemon);
		if(length>0)
		{
			for(i=0;i<length;i++)
			{
				pokemon=ll_get(pArrayPokemon, i);
				ePokemon_getNumero(pokemon, &numeroAux);

				if(numero==numeroAux)
				{
					*index = i;
					break;
				}
			}
		}
	}

	return pokemon;
}

/*
//se ingresa un elemento de la lista y modifica el valor especificado
int ePokemon_modificarValorAtaque(ePokemon* this)
{
	int retorno=-1;

	//ePokemon* pokemon; lo sacamos porque no fue necesario usar una estructura para modificar el dato
	//lo modificamos directo sin usar un intermediario que seria la estructura
	char AtaqueCargado[50];


	if(this!= NULL)
	{
		printf("\nPokemon a modificar:\n\n%-5s %-15s %-20s %-20s %-15s %-20s %-20s\n\n","Numero", "Nombre", "Tipo", "Tamaño", "ataqueCargado","valorAtaque", "varioColor");
		ePokemon_imprimirPokemon(this);

		pedirCadenaCompuesta("Ingrese el ataque Cargado: ", "Error. Ingrese el ataque cargado nuevamente(max 50 Caracteres)", AtaqueCargado, 50, 10);

		if(verificarConfirmacion("Ingrese 's' para confirmar la modificacion: ") != -1)
		{
			ePokemon_setAtaqueCargado(this, AtaqueCargado);
			retorno=0;
			printf("\nSe realizo correctamente la modificacion del valor de ataque!!\n");
		}
		else
		{
			printf("\nSe cancelo la modificacion del valor de ataque!!!\n");
		}

	}

	return retorno;
}
*/

void ePokemon_borrarPokemon(ePokemon* this)
{
	if(this != NULL)
	{
		free(this);
		this=NULL;
	}
}
