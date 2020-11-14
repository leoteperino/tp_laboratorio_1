#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

//TODO: Faltan validaciones las saque porque rompian
//Validaciones
static int esNumerica(char* cadena, int limite);
static int esNombre(char* cadena,int longitud);

Employee* employee_new(void)
{
    return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametrosTXT(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldStr)
{
	Employee* this = NULL;
	this = employee_new();
	if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldStr != NULL)
	{
		if( !(employee_setIdChar(this,idStr))
			&& !(employee_setNombre(this,nombreStr))
			&& !(employee_setHorasTrabajadasChar(this,horasTrabajadasStr))
			&& !(employee_setSueldoChar(this,sueldStr)))
		{
			return this;
		}
		else
		{
			employee_delete(this);
			this = NULL;
		}
	}
	return NULL;
}

int employee_delete(Employee* this)
{
	int ret=-1;
	if(this!=NULL)
	{
		ret=0;
		free(this);
	}
	return ret;
}

/*###############################################*/
/*################Setter Char####################*/
int employee_setIdChar(Employee* this,char* id)
{
	int ret=-1;
	int bufferID;
	if(this!=NULL && id!=NULL && esNumerica(id, LEN_ID))
	{
		ret=0;
		bufferID = atoi(id);
		this->id = bufferID;
	}
	return ret;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int ret=-1;
	if(this!=NULL && nombre!=NULL)
	{
		if(esNombre(nombre,LEN_NOMBRE))
		{
			ret=0;
			strncpy(this->nombre,nombre,LEN_NOMBRE);
		}
	}
	return ret;
}

int employee_setHorasTrabajadasChar(Employee* this,char* horasTrabajadas)
{
	int ret=-1;
	int bufferHoras;
	if(this!=NULL && horasTrabajadas!=NULL && esNumerica(horasTrabajadas,LEN_HORAS))
	{
		ret=0;
		bufferHoras = atoi(horasTrabajadas);
		this->horasTrabajadas = bufferHoras;
	}
	return ret;
}

int employee_setSueldoChar(Employee* this,char* sueldo)
{
	int ret=-1;
	int bufferSueldo;
	if(this!=NULL && sueldo!=NULL && esNumerica(sueldo,LEN_SUELDO))
	{
		ret=0;
		bufferSueldo = atoi(sueldo);
		this->sueldo = bufferSueldo;
	}
	return ret;
}

/*###############################################*/
/*################Getters Char###################*/
int employee_getIdChar(Employee* this,char* id)
{
	int ret=-1;
	if(this!=NULL && id!=NULL)
	{
		ret=0;
		sprintf(id,"%d",this->id);
	}
	return ret;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int ret=-1;
	if(this!=NULL && nombre!=NULL)
	{
		ret=0;
		strncpy(nombre,this->nombre,LEN_NOMBRE);
	}
	return ret;
}

int employee_getHorasTrabajadasChar(Employee* this,char* horasTrabajadas)
{
	int ret=-1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		ret=0;
		sprintf(horasTrabajadas,"%d",this->horasTrabajadas);
	}
	return ret;
}

int employee_getSueldoChar(Employee* this,char* sueldo)
{
	int ret=-1;
	if(this!=NULL && sueldo!=NULL)
	{
		ret=0;
		sprintf(sueldo,"%d",this->sueldo);
	}
	return ret;
}

/*###############################################*/
/*###############Getters Nativos##################*/
int employee_getIdNativo(Employee* this)
{
	int ret=-1;
	if(this!=NULL)
	{
		ret = this->id;
	}
	return ret;
}

char* employee_getNombreNativo(Employee* this)
{
	return this->nombre;
}

int employee_getHorasTrabajadasNativo(Employee* this)
{
	int ret=-1;
	if(this!=NULL)
	{
		ret = this->horasTrabajadas;
	}
	return ret;
}

int employee_getSueldoNativo(Employee* this)
{
	int ret=-1;
	if(this!=NULL)
	{
		ret = this->sueldo;
	}
	return ret;
}

/*###############################################*/
/*###############Validaciones###################*/
/**
 * \brief Verifica si la cadena ingresada es numerica, admite solo enteros
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 **/
static int esNumerica(char* cadena, int limite)
{
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>=0)
	{
		retorno = 1;
		for(i=0;i<limite&&cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int esNombre(char* cadena,int longitud)
{
	int retorno = 1;
	int i=0;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0'; i++)
		{
			if((cadena[i]<'A' || cadena[i]>'z') && (cadena[i]<'Z' || cadena[i]>'a'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



