/*
 ============================================================================
 Name        : trabajoPractico2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define MIN_OPTION_MENU 1
#define MAX_OPTION_MENU 4
#define MAX_OPTION_MENU_INFO 5
#define MAX_SALARY 999999
#define MAX_SECTOR 50

int main(void)
{
	//Declaracion de las Variables
	Employee employees[ARRAY_LEN_EMPLOYEES];
	int optionMenu;
	int id = 0;
	char name[ARRAY_NAME_LEN];
	char lastName[ARRAY_LASTNAME_LEN];
	float salary;
	int sector;

	//Inicializacion del Array
	if(!initEmployees(employees,ARRAY_LEN_EMPLOYEES))
	{
		printf("\nEl Array se Inicializo con Exito!!\n");
	}
	else
	{
		printf("\nEl Array no pudo inicializarse!!\n");
	}

	//Menu Principal
	do
	{
		if(!utn_getNumero(   &optionMenu,
							"\n*****Menu de Opciones*****\n"
							"1 - Dar de alta un empleado.\n"
							"2 - Modificar un empleado.\n"
							"3 - Dar de baja un empleado.\n"
							"4 - Informar.\n"
							"-----------------------------\n"
							"Elija una Opcion del Menu: ",
							"ERROR",MIN_OPTION_MENU,MAX_OPTION_MENU, QTY_REINT))
		{
			switch(optionMenu)
			{
				case 1:
					printf("\n***************************************\n");
					printf("Opcion 1\nDar de alta un empleado:\n");
					if(	!utn_getNombre(name,ARRAY_NAME_LEN,"Ingrese el nombre: ","ERROR\n",QTY_REINT) &&
						!utn_getApellido(lastName,ARRAY_LASTNAME_LEN,"Ingrese un apellido: ","ERROR\n",QTY_REINT)&&
						!utn_getNumeroFlotante(&salary,"Ingrese el salario: ","ERROR",ZERO,MAX_SALARY,QTY_REINT)&&
						!utn_getNumero(&sector,"Ingrese un sector: ","ERROR",ZERO,MAX_SECTOR,QTY_REINT))
					{
						if(!addEmployee(employees,ARRAY_LEN_EMPLOYEES,id,name,lastName,salary,sector))
						{
							printf("El empleado se cargo con exito!!\n");
						}
					}
					else
					{
						printf("Algo salio mal, se acabaron tus reintentos.\n");
					}
					printf("Lista de empleados:\n");
					mostrarLista(employees,ARRAY_LEN_EMPLOYEES);
					printf("\n***************************************\n");
					break;
				case 2:
					printf("\n***************************************\n");
					printf("Opcion 2\nModificar un empleado:\n");
					printf("\n***************************************\n");
					break;
				case 3:
					printf("\n***************************************\n");
					printf("Opcion 3\nDar de baja un empleado:\n");
					printf("\n***************************************\n");
					break;
				case 4:
					printf("\n***************************************\n");
					do
					{
						if(!utn_getNumero(	&optionMenu,
											"\n*****Informar*****\n"
											"1 - Lista de Empleados ordenada Alfabeticamente.\n"
											"2 - Total de los salarios.\n"
											"3 - Promedio de los salarios.\n"
											"4 - Cantidad de empleados que superan el salario promedio.\n"
											"5 - Volver al Menu Principal.\n"
											"-----------------------------\n"
											"Elija una Opcion del Menu: ",
											"\nERROR",MIN_OPTION_MENU,MAX_OPTION_MENU_INFO,QTY_REINT))
						{
							switch(optionMenu)
							{
								case 1:
									printf("\n***************************************\n");
									printf("Lista de Emplados por orden alfabetico:\n");
									printf("\n***************************************\n");
									break;
								case 2:
									printf("\n***************************************\n");
									printf("Total del salario:\n");
									printf("\n***************************************\n");
									break;
								case 3:
									printf("\n***************************************\n");
									printf("Promedio de los salarios:\n");
									printf("\n***************************************\n");
									break;
								case 4:
									printf("\n***************************************\n");
									printf("Cantidad de empleados que superan el salario promedio:\n");
									printf("\n***************************************\n");
									break;
							}
						}
					}while(optionMenu!=5);
					printf("\n***************************************\n");
					break;
			}
		}
	}while(optionMenu);
	return EXIT_SUCCESS;
}
