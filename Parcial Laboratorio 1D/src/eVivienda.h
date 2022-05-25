/*
 * eVivienda.h
 *
 *  Created on: 20 may. 2022
 *      Author: brian
 */

#ifndef EVIVIENDA_H_
#define EVIVIENDA_H_

#define CENSADA 1
#define SINCENSAR 0

#define TAMCALLE 25

#define CASA 1
#define DEPARTAMENTO 2
#define CASILLA 3
#define RANCHO 4

typedef struct
{
	int idVivienda;
	char calle[TAMCALLE];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int estadoVivienda;

}eVivienda;

int inicializarVivienda(eVivienda lista[], int tamVivienda);

int buscarEspacioLibreArrayVivienda(eVivienda lista[], int tamVivienda, int* index);

int buscarViviendaPorId(eVivienda lista[], int tamVivienda, int id);

int modificarDatosVivienda(eVivienda lista[], int tamVivienda);

void mostrarVivienda(eVivienda lista);

int darBajaVivienda(eVivienda lista[], int tamVivienda);

void mostrarViviendas(eVivienda lista[], int tamVivienda);

int ordenarViviendaPorcalle(eVivienda lista[], int tamViviendas);

void listarViviendasConSusCalles(eVivienda lista[], int tamViviendas);

int cargarUnaVivienda(eVivienda lista[], int index, int id);

int cargarViviendas(eVivienda lista[], int tamViviendas, int* ultimoId);

#endif /* EVIVIENDA_H_ */
