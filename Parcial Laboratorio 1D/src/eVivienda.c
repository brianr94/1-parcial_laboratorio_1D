/*
 * eVivienda.c
 *
 *  Created on: 20 may. 2022
 *      Author: brian
 */

#include "eVivienda.h"

#include "utn_inputs.h"


int inicializarVivienda(eVivienda lista[], int tamVivienda)
{
	int i;
	int retorno=-1;

	if(lista != NULL && tamVivienda>0)
	{
		for(i=0;i<tamVivienda;i++)
		{
			lista[i].estadoVivienda= SINCENSAR;
			retorno=0;
		}
	}

	return retorno;
}

int buscarViviendaPorId(eVivienda lista[], int tamVivienda, int id)
{
	int i;
	int retorno=-1;

	if(lista != NULL && tamVivienda>0)
	{
		for(i=0;i<tamVivienda;i++)
		{
			if(lista[i].estadoVivienda==CENSADA && lista[i].idVivienda==id)
			{
				retorno=i;
				break;

			}
		}
	}

	return retorno;
}

int buscarEspacioLibreArrayVivienda(eVivienda lista[], int tamVivienda, int* index)
{
	int i;
	int retorno=-1;

	if(lista != NULL && tamVivienda>0)
	{
		for(i=0; i<tamVivienda;i++)
		{
			if(lista[i].estadoVivienda==SINCENSAR)
			{
				*index=i;
				break;
			}
			retorno=0;
		}
	}

	return retorno;
}

int modificarDatosVivienda(eVivienda lista[], int tamVivienda)
{
	int idIngresado;
	int index;
	int opcion;
	int retorno=-1;
	eVivienda auxVivienda;

	if(lista != NULL && tamVivienda>0)
	{
		mostrarViviendas(lista, tamVivienda);

		pedirNumeroEnteroValidado(&idIngresado,"Ingrese ID de la vivienda a modificar(20000-30000): ", "Error. Reingrese ID correctamente(20000-30000): ", 20000, 30000);
		index=buscarViviendaPorId(lista, tamVivienda, idIngresado);

		if(index != -1)
		{



			do
			{
				printf("Datos de la vivienda a modificar:\n\n%-10s %-20s %-19s %-23s %-21s\n", "ID Vivienda", "Calle", "Cant. De Personas", "Cant. De Habitaciones", "Tipo De Vivienda");
				mostrarVivienda(lista[index]);

				auxVivienda=lista[index];
				pedirNumeroEnteroValidado(&opcion,
												"-------------------------------------------\n"
												 "1.Modificar calle\n"
												 "2.Modicar cantidad de personas\n"
												 "3.Modificar cantidad de habitaciones\n"
												 "4.Modificar tipo de vivienda\n"
												 "5.Volver\n"
												 "--------------------------------------------\n"
												 "Ingrese una opcion: ",
												 "--------------------------------------------\n"
												 "1.Modificar calle\n"
												 "2.Modicar cantidad de personas\n"
												 "3.Modificar cantidad de habitaciones\n"
												 "4.Modificar tipo de vivienda\n"
												 "5.Volver\n"
												 "---------------------------------------------\n"
												 "Opcion Incorrecta. Ingrese una opcion correcta: ", 1, 5);

				switch(opcion)
				{
				 case 1:

					 pedirCadena(auxVivienda.calle, "Ingrese el nombre de la calle: ", "Error. Ingrese la calle de hasta 25 caracteres: ", TAMCALLE);

					 if(verificarConfirmacion("\nIngrese 's' para confirmar la modificacion: ") != -1)
					 {
						lista[index]=auxVivienda;
						printf("\nSe realizo correcatemente la modificacion de la calle.!!!\n");
					 }
					 else
					 {
						 printf("\nSe cancelo la modificacion del nombre de la calle!!\n");
					 }
					 break;
				 case 2:
					 pedirNumeroEnteroValidado(&auxVivienda.cantidadPersonas, "Ingrese la cantidad de personas (1-10): ", "Error. ingrese correctamente la cantidad de personas (1-10): ", 1, 10);

					 if(verificarConfirmacion("\nIngrese 's' para confirmar la modificacion") != -1)
					 {
						lista[index]=auxVivienda;
						printf("\nSe realizo correcatemente de la cantidad de personas.!!!\n");
					 }
					 else
					 {
						 printf("\nSe cancelo la modificacion de la cantidad de personas!!\n");
					 }
					 break;
				 case 3:
					 pedirNumeroEnteroValidado(&auxVivienda.cantidadHabitaciones, "Ingrese la cantidad de habitaciones: ", "Error. Ingrese correctamente la cantidad de habitaciones (1-10): ", 1, 10);

					 if(verificarConfirmacion("\nIngrese 's' para confirmar la modificacion") != -1)
					 {
						 lista[index]=auxVivienda;
						 printf("\nSe realizo correcatemente la modificacion de la calle.!!!\n");
					 }
					 else
					 {
						 printf("\nSe cancelo la modificacion de la cantidad de habitaciones!!\n");
					 }
					 break;
				 case 4:
					 pedirNumeroEnteroValidado(&auxVivienda.tipoVivienda, "Ingrese el tipo de vivienda (1-Casa 2-Departamento 3-Casilla 4-Rancho): ", "Error. Ingrese correctamente el tipo de vivienda (1-Casa 2-Departamento 3-Casilla 4-Rancho): ", 1, 4);

					 if(verificarConfirmacion("\nIngrese 's' para confirmar la modificacion") != -1)
					 {
						 lista[index]=auxVivienda;
						 printf("\nSe realizo correcatemente la modificacion del tipo de vivienda.!!!\n");
					 }
					 else
					 {
						 printf("\nSe cancelo la modificacion del tipo de vivienda!!\n");
					 }

					 break;
				 case 5:
					 break;
				}

				if(opcion != 5)
				{
					system("pause");
				}

			}while(opcion != 5);

		}
		else
		{
			printf("\nEl ID de la vivienda ingresada no existe!!!\n");
		}

		retorno=0;
	}

	return retorno;
}

int darBajaVivienda(eVivienda lista[], int tamVivienda)
{
	int idIngresado;
	int index;
	int retorno=-1;

	if(lista != NULL && tamVivienda>0)
	{

		mostrarViviendas(lista, tamVivienda);
		pedirNumeroEnteroValidado(&idIngresado,"\nIngrese el ID de la vivienda a dar de baja (20000-30000): ", "Erorr. Reingrese el ID correctamente (20000 y 30000)", 20000, 30000);
		index= buscarViviendaPorId(lista, tamVivienda, idIngresado);

		if(index != -1)
		{
			printf("\nDatos de las viviendas a dar de baja:\n\n%-10s %-20s %-19s %-23s %-21s\n", "ID Vivienda", "Calle", "Cant. De Personas", "Cant. De Habitaciones", "Tipo De Vivienda");
			mostrarVivienda(lista[index]);

			if(verificarConfirmacion("\nIngrese 's' para confirmar la baja de la vivienda: ")==0)
			{
				lista[index].estadoVivienda=SINCENSAR;
				printf("\nLa baja de la vivienda fue dada correctamente!!!\n");
				retorno=0;
			}
			else
			{
				printf("\nSe cancelo la baja de la vivienda!!!\n");
			}

		}
		else
		{
			printf("\nEl ID de la vivienda no existe!!!\n");
		}

	}

	return retorno;
}

void mostrarVivienda(eVivienda lista)
{
	switch(lista.tipoVivienda)
	{
		case 1:
			printf("\n%-10d %-20s %-20d %-25d %-25s\n", lista.idVivienda, lista.calle, lista.cantidadPersonas, lista.cantidadHabitaciones, "CASA");
			break;
		case 2:
			printf("\n%-10d %-20s %-20d %-25d %-25s\n", lista.idVivienda, lista.calle, lista.cantidadPersonas, lista.cantidadHabitaciones, "DEPARTAMENTO");
			break;
		case 3:
			printf("\n%-10d %-20s %-20d %-25d %-25s\n", lista.idVivienda, lista.calle, lista.cantidadPersonas, lista.cantidadHabitaciones, "CASILLA");
			break;
		case 4:
			printf("\n%-10d %-20s %-20d %-25d %-25s\n", lista.idVivienda, lista.calle, lista.cantidadPersonas, lista.cantidadHabitaciones, "RANCHO");
			break;
	}
}

void mostrarViviendas(eVivienda lista[], int tamVivienda)
{
	int i;

	if(lista != NULL && tamVivienda>0)
	{
		printf("\nDatos de las viviendas:\n\n%-10s %-20s %-19s %-23s %-21s\n", "ID Vivienda", "Calle", "Cant. De Personas", "Cant. De Habitaciones", "Tipo De Vivienda");
		for(i=0;i<tamVivienda;i++)
		{
			if(lista[i].estadoVivienda==CENSADA)
			{
				mostrarVivienda(lista[i]);
			}

		}
	}
}

void listarViviendasConSusCalles(eVivienda lista[], int tamViviendas)
{
	int i;

	if(lista != NULL && tamViviendas>0)
	{
		printf("\nDatos de las viviendas:\n\n%-10s %-20s %-19s %-23s %-21s\n", "ID Vivienda", "Calle", "Cant. De Personas", "Cant. De Habitaciones", "Tipo De Vivienda");
		ordenarViviendaPorcalle(lista, tamViviendas);
		for(i=0;i<tamViviendas;i++)
		{
			mostrarVivienda(lista[i]);
		}

	}
}

int ordenarViviendaPorcalle(eVivienda lista[], int tamViviendas)
{
	int i;
	int j;
	int retorno=1;
	eVivienda auxVivienda;

	if(lista != NULL && tamViviendas>0)
	{

		for(i=0;i<tamViviendas;i++)
		{
			for(j=i+1;j<tamViviendas;j++)
			{
				if(lista[i].estadoVivienda==CENSADA && lista[j].estadoVivienda==CENSADA)
				{
					if(strcmp(lista[i].calle,lista[j].calle)==1)
					{
						auxVivienda=lista[i];
						lista[i]=lista[j];
						lista[j]=auxVivienda;
						retorno=0;
					}
					else
					{
						if(strcmp(lista[i].calle,lista[j].calle)==0 && lista[i].cantidadPersonas<lista[j].cantidadPersonas)
						{
							auxVivienda=lista[i];
							lista[i]=lista[j];
							lista[j]=auxVivienda;
							retorno=0;
						}
					}
				}
			}
		}
	}

	return retorno;
}

int cargarUnaVivienda(eVivienda lista[], int index, int id)
{
	int retorno=1;
	eVivienda auxVivienda;


	if(lista != NULL)
	{
		auxVivienda.idVivienda=id;

		if(pedirCadena(auxVivienda.calle, "Ingrese la calle de la vivienda(max 25 caracteres): ", "Error. Ingrese correctamente la calle de hasta 25 caracteres: ", TAMCALLE)==-1)
		{
			printf("Error. Ingrese otra vez los datos correctamente");
		}

		if(pedirNumeroEnteroValidado(&auxVivienda.cantidadPersonas, "Ingrese la cantidad de personas en la vivienda(min 1, max 10): ", "Error. Ingrese correctamente la cantidad de personas(min 1, max 10):", 1, 10)==-1)
		{
			printf("Error. Ingrese otra vez los datos correctamente");
		}

		if(pedirNumeroEnteroValidado(&auxVivienda.cantidadHabitaciones, "Ingrese la cantidad de habitaciones de la vivienda (min 1, max 10): ", "Error. Ingrese corectamente la cantidad de habitaciones(min 1, max 10): ", 1, 10)==-1)
		{
			printf("Error. Ingrese otra vez los datos correctamente");
		}

		if(pedirNumeroEnteroValidado(&auxVivienda.tipoVivienda, "Ingrese el tipo de vivienda (1-CASA 2-DEPARTAMENTO 3-CASILLA 4-RANCHO): ", "Error. Ingrese correctamente el tipo de vivienda(1-CASA 2-DEPARTAMENTO 3-CASILLA 4-RANCHO): ", 1, 4)==-1)
		{
			printf("Error. Ingrese otra vez los datos correctamente");
		}


		printf("\nDatos de las vivienda a cargar:\n\n%-10s %-20s %-19s %-23s %-21s\n", "ID Vivienda", "Calle", "Cant. De Personas", "Cant. De Habitaciones", "Tipo De Vivienda");
		mostrarVivienda(auxVivienda);

		if(verificarConfirmacion("\nIngrese 's' para confirmar la carga: ")==0)
		{
			lista[index].idVivienda=id;
			strcpy(lista[index].calle,auxVivienda.calle);
			lista[index].cantidadPersonas= auxVivienda.cantidadPersonas;
			lista[index].cantidadHabitaciones= auxVivienda.cantidadHabitaciones;
			lista[index].tipoVivienda= auxVivienda.tipoVivienda;
			lista[index].estadoVivienda= CENSADA;
			retorno=0;
		}
	}

	return retorno;
}

int cargarViviendas(eVivienda lista[], int tamViviendas, int* ultimoId)
{
	int retorno=-1;
	int id;
	int index;

	buscarEspacioLibreArrayVivienda(lista, tamViviendas, &index);

	id=*ultimoId;

	if(index != -1)
	{
		printf("\nCargando una vivienda....\n\n");
		if(cargarUnaVivienda(lista, index, id)==0)
		{
			printf("\nSe ha cargado con exito la vivienda!!!\n");
			id++;
			*ultimoId=id;
		}
		else
		{
			printf("\nSe cancelo la carga de la vivienda. Cargue la vivienda nuevamente!!!\n");
		}
		retorno=0;
	}
	else
	{
		printf("\nNo hay espacio para cargar una vivienda!!!\n");
	}

	return retorno;
}
