/*
 * utn_Libreria.c
 *
 *  Created on: 14 may. 2022
 *      Author: brian
 */

#include "utn_inputs.h"
#include "utn_validaciones.h"

int pedirCadenaValidada(char* cadena,char* mensaje,char* mensajeError,int maxTam)
{
	int retorno=-1;
	char cadenaAux[200];

	if(cadena!=NULL && maxTam>0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",cadenaAux);

		while(strlen(cadenaAux)>maxTam || esNumero(cadenaAux)==-1 || validarSignos(cadenaAux)==0)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%s",cadenaAux);
		}

		cadenaEnMinuscula(cadenaAux);
		primerLetraMayuscula(cadenaAux);
		strcpy(cadena,cadenaAux);
		retorno=0;
	}

	return retorno;
}

int pedirNumero(int* numero,char* mensaje,char* mensajeError,int min, int max)
{
	int retorno=-1;
	char numeroAux[51];
	int numeroEnteroAux;


	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{

		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",numeroAux);
		numeroEnteroAux=atoi(numeroAux);


		while((!esNumero(numeroAux) && !validarEspacio(mensaje)) || (numeroEnteroAux>max||numeroEnteroAux<min))
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%s",numeroAux);
			numeroEnteroAux=atoi(numeroAux);
		}

		*numero=atoi(numeroAux);
		retorno=0;

	}

	return retorno;
}

int pedirNumeroFlotante(float* numero, char* mensaje,char* mensajeError,int min,int max)
{
	int retorno=-1;
	char numeroAux[51];
	float numeroFlotAux;

	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",numeroAux);
		numeroFlotAux=atof(numeroAux);

		while((!esNumero(numeroAux) && !validarEspacio(mensaje)) || (numeroFlotAux<min ||numeroFlotAux>max))
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",numeroAux);
			numeroFlotAux=atof(numeroAux);
		}

		*numero=atof(numeroAux);
		retorno=0;
	}
	return retorno;
}

int pedirCadena(char* cadena,char* mensaje,char* mensajeError,int tamMax)
{
	int retorno=-1;
	char cadenaAux[200];

	if(cadena!=NULL && tamMax>0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",cadenaAux);

		while(strlen(cadenaAux)>tamMax)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%s",cadenaAux);
		}
		cadenaEnMinuscula(cadenaAux);
		strcpy(cadena,cadenaAux);
		retorno=0;
	}

	return retorno;
}



int pedirNumeroEnteroValidado(int* pNumero, char* mensaje, char* mensajeError, int min, int max)
{
	int numeroIngresado;
	int retorno=-1;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
	}

	*pNumero=numeroIngresado;
	retorno=0;

	return retorno;
}

int pedirCaracter(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}

int verificarConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}

	return retorno;
}
