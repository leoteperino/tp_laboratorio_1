#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	//Aca me llega lo que se leyo del archivo
	//Lo primero que hago es verificar que no sea NULL
//	int retorno = -1;
//	Employee* pBuffer;
//	int retornoLectura;
//	if(pFile != NULL)
//	{
//		retorno = 0;
//		//Como empiezo a recorrer este archivo y donde voy guardando
//		//lo que encuentro
//		do
//		{
//			//Cada vez que leo voy a leer un empleado
//			//y para poder leerlo armo un Buffer de empleado
//			//Hasta aca estoy leyendo en un buffer y verifico si lo pude
//			//leer con la var retornoLectura
//			// 1 -Si lo puede leer debo crear un empleado de manera dinamica y agregarlo
//			//a la lista
//			// 2 - Crear un buffer de manera dinamica es lo correcto
//			// Se crea un puntero a buffer y cada vez que leo guardo espacion en memoria
//			//para uno nuevo
//			//Aca ya tengo en un beffer un empleado creado de manera dinamica
//			pBuffer = employee_new(); //Esto me devuelve un puntero a un empleado
//			if(pBuffer!=NULL)
//			{
//				retornoLectura = fread(pBuffer,sizeof(Employee),1,pFile);
//				if(retornoLectura)
//				{
//					//Si retorno lectura es 1 es porque leyo algo
//					//Y tengo que llenar ese empleado con algo
//					//Ya tenemos un empleado creado de manera dinamica
//					//esta cargado con los datos que encontramos en el archivo
//					//Lo unico que falta es añadirlo a la lista con ll_add
//					ll_ad(pArrayListEmployee,pBuffer);
//				}
//				else
//				{
//					//Si no pudo leer el Empleado, tengo que liberarlo
//					//employee_delete hace un free
//					employee_delete(pBuffer);
//				}
//			}
//		}while(!feof(pFile));
//	}
    return 1;
}
