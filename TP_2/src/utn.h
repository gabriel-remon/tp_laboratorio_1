/*
 *      Author: Gabriel Remon
 */

#ifndef UTN_H_
#define UTN_H_


int utn_minMaxInt(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo);
/** pide un numero entero al usuario y lo valida entre un parametro minimo y maximo. Reintenta hasta conseguir un numero valido
* parametro pResultado int* guarda el numero validado en la pocision del puntero
* parametro pMensaje char* imprime al usuario por string el valor en ese puntero
* parametro pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
* parametro minimo int
* parametro maximo int
*
* retorna int return (-1) si huvo un error - (0) si ok
*/

int utn_minMaxFloat(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo);
/** pide un numero flotante al usuario y lo valida entre un parametro minimo y maximo. Reintenta hasta conseguir un numero valido
* parametro pResultado float* guarda el numero validado en la pocision del puntero
* parametro pMensaje char* imprime al usuario por string el valor en ese puntero
* parametro pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
* parametro minimo int
* parametro maximo int
*
* retorna int return (-1) si huvo un error - (0) si ok
*/

int utn_getCharDos(char* pResultado, char* pMensaje, char* pMensajeError, char criterio1, char criterio2);
/** pide un caracter al usuario y lo valida entre dos caracteres asignados. Reintenta hasta conseguir un caracter valido
* parametro pResultado char* guarda el caracter validado en la pocision del puntero
* parametro pMensaje char* imprime al usuario por string el valor en ese puntero
* parametro pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
* parametro minimo char 1º caracter permitido
* parametro maximo char 2º caracter permitido
*
* retorna int return (-1) si huvo un error - (0) si ok
*/

int utn_getInt(int* pResultado, char* pMensaje, char* pMensajeError);
/** pide un numero entero al usuario y lo valida. Reintenta hasta conseguir un numero valido
* parametro pResultado int* guarda el numero validado en la pocision del puntero
* parametro pMensaje char* imprime al usuario por string el valor en ese puntero
* parametro pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
*
* retorna int return (-1) si huvo un error - (0) si ok
*/

int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError);
/** pide un numero flotante al usuario y lo valida. Reintenta hasta conseguir un numero valido
* parametro pResultado float* guarda el numero validado en la pocision del puntero
* parametro pMensaje char* imprime al usuario por string el valor en ese puntero
* parametro pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
*
* retorna int return (-1) si huvo un error - (0) si ok
*/

int utn_getChar(char* pResultado, char* pMensaje, char* pMensajeError);
/** pide un caracter al usuario y lo valida. Reintenta hasta conseguir un caracter valido
* parametro pResultado char* guarda el caracter validado en la pocision del puntero
* parametro pMensaje char* imprime al usuario por string el valor en ese puntero
* parametro pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
*
* retorna int return (-1) si huvo un error - (0) si ok
*/

void utn_clear();
/** Limpia todo el texto que haya en la consola
*/

void utn_stop();
/** Detiene la ejecucion del programa hasta que el usuario precione enter
*/

int utn_ingresoScring(char cadena[],char* pMensaje, char* pMensajeError, int tamPermitido);
/** pide un string al usuario y valida que sea mas chico que el tamaño permitido. Reintenta hasta conseguir un string valido
* parametro cadena[] char destino donde se guardara el string ingresado
* parametro pMensaje char* imprime al usuario por string el valor en ese puntero
* parametro pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
* parametro tamPermitido int tamaño maximo del string ingresado
*
* retorna int return (-1) si huvo un error - (0) si ok
*/

int esPalabra(char vec[], int tam);
/** pide un string por parametro y valida que todos los caracteres sean letras, si lo son tranforma todos a minuscula
y luego el primero a mayuscula
* parametro vec[] char
* parametro tam int tamaño maximo del string
*
* retorna int return (1) si no todos los caracteres son letras - (0) si todos son letras
*/


#endif /* UTN_H_ */
