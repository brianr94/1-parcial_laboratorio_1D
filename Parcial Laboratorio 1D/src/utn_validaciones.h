/*
 * utn_validaciones.h
 *
 *  Created on: 26 may. 2022
 *      Author: brian
 */

#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_

#include <string.h>
#include <ctype.h>

/// @fn int esNumero(char*)
/// @brief recibe una cadena de caracteres y verifica que la cadena este compuesta por letras.
///
/// @param cadena cadena a verificar
/// @return retorna 0 si la cadena esta compuesta por letras, en caso contrario retorna -1 si hay numeros en la cadena
int esNumero(char* cadena);

/// @fn int validarSignos(char*)
/// @brief recibe una cadena de caracteres y verifica que se hayan ingresados signos en la cadena.
///
/// @param cadena cadena a verificar
/// @return retorna 0 si no se encuentra signos en la cadena, en caso contrario retorna -1 si la cadena contiene signos.
int validarSignos(char* cadena);

/// @fn int validarEspacio(char*)
/// @brief recibe cadena de caracteres y verifica que no haya espacios, tabulador, etc.
///
/// @param cadena cadena a verificar
/// @return retorna 0 si la cadena no tiene espacios, en caso contrario retorna -1 si hay espacios en la cadena.
int validarEspacio(char* cadena);

/// @fn int primerLetraMayuscula(char*)
/// @brief recibe la cadena de caracteres y cambia la primer letra de la cadena en mayusculas.
///
/// @param cadena cadena de caracteres
/// @return retorna 0 si se produjo el cambio, en caso contrario retorna -1 si hay error puntero a NULL.
int primerLetraMayuscula(char* cadena);

/// @fn int cadenaEnMinuscula(char*)
/// @brief recibe la cadena de caracteres y lo pasa a minusculas.
///
/// @param cadena cadena de caracteres para pasar a minusculas
/// @return retorna 0 si lo paso a minusculas, en caso contrario retorna -1 si hay error puntero a NULL.
int cadenaEnMinuscula(char* cadena);


#endif /* UTN_VALIDACIONES_H_ */
