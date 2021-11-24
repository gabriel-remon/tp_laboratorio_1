#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;


#endif // employee_H_INCLUDED
Employee* employee_new();

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);
void employee_printUno(Employee* this);

int employee_validarId(LinkedList* lista, int id);
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_ingresoNombre(Employee* this);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_ingresoHorasTrabajadas(Employee* this);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_ingresoSueldo(Employee* this);

int employee_ordenarId(void* primerParametro,void* segundoParametro);
int employee_ordenarnombre(void* primerParametro,void* segundoParametro);
int employee_ordenarhoras(void* primerParametro,void* segundoParametro);
int employee_ordenarsueldo(void* primerParametro,void* segundoParametro);
int employee_filterSueldo(void* parametro);
int employee_filterHoras(void* parametro);


int modificacion();
