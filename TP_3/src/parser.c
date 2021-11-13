#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
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

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
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
        }
        while(!feof(pFile));
    }

    return retorno;
}
