#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	//Aca se abre el archivo en modo lectura y se lo paso a parser
	int ret=-1;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE* pFile = fopen(path,"r");
		if(pFile!=NULL)
		{
			ret = parser_EmployeeFromText(pFile, pArrayListEmployee);
		}
		fclose(pFile);
	}
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	//El archivo se va a abrir en esta funcion y llega abierto a parser.
	//Aca hay que llamar a la funcion de Parser
	//Aca se lee el archivo y luego se lo pasamos al parser
	//para que este lo cargue en memoria
	//Este es el modo Disney de hacerlo
//	FILE* pFile = fopen(path,"r");

	//Un modo un poco mas pro seria hacer esto
	//parser_EmployeeFromBinary(fopen(path,"r"),pArrayListEmployee);

	//o asi tambien
//	int retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);

	//Debo cerrar el archivo despues de usarlo
//	fclose(pFile);

	//Voy a retornanr lo que me devuelva la funcion parser_EmployeeBinary
	//Puedo retornar la funcion directamente o guardarla en una variable y retornar la variable
    //return parser_EmployeeFromBinary(pFile, pArrayListEmployee);
	return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
//	int retorno = -1;
//	int i;
	//Creo un puntero al archivo
//	FILE* pFile;
	//Genero un puntero a un empleado
//	Employee* pEmpleado;
	//Guardo en una variable cuando mide la lista
//	int len = ll_len(pArrayListEmployee);
//	if(path != NULL && pArrayListEmployee != NULL)
//	{
//		//Recorro la lista
//		//Abro el archivo y lo leo com Binario
//		pFile = fopen(path,"wb");
//		if(pFile!=NULL)
//		{
//			retorno = 0;
//			for(i=0;i<len;i++)
//			{
//				//Obtengo un empleado
//				//ll_get me devuelve un puntero a void que se encuentra en i
//				pEmpleado= (Employee*)ll_get(pArrayListEmployee,i);
//				//Escribo el empleado en un Binario
//				//Esto destruye el archivo original y se crea uno nuevo
//				fwrite(pEmpleado,sizeof(Employee),1,pFile);
//			}
//		}
//	}
//	fclose(pFile);
    return 1;
}

