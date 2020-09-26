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

int main(void)
{
	Employee employees[ARRAY_NAME_LEN];
	int optionMenu;

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
