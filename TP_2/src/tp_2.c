/*
 ============================================================================
 Name        : TP_2
 Author      : gabriel Remon
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
	setbuf (stdout, NULL);
    eEmployee nomina[TAM];
    int asignacionId=2000;
    char seguir='n';

    initEmployees(nomina,TAM);
    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(nomina,TAM, &asignacionId);
            break;

        case 2:
            modificacionEmpleado(nomina,TAM);
            break;

        case 3:
            bajaEmpleado(nomina,TAM);
            break;

        case 4:
            printEmployees(nomina,TAM);
            break;

        case 5:
            utn_getCharDos(&seguir, "Esta seguro que desea salir (y/n)?", "Error ingrese 'y' o 'n'\n", 'y','n');
            break;
        }

        utn_stop();
        utn_clear();
    }while(seguir=='n');

    return EXIT_SUCCESS;
}
