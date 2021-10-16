/*
 *      Author: Gabriel Remon
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define OCUPADO 0
#define VACIO 1

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

int initEmployees(eEmployee vec[], int tam);
/** Inicializa todas las variables isEmpry de la variable vec[] en 1
* parametro vec[] eEmployee vector tipo estructura
* parametro tam int tamaño maximo del vector vec[]
*
* retorna int (-1) si huvo un error - (0) si todo ok
*/

int menu();
/** Muestra el menu de opciones principal del programa y devuelve un int validado
*
* retorna int por return entre el 1 y el 5
*/

int altaEmpleado(eEmployee vec[], int tam, int* id);
/** Pide al usuario 4 parametros valida y los carga en la primera posicision libre del vector
* parametro vec[] eEmployee vector tipo estructura
* parametro tam int tamaño maximo del vector vec[]
* parametro id int* carga el valor de id en vec[].id y suma 1 al valor de id
*
* retorna int (-1) si huvo un error - (0) si todo ok
*/

int addEmployees(eEmployee vec[], int tam, int id, char name[],char lastName[],float salary,int sector);
/** Carga los parametros recividos en el primer lugar libre de la variable tipo estructura
* parametro vec[] eEmployee vector tipo estructura
* parametro tam int tamaño maximo del vector vec[]
* parametro id int
* parametro name[] char
* parametro lastName[] char
* parametro salary float
* parametro sector int
*
*
* retorna int (-1) si huvo un error - (0) si todo ok
*/

int espacioLibre(eEmployee vec[], int tam);
/** Recorre toda el vector tipo estructura y devuelve si esta lleno, totalmente vacio o que espacio tiene libre
* parametro vec[] eEmployee variable tipo estructura
* parametro tam int largo maximo del vector
*
* retorna int (-2) si esta totalmente vacio - (-1) si huvo un error - (int) de la posicion libre si hay mas de un espacio ocupado
*/

int modificacionEmpleado(eEmployee vec[], int tam);
/** Pide al usuario un numero entero, busca si coincide con algun dato vec[].id y permite la modificacion de las demas varibles
dentro de esa pocision del vector
* parametro vec[] eEmployee variable tipo estructura
* parametro tam int largo maximo del vector
*
* retorna int (-1) si huvo un error - (0) si todo ok
*/

int findEmployeeById(eEmployee vec[], int tam,int id);
/** Busca el valor id pasado como parametro en el vector estructura y devuelve en que posicion se encuentra
* parametro vec[] eEmployee variable tipo estructura
* parametro tam int largo maximo del vector
* parametro id int
*
* retorna int return (-1) si huvo un error - (int) de la posicion del vector que coincide con el id
*/

int bajaEmpleado(eEmployee vec[], int tam);
/** Pide un valor entero al usuario y busca ese valor dentro de la variable vec[].id. Y elimina de manera logica a ese empleado
* parametro vec[] eEmployee variable tipo estructura
* parametro tam int largo maximo del vector
*
* retorna int return (-1) si huvo un error - (0) si todo ok
*/

int removeEmployee(eEmployee vec[], int tam, int id);
/** Elimina de manera logica a un empleado (vec[].isEmpty = 1) reciviendo su numero de id (vec[].id)
* parametro vec[] eEmployee variable tipo estructura
* parametro tam int largo maximo del vector
*
* retorna int return (-1) si huvo un error - (0) si todo ok
*/

void printEmployees(eEmployee vec[], int tam);
/** Imprime el vector de manera encadenada
* parametro vec[] eEmployee variable tipo estructura
* parametro tam int largo maximo del vector
*
*/

int sortEmployees(eEmployee vec[], int tam, int orden);
/** ordena de manera asendente o desendente al vector por apellido(vec[].lastName) y sector(vec[].sector)
* parametro vec[] eEmployee variable tipo estructura
* parametro tam int largo maximo del vector
* parametro orden int [1] indica manera asendente - [0] indica manera desendente
*
* retorna int return (-1) si huvo un error - (0) si todo ok
*/

#endif // ARRAYEMPLOYEES_H_INCLUDED
