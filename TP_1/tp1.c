/*
 * tp1.c
 *
 *  Created on: 24 sep. 2021
 *      Author: linux
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#define PASO 0
#define NO_PASO 1
#define SUMA 0
#define RESTA 1
#define MULTIPLICACION 2
#define DIVISION 3
#define FACTORIAL_1 4
#define FACTORIAL_2 5
#define FLAG_NUM_1 0
#define FLAG_NUM_2 1
#define FLAG_OPERASION 2
#define FLAG_DIVISION 3


int utn_menu()
{
    float seleccion;

    printf("Ingrese la opcion deseada \n\n");
    printf("1 - Inngresar el primer operador  (A=X)\n");
    printf("2 - Inngresar el segundo operador (B=Y)\n");
    printf("3 - Calcular todas las operaciones\n");
    printf("4 - Informar resultados\n");
    printf("5 - Salir\n\n");

    utn_minMax(&seleccion, "Indique opcion: ", "Error", 1,5);
    utn_clear();

    return seleccion;

}

void ingresoNumero(float* pIngreso, char* pMensaje, int* pFlagNum, int *flapOperacion)
{
    if(pIngreso!=NULL && pMensaje!=NULL && pFlagNum!=NULL && flapOperacion!=NULL)
    {
        if(*pFlagNum == PASO && *flapOperacion == PASO)
        {
            *flapOperacion = NO_PASO;
        }

        if(utn_minMax(pIngreso, pMensaje, "Error", -16777215,16777215) == 0)
        {
            utn_clear();
            printf("El operador fue cargado correctamente");
            *pFlagNum = PASO;
            utn_stop();
            utn_clear();
        }
        else
        {
            printf("Error en la carga del operador");
        }
    }
}

void calculos(float num1, float num2,int vectorFlag[], float vectorResultado[])
{
    int noDivision;
    if(vectorFlag!=NULL && vectorResultado!=NULL)
    {
        if (vectorFlag[FLAG_NUM_1]==PASO && vectorFlag[FLAG_NUM_2]==PASO)
        {
            utn_operador('+',&vectorResultado[SUMA], num1, num2);
            utn_operador('-',&vectorResultado[RESTA], num1, num2);
            utn_operador('*',&vectorResultado[MULTIPLICACION], num1, num2);
            noDivision = utn_operador('/',&vectorResultado[DIVISION],num1,num2);
            if(num1>0 && num1<34)
            {
            	vectorResultado[FACTORIAL_1]=utn_factorial(num1);
            }
            else
            {
            	vectorResultado[FACTORIAL_1]=-1;
            }

            if(num2>0 && num2<34)
            {
            	vectorResultado[FACTORIAL_2]=utn_factorial(num2);
            }
            else
            {
            	 vectorResultado[FACTORIAL_2]=-1;
            }

            printf("Operaciones realizadas");
            vectorFlag[FLAG_OPERASION]=PASO;
            vectorFlag[FLAG_DIVISION]=noDivision;
        }
        else
        {
            printf("Primero deve ingresar los dos operadores ");
        }
    }
    utn_stop();
    utn_clear();
}

void resultados(int vFlag[], float vOperaciones[])
{
    if(vFlag!=NULL && vOperaciones!=NULL)
    {
        if(vFlag[FLAG_NUM_1]==PASO && vFlag[FLAG_NUM_2]==PASO)
        {
            if(vFlag[FLAG_OPERASION]==PASO)
            {
                printf("El resultado de A+B es: %.2f\n", vOperaciones[SUMA]);
                printf("El resultado de A-B es: %.2f\n",vOperaciones[RESTA]);
                printf("El resultado de A*B es: %.2f\n",vOperaciones[MULTIPLICACION]);
                if(vFlag[FLAG_DIVISION]==1)
                {
                    printf("No se puede dividir por 0\n");
                }
                else
                {
                    printf("El resultado de A/B es: %.2f\n", vOperaciones[DIVISION]);
                }
                if(vOperaciones[FACTORIAL_1]==-1)
                {
                    printf("No se puede factoriar este numero\n");
                }
                else
                {
                    printf("El factorial de A es: %.f\n",vOperaciones[FACTORIAL_1]);
                }

                if(vOperaciones[FACTORIAL_2]==-1)
                {
                    printf("No se puede factoriar este numero");
                }
                else
                {
                    printf("El factorial de B es: %.f\n",vOperaciones[FACTORIAL_2]);
                }
            }
            else
            {
                printf("Primero deve realicar las operaciones");
            }
        }
        else
        {
            printf("Primero deve ingresar los dos operadores");
        }
    }

    utn_stop();
    utn_clear();
}

void salir(int* seguir)
{
    char letraInput;
    if(seguir!=NULL)
    {
        printf("Esta seguro que quiere salir (y/n) ");
        __fpurge(stdin);
        scanf("%c",&letraInput);
        if(letraInput=='y')
        {
            *seguir=0;
        }
    }

    utn_clear();
}


