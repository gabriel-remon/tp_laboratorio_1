/*
 ============================================================================
 Name        : TP_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "LinkedList.h"
#define TAM 128


int main()
{
    LinkedList* listaEmpleados;
    int flagListaGuardada=0;
    int flagHayDatos=0;
    char salir='N';
    char confirmar;
    char nombreArchivo[TAM];

    listaEmpleados=ll_newLinkedList();
    if(listaEmpleados==NULL)
    {
        printf("No hay espacio en memoria para iniciar el programa\n\n");
        exit(1);
    }

    do
    {
        switch(menu())
        {
        case 1:
            if(flagHayDatos)
            {
                utn_confirmar(&confirmar,"Se borraran los datos cargados. Desea continuar? (Y/N)","Error\n",'Y','N');
                utn_clear();
                if(confirmar=='N') continue;
            }
            utn_ingresoScring(nombreArchivo,"Ingrese el archivo de texto que desea leer (sin el .csv): ","Error\n",TAM);
            if(controller_loadFromText(nombreArchivo,listaEmpleados) && !flagHayDatos)flagHayDatos=1;
            flagListaGuardada=0;
            break;

        case 2:
            if(flagHayDatos)
            {
                utn_confirmar(&confirmar,"Se borraran los datos cargados. Desea continuar? (Y/N)","Error\n",'Y','N');
                utn_clear();
                if(confirmar=='N') continue;
            }
            utn_ingresoScring(nombreArchivo,"Ingrese el archivo de texto que desea leer (sin el .bin): ","Error\n",TAM);
            if(controller_loadFromBinary(nombreArchivo,listaEmpleados)&& !flagHayDatos)flagHayDatos=1;
            flagListaGuardada=0;
            break;

        case 3:
            controller_addEmployee(listaEmpleados);
            flagHayDatos=1;
            break;

        case 4:
            controller_editEmployee(listaEmpleados);
            break;

        case 5:
            controller_removeEmployee(listaEmpleados);
            break;

        case 6:
            controller_ListEmployee(listaEmpleados);
            break;

        case 7:
            controller_sortEmployee(listaEmpleados);
            break;

        case 8:
            utn_ingresoScring(nombreArchivo,"Ingrese el nombre del archivo de texto (sin el .csv)","Error \n",TAM);
            controller_saveAsText(nombreArchivo,listaEmpleados);
            if(!flagListaGuardada)  flagListaGuardada=1;
            break;

        case 9:
            utn_ingresoScring(nombreArchivo,"Ingrese el nombre del archivo binario (sin el .bin)","Error \n",TAM);
            controller_saveAsBinary(nombreArchivo,listaEmpleados);
            if(!flagListaGuardada)  flagListaGuardada=1;
            break;

        case 10:
            if(!flagListaGuardada) printf("WARNING, no guardo los cambios\n\n");
            utn_confirmar(&salir,"Esta seguro que desea salir?(Y/N)","Error ingrese (Y/N)",'Y','N');
            break;

        }

        utn_stop();
        utn_clear();
    }
    while(salir=='N');

    controller_exit(listaEmpleados);
    ll_deleteLinkedList(listaEmpleados);
    return EXIT_SUCCESS;
}
