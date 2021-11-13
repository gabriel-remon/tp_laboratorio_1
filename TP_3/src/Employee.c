#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Reserva espacio en memoria dinamica para un elemento Employee
 *
 * \param Employee*
 *
 */

Employee* employee_new()
{
    Employee* empleadoAux=NULL;

    empleadoAux=(Employee*) malloc(sizeof(Employee));

    return empleadoAux;
}

/** \brief Recive todos los parametros de la estructura Employee como char, los combierte a
 * 		   su tipo de dato correspondiente, luego reserva lugar en memoria dinamica y los guarda
 *
 * \param idStr char*
 * \param idStr char*
 * \param idStr char*
 * \param idStr char*
 *
 * \return Employee*
 *
 */
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

/** \brief Libera la memoria reservada del puntero this
 *
 * \param this Employee*
 *
 */
void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

/** \brief busca en linkedList si un elemento coincide con el id pasado como parametro
 *
 * \param lista LinkedList*
 * \param id int
 *
 * return int
 *
 */
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

/** \brief Guarda id en puntero this.id
 *
 * \param this Employee*
 * \param id int
 *
 * return int
 *
 */
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

/** \brief Carga en el valor *id en this.id
 *
 * \param this Employee*
 * \param id int*
 *
 * return int
 *
 */
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
/** \brief copia el string nombre en this.nombre
 *
 * \param this Employee*
 * \param nombre char*
 *
 * return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL )
    {
    	for(int i=0; (*(nombre+i))!='\0' ;i++)
    	{
    		if(*(nombre+i)=='-')
    		{
    			*(nombre+i)=32;
    		}
    	}
        strcpy(this->nombre,nombre);
        retorno=1;
    }

    return retorno;
}

/** \brief Copia el string de this.nombre hacia nombre
 *
 * \param this Employee*
 * \param nombre char*
 *
 * return int
 *
 */
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

/** \brief Carga carga la bariable horasTrabajadas en this.horasTrabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 *
 * return int
 *
 */
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

/** \brief Carga en *horasTrabajadas el valor en this.horasTrabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 *
 * return int
 *
 */
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
/** \brief Carga la variable sueldo en this.sueldo
 *
 * \param this Employee*
 * \param sueldo int
 *
 * return int
 *
 */
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

/** \brief Carga en el valor de *sueldo el dato en this.sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 *
 * return int
 *
 */
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

/** \brief Muestra los valores dentro de this en forma de columna
 *
 * \param this Employee*
 *
 */
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

/** \brief Pide al usuario nombre y apellido, los valida y guarda en this.nombre
 *
 * \param this Employee*
 *
 * return int
 *
 */
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

/** \brief Pide al usuario horas trabajadas, los valida y guarda en this.horasTrabajadas
 *
 * \param this Employee*
 *
 * return int
 *
 */
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

/** \brief Pide al usuario sueldo, valida y guarda en horas trabajadas
 *
 * \param this Employee*
 *
 * return int
 *
 */
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

/** \brief compara los valores Employee.id en los dos punteros
 *
 * \param primerParametro Employee*
 * \param segundoParametro Employee*
 *
 * return int
 *
 */
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

/** \brief compara los valores Employee.nombre en los dos punteros
 *
 * \param primerParametro Employee*
 * \param segundoParametro Employee*
 *
 * return int
 *
 */

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

/** \brief compara los valores Employee.horasTrabajadas en los dos punteros
 *
 * \param primerParametro Employee*
 * \param segundoParametro Employee*
 *
 * return int
 *
 */
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

/** \brief compara los valores Employee.sueldo en los dos punteros
 *
 * \param primerParametro Employee*
 * \param segundoParametro Employee*
 *
 * return int
 *
 */
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


