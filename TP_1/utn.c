/*
 * utn.c
 *
 *  Created on: 24 sep. 2021
 *      Author: linux
 */
#include <stdio.h>
#include <stdlib.h>
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



int utn_convercionTemp(float* pResultado, int temp, int tipo)
{
    int retorno = -1;
    float resultado;

    if(pResultado != NULL)
    {
        if(tipo == 0) //si de celcus a farengeit
        {
            resultado = (float) (temp * 9)/5 + 32;
        }
        else
        {
            resultado = (float) ((temp-32)*5)/9;
        }

        *pResultado = resultado;
        retorno=0;
    }
    return retorno;
}



int utn_getInt(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int intentos)
{
    int retorno = -1;
    int bufferIn;
    int error;

    if(pResultado != NULL && pMensaje!= NULL && pMensajeError!= NULL && minimo<maximo && intentos >= 0)
    {
        do
        {
            printf("%s ", pMensaje);
            __fpurge(stdin);
            error = scanf("%d", &bufferIn);
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
            intentos--;
        }while(intentos>=0);
    }
    return retorno;
}


int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int intentos)
{
    int retorno = -1;
    float bufferIn;
    int error;

    if(pResultado != NULL && pMensaje!= NULL && pMensajeError!= NULL && minimo<maximo && intentos >= 0)
    {
        do
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
            intentos--;
        }while(intentos>=0);
    }
    return retorno;
}

int utn_getChar(char* pResultado, char* pMensaje, char* pMensajeError, char minimo, char maximo, int intentos)
{
    int retorno = -1;
    char bufferIn;
    int error;

    if(pResultado != NULL && pMensaje!= NULL && pMensajeError!= NULL && minimo<maximo && intentos >= 0)
    {
        do
        {
            printf("%s ", pMensaje);
            __fpurge(stdin);
            error = scanf("%c", &bufferIn);
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
            intentos--;
        }while(intentos>=0);
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

int utn_inputNum(int* pResultado, char* pMensaje, char* pMensajeError)
{
    int numInput;
    int retorno = -1;
    int error;

    if(pResultado!= NULL && pMensaje!=NULL && pMensajeError!=NULL)
    {
        do
        {
            printf("%s", pMensaje);
            __fpurge(stdin);
            error = scanf("%d", &numInput);
            if(error!=0)
            {
                *pResultado = numInput;
                retorno=0;
                break;
            }
            else
            {
                printf("\n%s", pMensajeError);
            }
        }while(1);
    }

    return retorno;

}

void utn_clear()
{
	printf("\n\n\n\n\n\n\n\n\n");
   // system("clear");
    //system("@cls||clear");
}


void utn_stop()
{
    printf("\n\nPrecione Enter para continuar");
    __fpurge(stdin);
    getchar();
}



