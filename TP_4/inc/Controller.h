#include "LinkedList.h"

#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED

#endif

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);

LinkedList* controller_filterSueldo(LinkedList* pArrayListEmployee);
int controller_subList(LinkedList* pArrayListEmployee);
int controller_compararSueldoHoras(LinkedList* pArrayListEmployee,LinkedList* lista2);
int controller_buscarUnEmpleado(LinkedList* pArrayListEmployee,LinkedList* lista2);

void controller_exit(LinkedList* pArrayListEmployee);
int menu();
int menuOrdenar();

