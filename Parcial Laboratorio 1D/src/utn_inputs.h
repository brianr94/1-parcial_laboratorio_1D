/*
 * utn_Libreria.h
 *
 *  Created on: 14 may. 2022
 *      Author: brian
 */

#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/// @fn int pedirCadenaValidada(char*, char*, char*, int)
/// @brief solicita una cadena de caracteres y verifica que la cadena no exceda el maximo definido, si contiene numeros o contiene signos.
///
/// @param cadena puntero a cadena de caracteres
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param maxTam tamanio para verificar el maximo de la cadena de caracteres
/// @return retorna 0 si esta fue correcta la cadena de caracteres, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirCadenaValidada(char* cadena,char* mensaje,char* mensajeError,int maxTam);

/// @fn int pedirNumero(int*, char*, char*, int, int)
/// @brief solicita un numero al usuario y verifica que este entre un minimo y maximo definido
///
/// @param numero puntero a numero
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param min minimo a verificar
/// @param max maximo a verificar
/// @return retorna 0 si la validacion fue correcta, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirNumero(int* numero,char* mensaje,char* mensajeError,int min, int max);

/// @fn int pedirNumeroFlotante(float*, char*, char*, int, int)
/// @brief se solicita un numero flotante al usuario  y verifica que este entre un minimo y maximo definido
///
/// @param numero puntero a numero
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param min minimo a verificar
/// @param max maximo a verificar
/// @return retorna 0 si la validacion fue correcta, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirNumeroFlotante(float* numero, char* mensaje,char* mensajeError,int min,int max);

/// @fn int pedirNumeroEnteroValidado(int*, char*, char*, int, int)
/// @brief solicita un numero al usuario y verifica que este entre un minimo y maximo definido
///
/// @param pNumero puntero a numero
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param min minimo a verificar
/// @param max maximo a verificar
/// @return retorna 0 si la validacion fue correcta, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirNumeroEnteroValidado(int* pNumero, char* mensaje, char* mensajeError, int min, int max);

/// @fn int pedirCadena(char*, char*, char*, int)
/// @brief solicita una cadena de caracteres y verifica que la cadena no exceda el maximo definido
///
/// @param cadena puntero a cadena de caracteres
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @param mensajeError recibe un puntero de cadena de caracteres con un mensaje de error
/// @param tamMax tamanio maximo a verificar en la cadena de caracteres
/// @return retorna 0 si esta fue correcta la cadena de caracteres, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirCadena(char* cadena,char* mensaje,char* mensajeError,int tamMax);

/// @fn int pedirCaracter(char*, char*)
/// @brief solicita un caracter al usuario
///
/// @param caracter puntero a caracter
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @return retorna 0 si el caracter fue correctamente ingresado, en caso contrario retorna -1 si hubo error puntero a NULL.
int pedirCaracter(char* caracter, char* mensaje);

/// @fn int verificarConfirmacion(char*)
/// @brief solicita el caracter 's' y valida el caracter ingresado
///
/// @param mensaje recibe un puntero de cadena de caracteres con un mensaje
/// @return retorna 0 si la validacion del caracter es correcta, en caso contario retorna -1 si hubo error puntero a NULL.
int verificarConfirmacion(char* mensaje);

#endif /* UTN_INPUTS_H_ */
