/*
 * informes.c
 *
 *  Created on: Sep 29, 2020
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#include "Informes.h"

/**
 * \brief Calcula el Total y el Promedio de todos los salarios de los Empleados.
 * \param float pPromedio puntero a float donde se guardara el resultado del promedio.
 * \param float pTotalSalario puntero a float donde se guarda la cantidad total de los salarios.
 * \param array de Empleados - lista completa de los empleados
 * \param int len longitud total del array de Empleados
 * \return devuelve -1 en caso de ERROR y 0 en caso de OK.
 */
int info_PromedioTotalSalarios(float* pPromedio, float* pTotalSalario, Employee* list, int len)
{
	int ret=-1;
	float acumulador=0;
	int contador=0;
	int i;
	if(pPromedio!=NULL && pTotalSalario!=NULL && list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				acumulador+=list[i].salary;
				contador++;
			}
		}
		*pPromedio = ((float)acumulador)/contador;
		*pTotalSalario = acumulador;
		ret=0;
	}
	return ret;
}
/**
 * \brief Calcula el cantidad de empleados con un salario mayor al promedio.
 * \param float promedio promedio de todos los salarios.
 * \param int pResultado puntero donde se guardara el resultado.
 * \param array de Empleados - lista completa de los empleados.
 * \param int len longitud total del array de Empleados.
 * \return devuelve -1 en caso de ERROR y 0 en caso de OK.
 */
int info_calcularEmpleadosQueSuperanSalarioPromedio(Employee* list, int len, float promedio, int* pResultado)
{
	int ret=-1;
	int i;
	int contadorEmpleados = 0;
	if(list!=NULL && len>0 && promedio>=0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				if(list[i].salary > promedio)
				{
					contadorEmpleados++;
				}
			}
		}
		*pResultado = contadorEmpleados;
		ret=0;
	}
	return ret;
}

