/*
 * tp1.h
 *
 *  Created on: 24 sep. 2021
 *      Author: linux
 */

#ifndef TP1_H_
#define TP1_H_

int utn_menu();
/*
 * menu de opciones del programa
 *
 * se pide al usuario que ingrese un numero del 1 al 5 y lo valida
 * luego retorna el numero ingresado validado
 *
 */

void ingresoNumero(float* pIngreso, char* pMensaje, int* pFlagNum, int *flapOperacion);
/*Esta funcion valida que se ingrese un numero entre -16777215 y 16777215 si este numero no esta en este rango
 * la funcion enviara error y se pedira ingresar nuevamente el numero
 *
 * pMensaje= se ingresa el mensaje que se le mostrara al usuario dentro de comillas dobles
 *pIngreso= se ingresa el puntero de la variable donde se cargara el numero ingresado
 *pflagNum= Se ingresa el puntero de un flag que se pongra en 1 si se pudo realizar el contenido de la funcion
 *pflaOperacion= Se ingresa el puntero de un flag que se pondra en 0 si es que este y el valor en el puntero pflagNum es 1
 */

void calculos(float num1, float num2,int vectorFlag[], float vectorResultado[]);
/*
 * Esta funcion pide el ingreso de dos numeros y de un vector con distintas banderas que indican que se cargaron los numeros
 * luego realiza las operaciones y guarda los resultados en vectorResultado
 *
 * calcula todas las operaciones:
 * suma de num1 y num2
 * resta de num1 - num2
 * multiplicacion de num1 y num2
 * division de num1/num2
 * factorial del num1
 * factorial del num2
 *
 * carga en vectorFlag[3] un 0 si se pudo hacer la divicion y un 1 si no se pudo hacer
 * carga en vectorFlag[4] un -1 si el num1 no esta entre 0 y 34 para indicar que no se puede factorear ese numero
 * carga en vectorFlag[4] un -1 si el num2 no esta entre 0 y 34 para indicar que no se puede factorear ese numero
*/

void resultados(int vFlag[], float vOperaciones[]);
/*
 * Imprime todos los valores del vector cOperaciones solo si todos los valores de Vflag son 1
 */

void salir(int* seguir);
/*
 *pregunta si esta seguro de querer salir y pide el ingreso de 'y' para salir o 'n'
 *si se carga 'y' se carga un 0 en el valor en memoria del puntero seguir
 *
 *si se agrega cualquier caracter que no sea 'y' el valor del puntero seguira intacto
 *
 */

#endif /* TP1_H_ */
