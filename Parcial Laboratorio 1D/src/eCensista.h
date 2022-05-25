/*
 * eCensista.h
 *
 *  Created on: 20 may. 2022
 *      Author: brian
 */

#ifndef ECENSISTA_H_
#define ECENSISTA_H_

#define TAMNOMBRE 51
#define TAMTELEFONO 31
#define VACIO 0
#define LLENO 1

typedef struct
{
	int legajoCensista;
	char nombre[TAMNOMBRE];
	int edad;
	char telefono[TAMTELEFONO];
	int isEmpty;

}eCensista;

int buscarCensistaPorLegajo(eCensista lista[], int tamCensistas, int legajo);

int inicialiciarCensistas(eCensista lista[], int tamCensistas);

void listarCensistas(eCensista lista[], int tamCensistas);

void mostrarCencista(eCensista lista);

int harcodeoCensistas(eCensista lista[], int tamCensistas);





#endif /* ECENSISTA_H_ */
