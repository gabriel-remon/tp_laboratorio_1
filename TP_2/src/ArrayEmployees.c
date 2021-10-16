/*
 *      Author: Gabriel Remon
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

static void listaEmpleados(eEmployee vec[], int tam, char* texto,int orden);
/** Imprime una lista de los datos guardados dentro de la variable vec[] ordenandolos de manera asendente o desendente
* parametro vec[] eEmployee
* parametro tam int tamaño maximo de la variable vec
* parametro texto char* texto que aparecera antes de la lista de valores
* parametro orden int determina el orden asendente [1] o desendente [0]
*
*/

static void errorfaltaDato();
/** Limpia consola y muestra un mensaje de error
*/

static int modificacion();
/** Menu de opciones
*
* retorna int el cual sera un valor entre 1 y 5
*/

static void listaEmpleados(eEmployee vec[], int tam, char* texto,int orden)
{
    if(vec!=NULL && texto!=NULL && (orden==1 || orden==0))
    {
        utn_clear();
        printf("%s\n\n",texto);
        sortEmployees(vec,tam,orden);

        printf("-----------------Lista de empleados----------------- \n\n");
        printf("Id       Nombre         Apellido        Sueldo             Sector\n");
        for(int i=0; i<tam; i++)
        {
            if( !(vec[i].isEmpty) )
            {
                printf("%d     %-10s     %-13s   $%-13.2f     %d\n",
                       vec[i].id,
                       vec[i].name,
                       vec[i].lastName,
                       vec[i].salary,
                       vec[i].sector);
            }
        }
        printf("\n\n");
    }
}

static void errorfaltaDato()
{
    utn_clear();
    printf("Primero deve ingresar un empleado");
}

static int modificacion()
{
    int retorno;

    printf("1-Nombre\n");
    printf("2-Apellido\n");
    printf("3-Sueldo\n");
    printf("4-Sector\n");
    printf("5-Salir \n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 5",1,5);

    utn_clear();
    return retorno;

}

int initEmployees(eEmployee vec[], int tam)
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            vec[i].isEmpty=VACIO;
        }
        retorno=0;
    }

    return retorno;
}

int menu()
{
    int retorno;

    printf("-----------------Registro de empleados---------------\n\n");

    printf("1- ALTAS\n");
    printf("2- MODIFICAR\n");
    printf("3-BAJA\n");
    printf("4-INFORMAR\n");
    printf("5-SALIR\n\n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 5",1,5);
    return retorno;
}



int altaEmpleado(eEmployee vec[], int tam, int* id)
{
    int retorno=-1;
    int posicion;
    char nombreAux[51];
    char apellidoAux[51];
    float sueldoAux;
    int sectorAux;
    char exit;

    if(vec!=NULL && tam>0 && id!=NULL)
    {
        do
        {
            utn_clear();

            posicion=espacioLibre(vec,tam);
            if(posicion==-2)
            {
                posicion=0;
            }
            if(posicion>=0)
            {
            	do
            	{
                utn_ingresoScring(nombreAux, "Ingrese el nombre del empleado: ", "Error (maximo 50 caracteres), ", 51);
            	}while(esPalabra(nombreAux,51));

            	do
            	{
            	utn_ingresoScring(apellidoAux, "Ingrese el apellido del empleado: ", "Error (maximo 50 caracteres), ", 51);
            	}while(esPalabra(apellidoAux,51));

            	utn_getFloat(&sueldoAux, "Ingrese el salario del empleado: ","Error, ");
                utn_getInt(&sectorAux, "Ingrese el sector donde estara el empleado: ", "Error, ");

                addEmployees(vec,tam,(*id),nombreAux,apellidoAux,sueldoAux,sectorAux);

                (*id)++;
                printf("Empleado cargado con exito\n");
                utn_getCharDos(&exit,"\nDesea dar de alta otro empleado?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');

                retorno=0;
            }
            else
            {
                printf("No hay espacio para cargar mas empleados.\nPara hacerlo deve dar de baja a un empleado actual.");
                exit='n';
                retorno=1;
            }
        }
        while(exit=='y');
    }
    return retorno;
}

int addEmployees(eEmployee vec[], int tam, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno=-1;
    int posicion;

    if(vec!=NULL && name!=NULL && lastName!=NULL && tam>0)
    {
        posicion=espacioLibre(vec,tam);
        if(posicion==-2)
        {
            posicion=0;
        }
        vec[posicion].id=id;
        strcpy(vec[posicion].name,name);
        strcpy(vec[posicion].lastName,lastName);
        vec[posicion].salary=salary;
        vec[posicion].sector=sector;
        vec[posicion].isEmpty=OCUPADO;

        retorno=0;
    }

    return retorno;
}

int espacioLibre(eEmployee vec[], int tam)
{
    int retorno=-1;
    int flagEspacioLibre=1;
    int contadorLibres=0;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty && flagEspacioLibre)
            {
                retorno=i;
                flagEspacioLibre=0;
            }
            if(vec[i].isEmpty)
            {
                contadorLibres++;
            }
        }
        if(contadorLibres==tam)
        {
            retorno=-2;
        }
    }

    return retorno;
}

int modificacionEmpleado(eEmployee vec[], int tam)
{
    int retorno=-1;
    int posicion;
    char exit='n';
    int id;

    if(vec!=NULL && tam>0)
    {
        if(espacioLibre(vec,tam) != -2)
        {
            do
            {
                listaEmpleados(vec,tam,"******** MODIFICACION DE EMPLEADOS ********",1);

                utn_getInt(&id, "Ingrese el id del empleado a modificar: ","Error id invalido, ");
                posicion=findEmployeeById(vec,tam,id);
                if(posicion>=0)
                {
                    do
                    {
                        utn_clear();
                        printf("Datos del empleado:\n\n");
                        printf("Id: %d \nNombre: %s \nApellido: %s \nSalario: %.2f$ \nSector: %d \n\n",
                               vec[posicion].id,
                               vec[posicion].name,
                               vec[posicion].lastName,
                               vec[posicion].salary,
                               vec[posicion].sector
                              );

                        switch(modificacion())
                        {
                        case 1:
                        	do
                        	{
                            utn_ingresoScring(vec[posicion].name, "Ingrese el nombre del empleado: ", "Error (maximo 50 caracteres), ", 51);
                        	}while(esPalabra(vec[posicion].name, 51));
                            printf("\nNombre cambiado correctamente\n");
                            break;

                        case 2:
                        	do
                        	{
                            utn_ingresoScring(vec[posicion].lastName, "Ingrese el apellido del empleado: ", "Error (maximo 50 caracteres), ", 51);
                        	}while(esPalabra(vec[posicion].lastName,51));
                            printf("\nApellido cambiado correctamente\n");
                            break;

                        case 3:
                            utn_getFloat(&vec[posicion].salary, "Ingrese el salario del empleado: ","Error, ");
                            printf("\nSueldo cambiado correctamente\n");
                            break;

                        case 4:
                            utn_getInt(&vec[posicion].sector, "Ingrese el sector donde estara el empleado: ", "Error, ");
                            printf("\nSector cambiado correctamente\n");
                            break;

                        case 5:
                            utn_getCharDos(&exit, "Esta seguro que desea salir (y/n)?", "Error ingrese 'y' o 'n'\n", 'y','n');
                            break;
                        }
                        utn_stop();
                    }
                    while(exit=='n');
                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
            }
            while(exit=='y');
        }
        else
        {
            errorfaltaDato();
        }
        retorno=0;
    }

    return retorno;
}


int findEmployeeById(eEmployee vec[], int tam, int id)
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].id==id && !(vec[i].isEmpty))
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


int bajaEmpleado(eEmployee vec[], int tam)
{
    int retorno=-1;
    int posicion;
    char confirm;
    char exit='y';
    int idInput;

    if(vec!=NULL && tam>0)
    {
        if(espacioLibre(vec,tam)!=-2)
        {
            do
            {
                listaEmpleados(vec,tam,"******** BAJA DE EMPLEADOS ********",1);

                utn_getInt(&idInput, "Ingrese el id del empleado a dar de baja: ","Error id invalido, ");
                posicion=findEmployeeById(vec,tam,idInput);

                if(posicion>=0)
                {
                    utn_clear();
                    printf("Datos del empleado:\n\n");
                    printf("Id: %d \nNombre: %s \nApellido: %s \nSalario: %.2f$ \nSector: %d \n",
                           vec[posicion].id,
                           vec[posicion].name,
                           vec[posicion].lastName,
                           vec[posicion].salary,
                           vec[posicion].sector
                          );

                    utn_getCharDos(&confirm,"\nConfirmar la baja de este empleado(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
                    utn_clear();
                    if(confirm=='y')
                    {
                        removeEmployee(vec, tam, posicion);
                        printf("Empleado dado de baja");
                    }
                    else
                    {
                        printf("Se cancelo la operacion");
                    }
                }
                else
                {
                    printf("\nId no encontrado\n");
                }

                if(espacioLibre(vec,tam)!=-2)
                {
                    utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
                }
                else
                {
                    break;
                }

            }
            while(exit=='y');
        }
        else
        {
            errorfaltaDato();
        }
        retorno=0;
    }

    return retorno;
}

int removeEmployee(eEmployee vec[], int tam, int id)
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        vec[id].isEmpty=VACIO;
        retorno=0;
    }

    return retorno;
}



void printEmployees(eEmployee vec[], int tam)
{
    int cantidadEmpleados=0;
    float totalSalario=0;
    float promedioSalarios;
    int superaPromedio=0;
    int orden;

    if(vec!=NULL && tam>0)
    {
        if(espacioLibre(vec,tam)!=-2)
        {
            utn_clear();
            utn_minMaxInt(&orden, "Ingrese 1 para ordenar de forma asendente.\nIngrese 0 para ordenar de forma desendente","Error, Ingrese unicamente 1 o 0 \n", 0,1);
            sortEmployees(vec, tam, orden);
            utn_clear();
            listaEmpleados(vec,tam,"",orden);

            for(int i=0; i<tam; i++)
            {
                if( !(vec[i].isEmpty) )
                {
                    totalSalario=totalSalario+vec[i].salary;
                    cantidadEmpleados++;
                }
            }

            promedioSalarios=totalSalario/cantidadEmpleados;
            for(int i=0; i<tam; i++)
            {
                if( !(vec[i].isEmpty) && vec[i].salary>promedioSalarios)
                {
                    superaPromedio++;
                }
            }

            printf("\nTotal de empleados: %d \nPromedio de sueldos: $%.2f\n", cantidadEmpleados, promedioSalarios);
            printf("Hay %d empleados que superan el salario promedio", superaPromedio);
        }
        else
        {
            errorfaltaDato();
        }
    }
}

int sortEmployees(eEmployee vec[], int tam, int orden)
{
    int retorno=-1;
    int comparadorApellido;
    eEmployee aux;

    if(vec!=NULL && tam>0 && (orden==1 || orden==0))
    {
        for(int i=0; i<tam-1; i++)
        {
            if(vec[i].isEmpty)
            {
                continue;
            }
            for(int j=i+1; j<tam; j++)
            {
                comparadorApellido=strncasecmp(vec[i].lastName, vec[j].lastName, 51);
                if( !(vec[j].isEmpty) &&
                        (((comparadorApellido>0 || (comparadorApellido==0 && vec[i].sector>vec[j].sector)) && orden) ||
                         ((comparadorApellido<0 || (comparadorApellido==0 && vec[i].sector<vec[j].sector)) && !orden)
                        ))
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }

        retorno=0;
    }

    return retorno;
}
