#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Employee.h"
#define TAM_AUX 128

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    //int contador=0;
    char idTxt[TAM_AUX];
    char nombreTxt[TAM_AUX];
    char horasTxt[TAM_AUX];
    char sueldoTxt[TAM_AUX];
    int validacion;
    Employee* nuevoEmpleado;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
            validacion=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                              idTxt,
                              nombreTxt,
                              horasTxt,
                              sueldoTxt
                             );
            if(validacion==4)
            {
                nuevoEmpleado=employee_newParametros(idTxt,nombreTxt,horasTxt,sueldoTxt);
                if(nuevoEmpleado!=NULL)
                {
                    ll_add(pArrayListEmployee,nuevoEmpleado);
                    retorno++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }

        }
        while(!feof(pFile));
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int validacion;
    //int idAux;
    //char nombreAux[TAM_AUX];
    //int horasAux;
    //int sueldoAux;
    Employee* nuevoEmpleado;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
            nuevoEmpleado=employee_new();
            if(nuevoEmpleado!=NULL)
            {
                validacion=fread(nuevoEmpleado,sizeof(Employee),1,pFile);

                if(validacion==1)
                {
                    ll_add(pArrayListEmployee,nuevoEmpleado);
                }

            }
            /*
            employee_setId(nuevoEmpleado,idAux);
            employee_setNombre(nuevoEmpleado,nombreAux);
            employee_setHorasTrabajadas(nuevoEmpleado,horasAux);
            employee_setSueldo(nuevoEmpleado,sueldoAux);
            ll_add(pArrayListEmployee,nuevoEmpleado);
            */
        }
        while(!feof(pFile));
    }

    return retorno;
}
