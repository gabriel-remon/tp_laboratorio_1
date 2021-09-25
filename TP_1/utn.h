/*
 * utn.h
 *
 *      Autor: Gabriel Remon
 */

#ifndef UTN_H_
#define UTN_H_

int utn_minMax(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo);
/*
 * Esta funcion pude un numero al usuario dentro de un rango permitido validando este dato de entrada y luego carga
 * ese valor en el espacio de memoria de pResultado. Pide un valor hasta que el usuario ingrese un valor valido
 *
 * pResultado= se carga el puntero donde se quiere guardar el dato ingresado
 * pMensaje= se ingresa en comillas dobles el mensaje que quiere mostrarse al usuario
 * pMensajeError= se ingresa en comillas dobles el mensaje de error que se mostrara al usuario, se mostrara el mensaje de error y
 *                a contiuacion se mostrara el mensaje en pMensaje. esto se repetira hasta que se ingrese un valor valido
 * minimo= se ingresa el minimo numero permitido
 * maximo= se ingresa el maximo numero permitido
 *
 */

int utn_operador(char tipoOperador,float* pResultado, float num1, float num2);
/*
 * Esta funcion hace las operaciones suma, resta, multiplicacion y division de los numeros num1 y num2
 * para luego guardar el resultado en el puntero pResultado
 *
 * para elegir el tipo de operacion que se desea ralizar se deve ingresar el operador aritmetico en entre comillas simples
 * ya sea '+' '-' '*' '/'
 *
 * retorna -1 si no se pudo realizar la funcion
 * retorna 0 si la operacion se realizo
 * retorna 1 si la rivicion no se pudo realizar porque num2 es 0
 *
 */

int utn_factorial(int num);
/*
 * Se ingresa un numero por valor y retorna el factorial de ese numero
 */

void utn_clear();
/*
*Limpia la consola en sistema operativo linux
*Si esta funcion se ejecuta en la consola de eclipse da error deviado a que este no tiene una consola real
*
*/

void utn_stop();
/*
 * Se detiene la ejecusion del programa hasta precionar enter
 *
*/

#endif /* UTN_H_ */
