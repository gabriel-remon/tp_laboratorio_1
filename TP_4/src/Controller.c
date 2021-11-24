#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Controller.h"
#include "../inc/LinkedList.h"
#include "../inc/Employee.h"
#include "../inc/parser.h"
#include "../inc/utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *         (saltea la primera linea de valores del archivo)
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE* archivo;
    char vacio[128];
    char nombreArchivo[128];
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        controller_exit(pArrayListEmployee);
        strcat(nombreArchivo,path);
        strcat(nombreArchivo,".csv");
        archivo=fopen(nombreArchivo,"r");
        utn_clear();

        if(archivo!=NULL)
        {
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",vacio,vacio,vacio,vacio);
            parser_EmployeeFromText(archivo,pArrayListEmployee);
            retorno=1;
            printf("archivo cargado con exito");
            fclose(archivo);
        }
        else
        {
            printf("Archivo no encontrado");
        }

    }
    return retorno;

}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE* archivo;
    char nombreArchivo[128];

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        controller_exit(pArrayListEmployee);
        strcat(nombreArchivo,path);
        strcat(nombreArchivo,".bin");
        archivo=fopen(nombreArchivo,"rb");
        utn_clear();

        if(archivo!=NULL)
        {
            parser_EmployeeFromBinary(archivo,pArrayListEmployee);
            retorno=1;
            printf("archivo cargado con exito");
            fclose(archivo);
        }
        else
        {
            printf("Archivo no encontrado");
        }
    }
    return retorno;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee* nuevoEmpleado;
    int newID;

    if(pArrayListEmployee!=NULL )
    {
        nuevoEmpleado=employee_new();
        if(nuevoEmpleado!=NULL)
        {
            newID=ll_len(pArrayListEmployee) + 1;
            employee_setId(nuevoEmpleado,newID);
            employee_ingresoNombre(nuevoEmpleado);
            employee_ingresoHorasTrabajadas(nuevoEmpleado);
            employee_ingresoSueldo(nuevoEmpleado);

            retorno=1;
            ll_add(pArrayListEmployee,nuevoEmpleado);
        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =0;
    int idIngreso;
    Employee empleado;
    int flagIdEncontrado;
    char seguir;

    if(pArrayListEmployee!=NULL && !ll_isEmpty(pArrayListEmployee))
    {
        do
        {
            utn_clear();
            flagIdEncontrado=0;
            controller_ListEmployee(pArrayListEmployee);
            utn_getInt(&idIngreso,"Ingrese una id a modificar","Error, ingrese un numero valido\n");
            flagIdEncontrado=employee_validarId(pArrayListEmployee,idIngreso);
            if(flagIdEncontrado>=0)
            {
                empleado=*((Employee*) ll_get(pArrayListEmployee,flagIdEncontrado));
                do
                {
                    seguir='N';
                    utn_clear();
                    employee_printUno(&empleado);
                    switch(modificacion())
                    {
                    case 1:
                        employee_ingresoNombre(&empleado);
                        break;

                    case 2:
                        employee_ingresoHorasTrabajadas(&empleado);
                        break;

                    case 3:
                        employee_ingresoSueldo(&empleado);
                        break;

                    case 4:
                        utn_confirmar(&seguir,"Desea salir? (Y/N)","Error ingrese 'Y' o 'N'\n",'N','Y');
                        break;
                    }
                    ll_set(pArrayListEmployee,flagIdEncontrado,&empleado);
                }
                while(seguir=='N');
            }
            else
            {
                utn_clear();
                printf("Id ingresado no encontrado\n\n");
            }

            utn_confirmar(&seguir,"Desea ingresar otro ID? (Y/N)","Error ingrese 'Y' o 'N'\n",'N','Y');
        }
        while(seguir=='Y');
    }
    else
    {
        printf("Lista vacia, Primero de de alta un empleado");
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =0;
    int idIngreso;
    Employee* empleado;
    int flagIdEncontrado;
    char seguir;
    char confirmar;

    if(pArrayListEmployee!=NULL && !ll_isEmpty(pArrayListEmployee))
    {
        do
        {
            flagIdEncontrado=0;
            controller_ListEmployee(pArrayListEmployee);
            utn_getInt(&idIngreso,"\nIngrese una id a modificar","Error, ingrese un numero valido");
            flagIdEncontrado=employee_validarId(pArrayListEmployee,idIngreso);
            utn_clear();
            if(flagIdEncontrado>=0)
            {
                empleado=(Employee*) ll_pop(pArrayListEmployee,flagIdEncontrado);
                employee_printUno(empleado);
                utn_confirmar(&confirmar,"Desea dar de baja este empleado? (Y/N)","Error ingrese 'Y' o 'N'\n",'N','Y');

                utn_clear();
                if(confirmar=='Y')
                {
                    employee_delete(empleado);
                    printf("Empleado dado de baja\n\n");
                    if(ll_isEmpty(pArrayListEmployee))goto salir;
                }
                else
                {
                    ll_push(pArrayListEmployee,flagIdEncontrado,empleado);
                    printf("Operacion canselada\n\n");
                }
            }
            else
            {
                printf("Id ingresado no encontrado\n\n");
            }

            utn_confirmar(&seguir,"Desea ingresar otro ID? (Y/N)","Error ingrese 'Y' o 'N'\n",'N','Y');
        }
        while(seguir=='Y');
    }
    else
    {
        printf("Lista vacia, Primero de de alta un empleado");
    }
salir:

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int cantidadElementos;
    Employee* empleado;
    int idAux;
    char nombreAux[128];
    int horasAux;
    int sueldoAux;


    if(pArrayListEmployee!=NULL )
    {
        if(!ll_isEmpty(pArrayListEmployee))
        {
            cantidadElementos=ll_len(pArrayListEmployee);
            printf("id        nombre             horas trabajadas         sueldo\n");
            for(int i=0; i<cantidadElementos; i++)
            {
                empleado=(Employee*) ll_get(pArrayListEmployee,i);
                if(empleado!=NULL)
                {
                    employee_getId(empleado,&idAux);
                    employee_getNombre(empleado,nombreAux);
                    employee_getHorasTrabajadas(empleado,&horasAux);
                    employee_getSueldo(empleado,&sueldoAux);

                    printf("%-6d    %-20s    %-15d     $%-10d \n",
                           idAux,
                           nombreAux,
                           horasAux,
                           sueldoAux
                          );
                }
            }
        }
        else
        {
            printf("La lista esta vacia");
        }
    }


    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    LinkedList* listaAux;
    int (*pOrdenamiento) (void*,void*);
    int orden;

    if(pArrayListEmployee!=NULL && !ll_isEmpty(pArrayListEmployee))
    {
        listaAux=ll_clone(pArrayListEmployee);
        if(listaAux!=NULL)
        {
            switch(menuOrdenar())
            {
            case 1:
                pOrdenamiento=employee_ordenarId;
                break;
            case 2:
                pOrdenamiento=employee_ordenarnombre;
                break;

            case 3:
                pOrdenamiento=employee_ordenarhoras;
                break;
            case 4:
                pOrdenamiento=employee_ordenarsueldo;
                break;
            }
            utn_minMaxInt(&orden,"\nIngrese el orden (0- ASENDENTE / 1-DESCENDENTE): ","Error ingrese solo '0' o '1'",0,1);
            utn_clear();
            ll_sort(listaAux,pOrdenamiento,orden);

            controller_ListEmployee(listaAux);

            ll_clear(listaAux);
            ll_deleteLinkedList(listaAux);
        }

    }
    else
    {
        printf("Primero deve cargar un empleado");
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char nombreArchivo[128]= {};
    int cantidadElementos;
    Employee* empleados;
    FILE* archivo;
    int idAux;
    char nombreAux[128];
    int horasAux;
    int sueldoAux;
    char comfirmar;

    if(path!=NULL && pArrayListEmployee!=NULL && !ll_isEmpty(pArrayListEmployee))
    {
        strcat(nombreArchivo,path);
        strcat(nombreArchivo,".csv");

        archivo=fopen(nombreArchivo,"r");
        utn_clear();

        if(archivo==NULL)
        {
            goto guardar;
        }
        else
        {
            fclose(archivo);
            utn_confirmar(&comfirmar,"\nSe encontro un archivo con ese nombre. Desea sobre escrivirlo? (Y/N): ","Error ingrese 'Y' o 'N'",'Y','N');
            if(comfirmar=='Y')
            {
guardar:
                archivo=fopen(nombreArchivo,"w");
                fprintf(archivo,"Id,Nombre,HorasTrabajadas,Sueldo\n");
                cantidadElementos=ll_len(pArrayListEmployee);
                for(int i=0; i<cantidadElementos; i++)
                {
                    empleados=(Employee*) ll_get(pArrayListEmployee,i);
                    if(empleados!=NULL)
                    {
                        employee_getId(empleados,&idAux);
                        employee_getNombre(empleados,nombreAux);
                        employee_getHorasTrabajadas(empleados,&horasAux);
                        employee_getSueldo(empleados,&sueldoAux);

                        fprintf(archivo,"%d,%s,%d,%d\n",
                                idAux,
                                nombreAux,
                                horasAux,
                                sueldoAux
                               );
                    }
                }
                printf("Archivo guardado con exito\n");
                fclose(archivo);
            }
        }

    }
    else
    {
        printf("Primero deve de dar de alta un empleado");
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char nombreArchivo[128];
    int cantidadElementos;
    char comfirmar;
    Employee* empleados;
    FILE* archivo;

    if(path!=NULL && pArrayListEmployee!=NULL && !ll_isEmpty(pArrayListEmployee))
    {
        strcat(nombreArchivo,path);
        strcat(nombreArchivo,".bin");
        archivo=fopen(nombreArchivo,"r");
        utn_clear();
        if(archivo==NULL)
        {
            goto guardar;
        }
        else
        {
            fclose(archivo);
            utn_confirmar(&comfirmar,"\nSe encontro un archivo con ese nombre. Desea sobre escrivirlo? (Y/N): ","Error ingrese 'Y' o 'N'",'Y','N');
            if(comfirmar=='Y')
            {
guardar:
                archivo=fopen(nombreArchivo,"wb");
                cantidadElementos=ll_len(pArrayListEmployee);
                //fprintf(archivo,"%c",'b');
                for(int i=0; i<cantidadElementos; i++)
                {
                    empleados=(Employee*) ll_get(pArrayListEmployee,i);
                    if(empleados!=NULL)
                    {
                        fwrite(empleados,sizeof(Employee),1,archivo);
                    }
                }
                printf("Archivo guardado con exito\n");
                fclose(archivo);
            }
        }
    }
    else
    {
        printf("Primero deve de dar de alta un empleado");
    }


    return retorno;
}

void controller_exit(LinkedList* pArrayListEmployee)
{
    int cantidadElementos;
    Employee* empleado;

    if(pArrayListEmployee!=NULL)
    {
        cantidadElementos=ll_len(pArrayListEmployee);
        for(int i=0; i<cantidadElementos; i++)
        {
            empleado=(Employee*) ll_get(pArrayListEmployee,i);
            if(empleado!=NULL)
            {
                employee_delete(empleado);
            }
        }
        ll_clear(pArrayListEmployee);
    }

}

int menu()
{
    int retorno;

    printf("-----------------REGISTROS DE EMPLEADOS---------------\n\n");

    printf("1- CARGAR ARCHIVO (formato texto)       \n");
    printf("2- CARGAR ARCHIVO (formato binario)   \n\n");
    printf("3- ALTA DE EMPLEADOS                    \n");
    printf("4- MODIFICAR UN EMPLEADO                \n");
    printf("5- BAJA DE EMPLEADOS                    \n");
    printf("6- LISTA DE EMPLEADOS                   \n");
    printf("7- LISTA DE EMPLEADOS (ordenados)     \n\n");
    printf("8- GUARDAR EN ARCHIVO (formato texto)   \n");
    printf("9- GUARDAR EN ARCHIVO (formato binario) \n");
    printf("10- FILTRAR SUELDOS MAYORES A 40.000    \n");
    printf("11- CREAR LISTA DEL ID 200 AL 400       \n");
    printf("12- COMPARA EMPLEADOS CON SUELDO Y HORAS\n");
    printf("13- PREGUNTA EMPLEADO SUELDO CARO   \n\n\n");


    printf("14-SALIR                             \n\n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 10",1,14);
    utn_clear();
    return retorno;
}
int menuOrdenar()
{
    int retorno;

    printf("-----------------ORDENAMIENTO DE EMPLEADOS---------------\n\n");

    printf("1- ORDENAR POR ID\n");
    printf("2- ORDENAR POR NOMBRE\n");
    printf("3- ORDENAR POR HORAS TRABAJADAS\n");
    printf("4- ORDENAR POR SUELDO\n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 4",1,4);
    utn_clear();
    return retorno;
}

LinkedList* controller_filterSueldo(LinkedList* pArrayListEmployee)
{
    LinkedList* listaFiltrada=NULL;
    char archivo[128];

    if(pArrayListEmployee!=NULL)
    {
        if(!ll_isEmpty(pArrayListEmployee))
        {
            listaFiltrada=ll_filter(pArrayListEmployee,employee_filterSueldo);
            if(ll_isEmpty(listaFiltrada)==0)
            {
                utn_ingresoScring(archivo,"Ingrese el nombre como se guardara: ","Error\n",128);
                controller_saveAsText(archivo,listaFiltrada);
            }
            else
            {
                printf("No se encontraron datos compatibles");
            }
        }
        else
        {
            printf("primero deve ingresar datos");
        }
    }

    return listaFiltrada;
}


int controller_subList(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    LinkedList* nuevalista;
    char archivo[128];

    if(pArrayListEmployee!=NULL)
    {
        if(ll_len(pArrayListEmployee)>400)
        {
            nuevalista=ll_subList(pArrayListEmployee,200,400);
            if(nuevalista!=NULL)
            {
                utn_ingresoScring(archivo,"Ingrese el nombre del archivo de destino","Error\n",128);
                controller_saveAsText(archivo,nuevalista);
                ll_deleteLinkedList(nuevalista);
            }
            else
            {
                printf("error al crear la lista");
            }

        }
        else
        {
            printf("Lista demasiado chica");
        }
        retorno=1;
    }

    return retorno;
}

int controller_compararSueldoHoras(LinkedList* pArrayListEmployee,LinkedList* lista2)
{
    int retorno=0;
    LinkedList* lista3;

    if(pArrayListEmployee!=NULL && lista2!=NULL)
    {

        if(!ll_isEmpty(pArrayListEmployee))
        {
            lista3=ll_filter(pArrayListEmployee,employee_filterHoras);
            if(lista3!=NULL)
            {
                if(ll_containsAll(lista3,lista2))
                {
                    printf("Todos los empleados que cobran mas de 40.000 trabajan mas de 130 horas");
                }
                else
                {
                    printf("No todos los empleados que ganan mas tabajan mas de 130 horas");
                }

            }
            else
            {
                printf("No se pudo crear la lista ");
            }

        }
        else
        {
            printf("Lista vacia, ingrese al menos un empleado");
        }
        retorno=1;
    }

    return retorno;
}

int controller_buscarUnEmpleado(LinkedList* pArrayListEmployee,LinkedList* lista2)
{

    int retorno =0;
    int idIngreso;
    Employee* empleado;
    int flagIdEncontrado;
    char seguir;

    if(pArrayListEmployee!=NULL && !ll_isEmpty(pArrayListEmployee) && lista2!=NULL)
    {
        do
        {
            flagIdEncontrado=0;
            controller_ListEmployee(pArrayListEmployee);
            utn_getInt(&idIngreso,"\nIngrese una id de un empleado","Error, ingrese un numero valido");
            flagIdEncontrado=employee_validarId(pArrayListEmployee,idIngreso);
            utn_clear();
            if(flagIdEncontrado>=0)
            {
                empleado=(Employee*) ll_get(pArrayListEmployee,flagIdEncontrado);
                employee_printUno(empleado);
                controller_ListEmployee(lista2);

                if(ll_contains(lista2,empleado))
                {
                    printf("\nEl empleado esta dentro del grupo Caro");
                }
                else
                {
                    printf("\nEl empleado tiene un sueldo economico");
                }
                printf("\n\n");
            }
            else
            {
                printf("Id ingresado no encontrado\n\n");
            }

            utn_confirmar(&seguir,"Desea ingresar otro ID? (Y/N)","Error ingrese 'Y' o 'N'\n",'N','Y');
        }
        while(seguir=='Y');
    }
    else
    {
        printf("Lista vacia, Primero de de alta un empleado");
    }

    return retorno;

}
