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

int main(void)
{
	//Declaracion de las Variables
	Employee employees[ARRAY_LEN_EMPLOYEES];
	int optionMenu;
	int id=0;
	char name[ARRAY_NAME_LEN];
	char lastName[ARRAY_LASTNAME_LEN];
	float salary;
	int sector;
	int auxIndice;
	int auxId;

	//Inicializacion del Array
	if(!initEmployees(employees,ARRAY_LEN_EMPLOYEES))
	{
		printf("\nEl Array se Inicializo con Exito!!\n");
	}
	else
	{
		printf("\nEl Array no pudo inicializarse!!\n");
	}

	//Mocks
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,0,id,"Pepe","Mujica",45000,1);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,1,id,"Pepe","Argento",55000,2);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,2,id,"Pepe","Gonzalez",65800,3);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,3,id,"Diego","Maradona",78000,4);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,4,id,"Fernando","Gomez",80000,5);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,5,id,"Pablo","Gimenez",92100,1);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,6,id,"Alberto","Fernandez",55000,8);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,7,id,"Cristina","Kirchner",64100.30,9);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,8,id,"Patricia","Bulrich",43000,7);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,9,id,"Daniela","Garay",48000,8);

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
					printEmployees(employees,ARRAY_LEN_EMPLOYEES);
					printf("\n***************************************\n");
					break;
				case 2:
					printf("\n***************************************\n");
					printf("Opcion 2\nModificar un empleado:\n");
					if(!printEmployees(employees,ARRAY_LEN_EMPLOYEES))
					{
						if(!utn_getNumero(	&auxId,
										"Ingrese el numero de ID del empleado a modificar: ",
										"ERROR\n",ZERO,MAX_ID,QTY_REINT))
						{
							auxIndice = findEmployeeById(employees,ARRAY_LEN_EMPLOYEES,auxId);
							if(auxIndice>=0)
							{

							}
							else
							{
								printf("Usted ingreso un ID que no existe.\n");
							}
						}

					}
					else
					{
						printf("La lista de empleado esta vacia.\nDebe cargar un empleado para poder continuar.\n");
					}

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
