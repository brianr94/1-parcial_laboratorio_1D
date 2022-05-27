/*
 ============================================================================
 Name        : 1°parcial_laboratorio_1D
 Author      : BRIAN RIANI
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "eCensista.h"
#include "eVivienda.h"
#include "utn_inputs.h"

#define LENVIVIENDAS 5
#define LENCENCISTAS 3

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int ultimoIdIngresado;
	int viviendaIngresada;
	eVivienda viviendas[LENVIVIENDAS];
	eCensista cencistas[LENVIVIENDAS];

	viviendaIngresada=0;
	ultimoIdIngresado=20000;

	inicializarVivienda(viviendas, LENVIVIENDAS);
	inicialiciarCensistas(cencistas, LENCENCISTAS);
	harcodeoCensistas(cencistas, LENCENCISTAS);



	do
	{

		pedirNumeroEnteroValidado(&opcion,	"--------------------------\n"
											"1. ALTA VIVIENDA\n"
											"2. MODIFICAR VIVIENDA\n"
											"3. BAJA VIVIENDA\n"
											"4. LISTAR VIVIENDAS\n"
											"5. LISTAR CENCISTAS\n"
											"6. SALIR\n"
											"---------------------------\n"
											"Ingrese una opcion: ",
											"----------------------------\n"
											"1. ALTA VIVIENDA\n"
											"2. MODIFICAR VIVIENDA\n"
											"3. BAJA VIVIENDA\n"
											"4. LISTAR VIVIENDAS\n"
											"5. LISTAR CENCISTAS\n"
											"6. SALIR\n"
											"-----------------------------\n"
											"Error. Ingrese una opcion correcta: ", 1, 6);


			switch(opcion)
			{
				case 1:
					mostrarViviendas(viviendas, LENVIVIENDAS);
					if(cargarViviendas(viviendas, LENVIVIENDAS, &ultimoIdIngresado)==0)
					{
						viviendaIngresada++;
					}
					break;

				case 2:
					if(viviendaIngresada>0)
					{
						modificarDatosVivienda(viviendas, LENVIVIENDAS);
					}
					else
					{
						printf("Primero debe dar de alta una vivienda!!!\n");
					}


					break;

				case 3:
					if(viviendaIngresada>0)
					{
						if(darBajaVivienda(viviendas, LENCENCISTAS)==0)
						{
							viviendaIngresada--;
						}
					}
					else
					{
						printf("\nPrimero debe dar de alta  una vivienda!!!!\n");
					}
					break;

				case 4:
					if(viviendaIngresada>0)
					{
						listarViviendasConSusCalles(viviendas, LENVIVIENDAS);
					}
					else
					{
						printf("\nPrimero debe dar de alta  una vivienda!!!!\n");
					}
					break;

				case 5:
					listarCensistas(cencistas, LENCENCISTAS);
					break;

				case 6:
					printf("\nFinalizo el programa!!!\n");
					break;
			}

			if(opcion != 6)
			{
				system("pause");
			}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}
