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

/// @fn int inicializarVivienda(eVivienda[], int)
/// @brief recorre el array e inicializa cada indice en 0(SIN CENSAR).
///
/// @param lista array a inicializar
/// @param tamVivienda tamanio del array
/// @return retorna 0 si se inicializo correctamente, en caso contrario retorna -1.
int inicializarVivienda(eVivienda lista[], int tamVivienda);

/// @fn int buscarEspacioLibreArrayVivienda(eVivienda[], int, int*)
/// @brief recorre el array y verifica si hay indices libres disponibles.
///
/// @param lista array para recorrer
/// @param tamVivienda tamanio del array
/// @param index el indice libre que retorna por referencia
/// @return retorna el indice libre del array por referencia si salio bien, en caso contrario retorna -1.
int buscarEspacioLibreArrayVivienda(eVivienda lista[], int tamVivienda, int* index);

/// @fn int buscarViviendaPorId(eVivienda[], int, int)
/// @brief recorre el array y busca el id de la vivienda que se solicita, si lo encuenta retorna el indice por referencia, sino retorna -1 en caso contrario.
///
/// @param lista array para buscar el id
/// @param tamVivienda tamanio del array
/// @param id id a buscar en el array.
/// @return retorna 0 y el indice por referencia si encuentra el id, en caso contrario -1 si el id no existe.
int buscarViviendaPorId(eVivienda lista[], int tamVivienda, int id);

/// @fn int modificarDatosVivienda(eVivienda[], int)
/// @brief recorre el array y mediante el id solicitado modifica los valores existentes.
///
/// @param lista array para recorrer y modificar.
/// @param tamVivienda tamanio del array
/// @return retorna 0 si la modificacion de el/los valores fueron correctamente, en caso de no existir el id retorna -1.
int modificarDatosVivienda(eVivienda lista[], int tamVivienda);

/// @fn void mostrarVivienda(eVivienda)
/// @brief recibe un lista e imprime los valores cargados
///
/// @param lista lista para imprimir los valores.
void mostrarVivienda(eVivienda lista);

/// @fn int darBajaVivienda(eVivienda[], int)
/// @brief recorre el array y solicita el id, para dar la baja logica (cambiar el estado a SINCENSAR).
///
/// @param lista array para hacer la baja
/// @param tamVivienda tamanio del array
/// @return retorna 0 si la baja fue exitosa, en caso contrario -1 si el id no existe.
int darBajaVivienda(eVivienda lista[], int tamVivienda);

/// @fn void mostrarViviendas(eVivienda[], int)
/// @brief recorre el array e imprime los valores existentes en el mismo.
///
/// @param lista array para imprimir
/// @param tamVivienda tamanio del array
void mostrarViviendas(eVivienda lista[], int tamVivienda);

/// @fn int ordenarViviendaPorcalle(eVivienda[], int)
/// @brief ordena el array por calle en forma alfabetica y en caso de repetirse las calles lo ordena por cantidad de personas en forma descendente.
///
/// @param lista array a ordenar
/// @param tamViviendas tamanio del array
/// @return retorna 0 si el ordenamiento fue correcto, en caso contrario -1 si hubo error en el tamanio o puntero a NULL.
int ordenarViviendaPorcalle(eVivienda lista[], int tamViviendas);

/// @fn void listarViviendasConSusCalles(eVivienda[], int)
/// @brief recorre el array e imprime los valores cargados, ordenados alfabeticamente por calles.
///
/// @param lista array a imprimir
/// @param tamViviendas tamanio del array
void listarViviendasConSusCalles(eVivienda lista[], int tamViviendas);

/// @fn int cargarUnaVivienda(eVivienda[], int, int)
/// @brief se solicita los datos para cargarlos en el indice vacio del array.
///
/// @param lista array a cargar los datos
/// @param index indice donde se va a cargar los datos
/// @param id id del indice
/// @return retorna 0 si la carga fue exitosa, en caso contrario -1 si no se logro la carga.
int cargarUnaVivienda(eVivienda lista[], int index, int id);

/// @fn int cargarViviendas(eVivienda[], int, int*)
/// @brief recibe los datos cargados y verifica que haya espacio en el array para cargarlo en el indice.
///
/// @param lista array donde se cargan los datos
/// @param tamViviendas tamanio del array
/// @param ultimoId id del indice a cargar
/// @return retorna 0 si se cargo exitosamente en el array, en caso contrario retorna -1 si se cancelo la carga o puntero a NULL.
int cargarViviendas(eVivienda lista[], int tamViviendas, int* ultimoId);

#endif /* EVIVIENDA_H_ */
