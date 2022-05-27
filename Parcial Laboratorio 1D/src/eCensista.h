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

/// @fn int buscarCensistaPorLegajo(eCensista[], int, int)
/// @brief recorre el array y busca el legajo del censista que se solicita, si lo encuenta retorna el indice donde esta, sino retorna -1 en caso contrario.
///
/// @param lista array a recorrer
/// @param tamCensistas tamanio del array
/// @param legajo legajo para buscar en el array
/// @return retorna 0 y el indice por referencia si encuentra el legajo, sino retorna -1 en caso de no existir el legajo.
int buscarCensistaPorLegajo(eCensista lista[], int tamCensistas, int legajo);

/// @fn int inicialiciarCensistas(eCensista[], int)
/// @brief recorre el array e inicializa cada indice en 0(VACIO).
///
/// @param lista array para inicializar
/// @param tamCensistas tamanio del array
/// @return si el array se inicializa retorna 0, sino retorna -1 si salio mal.
int inicialiciarCensistas(eCensista lista[], int tamCensistas);

/// @fn void listarCensistas(eCensista[], int)
/// @brief recorre el array e imprime los valores ya existente en el mismo.
///
/// @param lista array para imprimir
/// @param tamCensistas tamanio del array
void listarCensistas(eCensista lista[], int tamCensistas);

/// @fn void mostrarCencista(eCensista)
/// @brief recibe una lista e imprime el valor ya existente.
///
/// @param lista lista a recibir para imprimir
void mostrarCencista(eCensista lista);

/// @fn int harcodeoCensistas(eCensista[], int)
/// @brief carga en cada indice que no s encuentre ocupado del array, valores ya predefinidos.
///
/// @param lista array para cargar los datos.
/// @param tamCensistas tamanio del array
/// @return retorna 0 si los datos se cargaron correctamente, en caso contrario retorna -1 si no se cargo en el array.
int harcodeoCensistas(eCensista lista[], int tamCensistas);

/// @fn int buscarEspacioLibreArrayCensista(eCensista[], int, int*)
/// @brief recorre el array y verifica si hay indices libres.
///
/// @param lista array para buscar espacios libres
/// @param tamCensistas tamanio del array
/// @param index indice que retorna por referencia si se encontro un espacio vacio
/// @return si encuentra un espacio libre en el array retorna el indice por referencia, en caso contrario devuelve -1 si no hay espacios libres.
int buscarEspacioLibreArrayCensista(eCensista lista[], int tamCensistas, int* index);




#endif /* ECENSISTA_H_ */
