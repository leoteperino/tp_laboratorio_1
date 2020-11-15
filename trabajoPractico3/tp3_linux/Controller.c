#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

static int controller_newEmployeeId(LinkedList* pArrayListEmployee, int* id);

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
	int ret = -1;
	FILE* pFile;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"rb");
		if(pFile!=NULL)
		{
			if(parser_EmployeeFromBinary(pFile, pArrayListEmployee))
			{
				ret = 0;
			}
			fclose(pFile);
		}
	}
	return ret;
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
	int ret=-1;
	int bufferId;
	char bufferNombre[LEN_NOMBRE];
	int bufferHoras;
	int bufferSueldo;
	Employee* this;
	if(pArrayListEmployee!=NULL)
	{
		if( !controller_newEmployeeId(pArrayListEmployee, &bufferId) &&
			!utn_getNombre(bufferNombre,LEN_NOMBRE,"Ingrese nombre del empleado: ","ERROR",QTY_REINT) &&
			!utn_getNumero(&bufferHoras,"Ingrese horas trabajadas: ","ERROR",ZERO,MAX_HORAS,QTY_REINT) &&
			!utn_getNumero(&bufferSueldo,"Ingrese el sueldo: ","ERROR",ZERO,MAX_SUELDO,QTY_REINT))
		{
			this = employee_newParam(bufferId,bufferNombre,bufferHoras,bufferSueldo);
			if(this!=NULL)
			{
				if(!ll_add(pArrayListEmployee, this))
				{
					ret=0;
				}
			}
		}
	}
    return ret;
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
	int ret=-1;
	int bufferID;
	int positionID;
	Employee* this;
	if(pArrayListEmployee!=NULL)
	{
		printf("############# Edicion de Empleados ################\n");
		controller_ListEmployee(pArrayListEmployee);
		if(!utn_getNumero(&bufferID,"Ingrese el ID del empleado a editar: ","ERROR",ZERO,LEN_ID,QTY_REINT))
		{
			if(!controller_employeeFindById(pArrayListEmployee,bufferID,&positionID))
			{
				this = (Employee*)ll_get(pArrayListEmployee, positionID);
				if(this!=NULL)
				{
					printf( "Empleado seleccionado:\n"
							"Nombre: %s\n"
							"Horas trabajadas: %d\n"
							"Sueldo: %d\n",
							employee_getNombreNativo(this),
							employee_getHorasTrabajadasNativo(this),
							employee_getSueldoNativo(this));
				}
				if(	!utn_getNombre(this->nombre,LEN_NOMBRE,"Ingrese nuevo nombre: ","ERROR",QTY_REINT) &&
					!utn_getNumero(&this->horasTrabajadas,"Ingrese las nuevas horas: ","ERROR",ZERO,LEN_HORAS,QTY_REINT) &&
					!utn_getNumero(&this->sueldo,"Ingrese el nuevo sueldo: ","ERROR",ZERO,LEN_SUELDO,QTY_REINT))
				{
					if( !employee_setNombre(this, this->nombre) &&
						!employee_setHorasTrabajadas(this, this->horasTrabajadas) &&
						!employee_setSueldo(this, this->sueldo))
					{
						printf("El empleado se edito con exito!!\n");
						ret=0;
					}
				}
			}
			else
			{
				printf("No se encontro el ID ingresado.\n");
			}
		}
	}
	return ret;
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
	int ret=-1;
	int bufferID;
	int positionID;
	int bufferIndexList;
	Employee* this;
	if(pArrayListEmployee!=NULL)
	{
		printf("############# Baja de Empleados ################\n");
		controller_ListEmployee(pArrayListEmployee);
		if(!utn_getNumero(&bufferID,"Ingrese el ID del empleado a borrar: ","ERROR",ZERO,LEN_ID,QTY_REINT))
		{
			if(!controller_employeeFindById(pArrayListEmployee,bufferID,&positionID))
			{
				this = (Employee*)ll_get(pArrayListEmployee, positionID);
				if(this!=NULL)
				{
					printf("Empleado seleccionado: %s\n", employee_getNombreNativo(this));
				}
				bufferIndexList = ll_indexOf(pArrayListEmployee,this);
				if( !employee_delete(this) &&
					!ll_remove(pArrayListEmployee, bufferIndexList))
				{
					printf("El empleado ha sido borrado.\n");
				}
			}
			else
			{
				printf("No se encontro el ID ingresado.\n");
			}
		}
	}
    return ret;
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
	int ret=-1;
	int len_ll;
	int i;
	Employee* this;
	if(pArrayListEmployee!=NULL)
	{
		ret=0;
		len_ll = ll_len(pArrayListEmployee);
		for(i=0;i<len_ll;i++)
		{
			this = (Employee*)ll_get(pArrayListEmployee, i);
			if(this!=NULL)
			{
				printf( "%d-%s-%d-%d\n",
						employee_getIdNativo(this),
						employee_getNombreNativo(this),
						employee_getHorasTrabajadasNativo(this),
						employee_getSueldoNativo(this));
			}
		}
	}
	return ret;
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
   int ret=-1;
   if(pArrayListEmployee!=NULL)
   {
	   if(!ll_sort(pArrayListEmployee, employee_sortEmployeesByHorasTrabajadas, 1))
	   {
		   ret = 0;
		   printf("Se ordeno con exito la lista de empleados por horas trabajadas\n");
	   }
   }
   return ret;
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
    int ret=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
    	pFile=fopen(path,"w");
    	if(pFile!=NULL)
    	{
    		if(!parser_EmployeeWriteText(pFile, pArrayListEmployee))
    		{
    			ret = 0;
    			printf("El archivo se guardo con exito!!");
    		}
    		fclose(pFile);
    	}
    }
    return ret;
}

int controller_employeeFindMaxId(LinkedList* pArrayListEmployee, int* id)
{
	int ret=-1;
	Employee* this;
	int idMax;
	int i;
	int len_ll;
	if(pArrayListEmployee!=NULL && id>=0)
	{
		len_ll = ll_len(pArrayListEmployee);
		for(i=0;i<len_ll;i++)
		{
			this = (Employee*)ll_get(pArrayListEmployee,i);
			if(this!=NULL)
			{
				if(this->id > idMax || i==0)
				{
					idMax = this->id;
				}
				*id = idMax;
				ret=0;
			}
		}
	}
	return ret;
}

static int controller_newEmployeeId(LinkedList* pArrayListEmployee, int* id)
{
	int ret=-1;
	static int newId;
	if(pArrayListEmployee!=NULL && id>=0)
	{
		if(!controller_employeeFindMaxId(pArrayListEmployee,&newId))
		{
			newId++;
			*id = newId;
			ret=0;
		}
	}
	return ret;
}

int controller_employeeFindById(LinkedList* pArrayListEmployee, int id, int* indexPosition)
{
	int ret=-1;
	Employee* this;
	int i;
	int len_ll;
	if(pArrayListEmployee!=NULL && id>=0 && indexPosition>0)
	{
		len_ll=ll_len(pArrayListEmployee);
		for(i=0;i<len_ll;i++)
		{
			this=(Employee*)ll_get(pArrayListEmployee, i);
			if(employee_getIdNativo(this)==id)
			{
				*indexPosition = i;
				ret=0;
				break;
			}
		}
	}
	return ret;
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
//	//Creo un puntero al archivo
//	FILE* pFile;
//	//Genero un puntero a un empleado
//	Employee* pEmpleado;
//	//Guardo en una variable cuando mide la lista
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
	int ret = -1;
	FILE* pFile;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");
		if(pFile != NULL)
		{
			if(!(parser_EmployeeToBinary(pFile, pArrayListEmployee)))
			{
				ret = 0;
				printf("El archivo se guardo con exito!!");
			}
			fclose(pFile);
		}
	}
	return ret;
}

