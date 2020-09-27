/*
 * ArrayEmployees.c
 *
 *  Created on: Sep 26, 2020
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

static int generarIdNuevo(void);

/**
 * \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initEmployees(Employee* list, int len)
{
	int ret=-1;
	int i=0;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=TRUE;
		}
		ret=0;
	}
	return ret;
}
/**
 * \brief find an Employee by Id en returns the index position in array.
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int ret=-1;
	int i=0;
	if(list!=NULL && len>0 && id>=0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE && list[i].id==id)
			{
				ret=i;
				break;
			}
		}
	}
	return ret;
}
/**
 * \brief add in a existing list of employees the values received as parameters in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int ret=-1;
	Employee bufferEmployee;
	int indice;
	if(list!=NULL && len>0 && id>=0 && name!=NULL && lastName!=NULL && salary>0 && sector>=0)
	{
		indice = buscarVacio(list,len);
		if(indice>=0)
		{
			bufferEmployee.id=generarIdNuevo();
			bufferEmployee.isEmpty = FALSE;
			strncpy(bufferEmployee.name,name,ARRAY_NAME_LEN);
			strncpy(bufferEmployee.lastName,lastName,ARRAY_LASTNAME_LEN);
			bufferEmployee.salary=salary;
			bufferEmployee.sector=sector;
			list[indice] = bufferEmployee;
			ret=0;
		}
		else
		{
			printf("No hay lugares vacios en el array.\n");
		}
	}
	return ret;
}
/**
 * \brief Genera un numero de id nuevo cada vez que se llama a la funcion
 * \return devuelve el numero de id generado
 */
static int generarIdNuevo(void)
{
	static int id=0;
	id = id+1;
	return id;
}
/**
 * \brief Imprime los empleados cargados
 * \param Employee array[], Es el puntero al array de Empleados
 * \param int len, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int mostrarLista(Employee* list, int len)
{
	int ret=-1;
	int i=0;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				ret=0;
				printf("ID:%d - Nombre:%s %s - Salario:%.2f - Sector:%d - Estado:%d\n",
						list[i].id,
						list[i].name,
						list[i].lastName,
						list[i].salary,
						list[i].sector,
						list[i].isEmpty);
			}
		}
	}
	return ret;
}
/**
 * \brief Busca el primer lugar vacio de la lista de Empleados.
 * \param Empleados array[], Es el puntero al array de empleados.
 * \param int len, es el limite de array
 * \return devuelve el indice del lugar vacio de la lista o -1 en caso de no encontrar lugar vacio
 */
int buscarVacio(Employee* list, int len)
{
	int ret = -1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==TRUE)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}
