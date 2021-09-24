/*
 * main.c
 *
 *  Created on: 24 sep. 2021
 *      Author: linux
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include "utn.h"
#define NO_PASO 1
#define FLAG_NUM_1 0
#define FLAG_NUM_2 1
#define FLAG_OPERASION 2

int main(void)
{
    float numeroIngreso1;
    float numeroIngreso2;
    int seguir=1;

    float operaciones[6];
    int flag[4]= {NO_PASO,NO_PASO,NO_PASO,NO_PASO};

    do
    {
        switch (utn_menu())
        {
        case 1:
            ingresoNumero(&numeroIngreso1, "Ingrese el primer operador: ", &flag[FLAG_NUM_1], &flag[FLAG_OPERASION]);
            break;

        case 2:
            ingresoNumero(&numeroIngreso2, "Ingrese el segundo operador: ", &flag[FLAG_NUM_2], &flag[FLAG_OPERASION]);
            break;

        case 3:
            calculos(numeroIngreso1,numeroIngreso2,flag,operaciones);
            break;

        case 4:
            resultados(flag,operaciones);
            break;

        case 5:
            salir(&seguir);
            break;
        }

    }
    while(seguir);

    return 0;
}


