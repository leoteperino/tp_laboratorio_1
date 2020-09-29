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
/** \brief print the content of employees array
* \param list Employee*
* \param length int
* \return int
*/
int printEmployees(Employee* list, int len)
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
				printf("ID:%d - Nombre:%s - Apellido:%s - Salario:%.2f - Sector:%d\n",
						list[i].id,
						list[i].name,
						list[i].lastName,
						list[i].salary,
						list[i].sector);
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

/**
 * \brief Da de alta un Empleado en una posicion del array de manera forzada
 * \param array Array de empleados a ser actualizado
 * \param int len longitud del array de empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int mocksEmployees(Employee* list, int len, int indice, int id, char* name,char* lastName,float salary,int sector)
{
	int ret = -1;
	Employee bufferEmployee;

	if(list!= NULL && len>0 && indice<len && indice>=0 && id>=0 && name!=NULL && lastName!=NULL && salary>0 && sector>=0)
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
	return ret;
}
/**
 * \brief Realiza la edicion de un empleado solo si el indice es valido.
 * \param Employee list, Es el puntero al array de empleados
 * \param int len, es el limite de array
 * \param int indice, es el indice donde se modificara el empleado
 * \return (-1) Error / (0) Ok
 */
int editEmployee(Employee* list, int len, int indice)
{
	int ret=-1;
	Employee bufferEmployee;
	if(list!=NULL && len>0 && indice>=0 && indice<=len)
	{
		if(	!utn_getNombre( bufferEmployee.name,ARRAY_NAME_LEN,
							"Ingrese un nombre: ","ERROR\n",QTY_REINT) &&
			!utn_getApellido( bufferEmployee.lastName,ARRAY_LASTNAME_LEN,
							  "Ingrese un apellido: ","ERROR\n",QTY_REINT) &&
			!utn_getNumeroFlotante( &bufferEmployee.salary,"Ingrese el salario: ",
									"ERROR",ZERO,MAX_SALARY,QTY_REINT) &&
			!utn_getNumero( &bufferEmployee.sector,"Ingrese el sector: ",
			                "ERROR",ZERO,MAX_SECTOR,QTY_REINT))
		{
			bufferEmployee.id = list[indice].id;
			bufferEmployee.isEmpty = list[indice].isEmpty;
			list[indice]=bufferEmployee;
			ret=0;
		}
	}
	return ret;
}
/**
 * \brief Realiza la edicion del nombre de un empleado solo si el indice es valido.
 * \param Employee list, Es el puntero al array de empleados
 * \param int len, es el limite de array
 * \param int indice, es el indice donde se modificara el empleado
 * \return (-1) Error / (0) Ok
 */
int editNameEmployee(Employee* list, int len, int indice)
{
	int ret=-1;
	Employee bufferEmployee;
	if(list!=NULL && len>0 && indice>=0 && indice<=len)
	{
		if(	!utn_getNombre( bufferEmployee.name,ARRAY_NAME_LEN,
							"Ingrese el nuevo nombre: ","ERROR\n",QTY_REINT))
		{
			bufferEmployee.id = list[indice].id;
			strncpy(bufferEmployee.lastName,list[indice].lastName,ARRAY_NAME_LEN);
			bufferEmployee.salary = list[indice].salary;
			bufferEmployee.sector = list[indice].sector;
			bufferEmployee.isEmpty = list[indice].isEmpty;
			list[indice]=bufferEmployee;
			ret=0;
		}
	}
	return ret;
}
/**
 * \brief Realiza la edicion del Apellido de un empleado solo si el indice es valido.
 * \param Employee list, Es el puntero al array de empleados
 * \param int len, es el limite de array
 * \param int indice, es el indice donde se modificara el empleado
 * \return (-1) Error / (0) Ok
 */
int editLastNameEmployee(Employee* list, int len, int indice)
{
	int ret=-1;
	Employee bufferEmployee;
	if(list!=NULL && len>0 && indice>=0 && indice<=len)
	{
		if(	!utn_getApellido( bufferEmployee.lastName,ARRAY_NAME_LEN,
							  "Ingrese el nuevo apellido: ","ERROR\n",QTY_REINT))
		{
			bufferEmployee.id = list[indice].id;
			strncpy(bufferEmployee.name,list[indice].name,ARRAY_NAME_LEN);
			bufferEmployee.salary = list[indice].salary;
			bufferEmployee.sector = list[indice].sector;
			bufferEmployee.isEmpty = list[indice].isEmpty;
			list[indice]=bufferEmployee;
			ret=0;
		}
	}
	return ret;
}
/**
 * \brief Realiza la edicion del salario de un empleado solo si el indice es valido.
 * \param Employee list, Es el puntero al array de empleados
 * \param int len, es el limite de array
 * \param int indice, es el indice donde se modificara el empleado
 * \return (-1) Error / (0) Ok
 */
int editSalaryEmployee(Employee* list, int len, int indice)
{
	int ret=-1;
	Employee bufferEmployee;
	if(list!=NULL && len>0 && indice>=0 && indice<=len)
	{
		if(	!utn_getNumeroFlotante( &bufferEmployee.salary,"Ingrese el nuevo salario: ",
				"ERROR",ZERO,MAX_SALARY,QTY_REINT))
		{
			bufferEmployee.id = list[indice].id;
			strncpy(bufferEmployee.name,list[indice].name,ARRAY_NAME_LEN);
			strncpy(bufferEmployee.lastName,list[indice].lastName,ARRAY_NAME_LEN);
			bufferEmployee.sector = list[indice].sector;
			bufferEmployee.isEmpty = list[indice].isEmpty;
			list[indice]=bufferEmployee;
			ret=0;
		}
	}
	return ret;
}
/**
 * \brief Realiza la edicion del sector de un empleado solo si el indice es valido.
 * \param Employee list, Es el puntero al array de empleados
 * \param int len, es el limite de array
 * \param int indice, es el indice donde se modificara el empleado
 * \return (-1) Error / (0) Ok
 */
int editSectorEmployee(Employee* list, int len, int indice)
{
	int ret=-1;
	Employee bufferEmployee;
	if(list!=NULL && len>0 && indice>=0 && indice<=len)
	{
		if(	!utn_getNumero( &bufferEmployee.sector,"Ingrese el nuevo sector: ",
                            "ERROR",ZERO,MAX_SECTOR,QTY_REINT))
		{
			bufferEmployee.id = list[indice].id;
			strncpy(bufferEmployee.name,list[indice].name,ARRAY_NAME_LEN);
			strncpy(bufferEmployee.lastName,list[indice].lastName,ARRAY_NAME_LEN);
			bufferEmployee.salary = list[indice].salary;
			bufferEmployee.isEmpty = list[indice].isEmpty;
			list[indice]=bufferEmployee;
			ret=0;
		}
	}
	return ret;
}
/**
* \brief Muestra el empleado seleccionado por ID
* \param list Employee*
* \param length int
* \param int id del empleado seleccionado
* \return -1 (ERROR) - 0 (OK).
*/
int printEmployeeById(Employee* list, int len, int id)
{
	int ret=-1;
	int i=0;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE && list[i].id==id)
			{
				ret=0;
				printf("ID:%d - Nombre:%s - Apellido:%s - Salario:%.2f - Sector:%d\n",
						list[i].id,
						list[i].name,
						list[i].lastName,
						list[i].salary,
						list[i].sector);
			}
		}
	}
	return ret;
}
/**
* \brief Remove a Employee by Id (put isEmpty Flag in 1)
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*/
int removeEmployee(Employee* list, int len, int id)
{
	int ret=-1;
	Employee bufferEmployee;
	int auxIndice;
	char auxChar;
	if(list!=NULL && len>0 && id>=0)
	{
		auxIndice = findEmployeeById(list,ARRAY_LEN_EMPLOYEES,id);
		if(auxIndice>=0)
		{
			if(!utn_getCaracterSN(&auxChar,ARRAY_LEN_CHAR,
					   	   	   	  "Esta seguro que desea borrar este Alumno?[S/N]:",
								  "ERROR\n",QTY_REINT))
			{
				switch(auxChar)
				{
					 case 'S':
					 case 's':
						bufferEmployee.id = list[auxIndice].id;
						strncpy(bufferEmployee.name,list[auxIndice].name,ARRAY_NAME_LEN);
						strncpy(bufferEmployee.lastName,list[auxIndice].lastName,ARRAY_NAME_LEN);
						bufferEmployee.salary = list[auxIndice].salary;
						bufferEmployee.sector = list[auxIndice].sector;
						bufferEmployee.isEmpty = TRUE;
						list[auxIndice]=bufferEmployee;
						ret=0;
						break;
					 case 'N':
					 case 'n':
						 break;
				}
			}
		}
		else
		{
				printf("Usted ingreso un ID que no existe.\n");
		}
	}
	return ret;
}

