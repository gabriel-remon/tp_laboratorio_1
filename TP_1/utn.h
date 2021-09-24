/*
 * utn.h
 *
 *  Created on: 24 sep. 2021
 *      Author: linux
 */

#ifndef UTN_H_
#define UTN_H_

int utn_minMax(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo);//ingresa un numero entre un maximo y un minimo hasta que sea el correcto
int utn_convercionTemp(float* pResultado, int temp, int tipo);//tipo=0 - convierte de celcius a farenheit ; tipo=1 - convierte de farengeit a celcius
int utn_getInt(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int intentos);//pide un entero y valida entre maximo y minimo
int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int intentos);//pide un flotante y valida entre maximo y minimo
int utn_getChar(char* pResultado, char* pMensaje, char* pMensajeError, char minimo, char maximo, int intentos);//pide un caracter y valida entre maximo y minimo
int utn_operador(char tipoOperador,float* pResultado, float num1, float num2); //operador para +, - y *
int utn_factorial(int num); //operacion factoreal de un numero
int utn_inputNum(int* pResultado, char* pMensaje, char* pMensajeError); //pide un entero y lo valida
void utn_clear(); //limpia la pantalla (linux)
void utn_stop(); //pausa el programa hasta que se precione enter




#endif /* UTN_H_ */
