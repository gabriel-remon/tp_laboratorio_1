/*
 * utn.c
 *
 *      Autor: Gabriel Remon
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

int utn_minMax(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo)
{
    int retorno = -1;
    float bufferIn;
    int error;

    if(pResultado != NULL && pMensaje!= NULL && pMensajeError!= NULL && minimo<maximo)
    {
        while(1)
        {
            printf("%s ", pMensaje);
            __fpurge(stdin);
            error = scanf("%f", &bufferIn);
            if(bufferIn>=minimo && bufferIn<=maximo && error == 1)
            {
                *pResultado = bufferIn;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s ", pMensajeError);
            }
        }
    }
    return retorno;
}

int utn_operador(char tipoOperador,float* pResultado, float num1, float num2)
{

    float resultado;
    int retorno = -1;

    if(pResultado != NULL && (tipoOperador=='+' || tipoOperador=='-' || tipoOperador=='*' || tipoOperador=='/'))
    {
        switch(tipoOperador)
        {
            case '+':
                resultado=num1+num2;
                retorno = 0;
                break;

            case '-':
                resultado=num1-num2;
                retorno = 0;
                break;

            case '*':
                resultado=num1*num2;
                retorno = 0;
                break;

            case '/':
                if(num2!=0)
                {
                    resultado=num1/num2;
                    retorno=0;
                }
                else
                {
                    retorno=1;
                }
                break;
        }
        *pResultado = resultado;
    }

    return retorno;

}

int utn_factorial( int num)
{
    int retorno;
    if(num==0)
    {
        retorno= 1;
    }
    else
    {
        retorno=num * utn_factorial(num-1);
    }
    return retorno;
}

void utn_clear()
{
    system("clear");
    //system("@cls||clear");
}

void utn_stop()
{
    printf("\n\nPrecione Enter para continuar");
    __fpurge(stdin);
    getchar();
}



