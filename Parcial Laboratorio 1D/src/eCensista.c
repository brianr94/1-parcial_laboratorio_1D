/*
 * eCencista.c
 *
 *  Created on: 20 may. 2022
 *      Author: brian
 */

#include "eCensista.h"

#include "utn_inputs.h"

int inicialiciarCensistas(eCensista lista[], int tamCensistas)
{
	int i;
	int retorno=-1;

	if(lista != NULL && tamCensistas>0)
	{
		for(i=0;i<tamCensistas;i++)
		{
			lista[i].isEmpty= VACIO;
			retorno=0;
		}
	}

	return retorno;
}



int buscarCensistaPorLegajo(eCensista lista[], int tamCensistas, int legajo)
{
	int i;
	int retorno=-1;

	if(lista != NULL && tamCensistas>0)
	{
		for(i=0;i<tamCensistas;i++)
		{
			if(lista[i].isEmpty==LLENO && lista[i].legajoCensista==legajo)
			{
				retorno=i;
				break;

			}
		}
	}

	return retorno;
}

int buscarEspacioLibreArrayCensista(eCensista lista[], int tamCensistas, int* index)
{
	int i;
	int retorno=-1;

	if(lista != NULL && tamCensistas>0)
	{
		for(i=0; i<tamCensistas;i++)
		{
			if(lista[i].isEmpty==VACIO)
			{
				*index=i;
				break;
			}
			retorno=0;
		}
	}



	return retorno;
}

int harcodeoCensistas(eCensista lista[], int tamCensistas)
{
	int i;
	int retorno=-1;
	int contadorCensistas;
	int totalCensistas;
	int legajoCensistas[]={100,101,102};
	char nombres[][TAMNOMBRE]={"ANA","JUAN","SOL"};
	int edades[]={34,24,47};
	char telefonos[][TAMTELEFONO]={"1203-2345","4301-54678","5902-37487"};


	contadorCensistas=0;
	totalCensistas=3;

	for(i=0;i<tamCensistas;i++)
	{
		if(lista[i].isEmpty==VACIO)
		{
			lista[i].legajoCensista=legajoCensistas[i];
			strcpy(lista[i].nombre,nombres[i]);
			lista[i].edad=edades[i];
			strcpy(lista[i].telefono,telefonos[i]);
			lista[i].isEmpty=LLENO;
			contadorCensistas++;
		}

		if(contadorCensistas==totalCensistas)
		{
			retorno=0;
			break;
		}
	}

	return retorno;
}

void mostrarCencista(eCensista lista)
{
	printf("%-15d %-15s %-10d %-15s\n", lista.legajoCensista, lista.nombre, lista.edad, lista.telefono);
}

void listarCensistas(eCensista lista[], int tamCensistas)
{
	int i;

	printf("Datos de los censistas:\n\n%-15s %-15s %-10s %-15s\n", "Legajo", "Nombre", "Edad", "Telefono");
	if(lista != NULL && tamCensistas>0)
	{
		for(i=0;i<tamCensistas;i++)
		{
			if(lista[i].isEmpty== LLENO)
			{
				mostrarCencista(lista[i]);
			}

		}
	}
}

