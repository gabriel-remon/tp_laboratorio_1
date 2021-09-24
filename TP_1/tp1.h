/*
 * tp1.h
 *
 *  Created on: 24 sep. 2021
 *      Author: linux
 */

#ifndef TP1_H_
#define TP1_H_

int utn_menu(); //menu de opciones
void ingresoNumero(float* pIngreso, char* pMensaje, int* pFlagNum, int *flapOperacion); //funcion para cargar los numeros
void calculos(float num1, float num2,int vectorFlag[], float vectorResultado[]);//calcula todas las operaciones
void resultados(int vFlag[], float vOperaciones[]);//muestra los resultados
void salir(int* seguir);// pregunta si esta seguro de querer salir


#endif /* TP1_H_ */
