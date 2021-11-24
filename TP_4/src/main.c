/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/utn.h"
#include "../inc/Employee.h"
#include "../inc/parser.h"
#include "../inc/Controller.h"
#define TAM 128


int main()
{

    /*
    	startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
     	startTesting(3);  // getNode - test_getNode
     	startTesting(4);  // addNode - test_addNode
     	startTesting(5);  // ll_add
     	startTesting(6);  // ll_get
     	startTesting(7);  // ll_set
     	startTesting(8);  // ll_remove
     	startTesting(9);  // ll_clear
     	startTesting(10); // ll_deleteLinkedList
     	startTesting(11); // ll_indexOf
     	startTesting(12); // ll_isEmpty
    	startTesting(13); // ll_push
     	startTesting(14); // ll_pop
        startTesting(15); // ll_contains
     	startTesting(16); // ll_containsAll
     	startTesting(17); // ll_subList
    	startTesting(18); // ll_clone
        startTesting(19); // ll_sort
    */

    LinkedList* listaEmpleados;
    LinkedList* listaEmpleadosCaros;
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
            listaEmpleadosCaros=controller_filterSueldo(listaEmpleados);
            break;

        case 11:
            controller_subList(listaEmpleados);
            break;
        case 12:
            if(listaEmpleadosCaros!=NULL)controller_compararSueldoHoras(listaEmpleados,listaEmpleadosCaros);
            else printf("Primero precione la opcion 10");
            break;

        case 13:
            if(listaEmpleadosCaros!=NULL)controller_buscarUnEmpleado(listaEmpleados,listaEmpleadosCaros);
            else printf("Primero precione la opcion 10");
            break;

        case 14:
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
    ll_deleteLinkedList(listaEmpleadosCaros);

    return 0;
}





























