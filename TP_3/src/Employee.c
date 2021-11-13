#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new()
{
    Employee* empleadoAux=NULL;

    empleadoAux=(Employee*) malloc(sizeof(Employee));

    return empleadoAux;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpleado=NULL;
    nuevoEmpleado=employee_new();

    if(nuevoEmpleado!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {

        if(esNumerica(idStr))
        {
            //  idAux=atoi(idStr);
            employee_setId(nuevoEmpleado,atoi(idStr));
        }

        employee_setNombre(nuevoEmpleado,nombreStr);
        if(esNumerica(horasTrabajadasStr))
        {

            employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr));
        }
        if(esNumerica(sueldoStr))
        {

            employee_setSueldo(nuevoEmpleado,atoi(sueldoStr));
        }

    }

    return nuevoEmpleado;
}

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int employee_validarId(LinkedList* lista, int id)
{
    int retorno=-1;
    int idGuardada;
    int cantidadEmpleados;
    Employee* empleado;

    if(lista!=NULL)
    {
        cantidadEmpleados=ll_len(lista);
        for(int i=0; i<cantidadEmpleados; i++)
        {
            empleado = (Employee*) ll_get(lista,i);
            if(empleado!=NULL)
            {
                employee_getId(empleado,&idGuardada);
                if(idGuardada==id)
                {
                    retorno=i;
                    break;
                }

            }
        }
    }

    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno=0;

    if(this!=NULL )
    {
        this->id=id;
        retorno=1;
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=0;

    if(this!=NULL && id!=NULL)
    {
        *id= this->id;
        retorno=1;
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL )
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL )
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL )
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=1;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=1;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;

    if(this!=NULL )
    {
        this->sueldo=sueldo;
        retorno=1;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=1;
    }

    return retorno;
}


void employee_printUno(Employee* this)
{
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(this !=NULL)
    {
        employee_getId(this,&id);
        employee_getNombre(this,nombre);
        employee_getHorasTrabajadas(this,&horas);
        employee_getSueldo(this,&sueldo);
        printf("ID: %d \nnombre: %s \nhoras trabajadas: %d \nSueldo: $%d\n\n",
               id,
               nombre,
               horas,
               sueldo
              );
    }
}

int modificacion()
{
    int retorno;

    printf("\n\n-----------------MODIFICAR EMPLEADOS---------------\n\n");

    printf("1- MODIFICAR NOMBRE Y APELLIDO\n");
    printf("2- MODIFICAR HORAS TRABAJADAS\n");
    printf("3- MODIFICAR SUELDO\n\n");

    printf("4-SALIR\n\n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 4",1,4);
    utn_clear();
    return retorno;
}


int employee_ingresoNombre(Employee* this)
{
    int retorno=0;
    char nombreIngreso[64];
    char apellidoIngreso[63];
    char nombreApellido[128];
    if(this!=NULL)
    {
        do
        {
            utn_ingresoScring(nombreIngreso,"Ingrese nombre: ", "error\n",64);
        }
        while(utn_validarNombre(nombreIngreso,64));
        do
        {
            utn_ingresoScring(apellidoIngreso,"Ingrese apellido: ", "error\n",63);
        }
        while(utn_validarNombre(apellidoIngreso,63));
        snprintf(nombreApellido,128,"%s %s",nombreIngreso,apellidoIngreso);
        employee_setNombre(this,nombreApellido);
        retorno=1;
    }

    return retorno;
}
int employee_ingresoHorasTrabajadas(Employee* this)
{
    int retorno=0;

    int horasIngreso;
    if(this!=NULL)
    {

        utn_minMaxInt(&horasIngreso,"Ingrese las horas trabajadas: ","Error ingrese un numero entre 1 y 8640\n",1,8640);
        employee_setHorasTrabajadas(this,horasIngreso);
        retorno=1;
    }

    return retorno;
}
int employee_ingresoSueldo(Employee* this)
{
    int retorno=0;
    int sueldoIngreso;

    if(this!=NULL)
    {
        utn_minMaxInt(&sueldoIngreso,"Ingrese su sueldo: $","Error ingrese un numero valido",1,1000000000);
        employee_setSueldo(this,sueldoIngreso);
        retorno=1;
    }

    return retorno;
}

int employee_ordenarId(void* primerParametro,void* segundoParametro)
{
    int retorno=0;
    Employee* empleado1;
    Employee* empleado2;
    int a;
    int b;

    if(primerParametro!=NULL && segundoParametro!=NULL)
    {
        empleado1 = (Employee*) primerParametro;
        empleado2 = (Employee*) segundoParametro;
        employee_getId(empleado1,&a);
        employee_getId(empleado2,&b);

        if(a>b)
        {
            retorno=1;
        }
        else
        {
            if(a<b)
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}

int employee_ordenarnombre(void* primerParametro,void* segundoParametro)
{
    int retorno=0;
    Employee* empleado1;
    Employee* empleado2;
    char a[128];
    char b[128];

    if(primerParametro!=NULL && segundoParametro!=NULL)
    {
        empleado1 = (Employee*) primerParametro;
        empleado2 = (Employee*) segundoParametro;
        employee_getNombre(empleado1,a);
        employee_getNombre(empleado2,b);
        retorno=strncasecmp(a,b,128);
        if(retorno>0)
        {
            retorno=1;
        }
        else
        {
            if(retorno<0)
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}

int employee_ordenarhoras(void* primerParametro,void* segundoParametro)
{
    int retorno=0;
    Employee* empleado1;
    Employee* empleado2;
    int a;
    int b;

    if(primerParametro!=NULL && segundoParametro!=NULL)
    {
        empleado1 = (Employee*) primerParametro;
        empleado2 = (Employee*) segundoParametro;
        employee_getHorasTrabajadas(empleado1,&a);
        employee_getHorasTrabajadas(empleado2,&b);

        if(a>b)
        {
            retorno=1;
        }
        else
        {
            if(a<b)
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}

int employee_ordenarsueldo(void* primerParametro,void* segundoParametro)
{
    int retorno=0;
    Employee* empleado1;
    Employee* empleado2;
    int a;
    int b;

    if(primerParametro!=NULL && segundoParametro!=NULL)
    {
        empleado1 = (Employee*) primerParametro;
        empleado2 = (Employee*) segundoParametro;
        employee_getSueldo(empleado1,&a);
        employee_getSueldo(empleado2,&b);
        if(a>b)
        {
            retorno=1;
        }
        else
        {
            if(a<b)
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}


