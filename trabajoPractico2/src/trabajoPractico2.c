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
#include "Informes.h"

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
	int optionMenuEdit;
	int auxSort;
	float totalSalario;
	float promedio;
	int auxCantidad;

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
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,0,id,"Pepe","Mujica",10000,1);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,1,id,"Pepe","Argento",45689,2);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,2,id,"Pepe","Gonzalez",85420,3);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,3,id,"Diego","Maradona",35820,4);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,4,id,"Fernando","Gomez",10000,5);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,5,id,"Pablo","Gimenez",10000,1);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,6,id,"Alberto","Fernandez",45820,8);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,7,id,"Cristina","Kirchner",85470,9);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,8,id,"Patricia","Bulrich",56980,7);
	mocksEmployees(employees,ARRAY_LEN_EMPLOYEES,9,id,"Daniela","Garay",71250,8);

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
					if(printEmployees(employees,ARRAY_LEN_EMPLOYEES)==-1)
					{
						printf("La lista de empleado esta vacia.\nDebe cargar un empleado para poder continuar.\n");
					}
					else
					{
						if(!utn_getNumero(	&auxId,
											"Ingrese el numero de ID del empleado a modificar: ",
											"ERROR\n",ZERO,MAX_ID,QTY_REINT))
						{
							printf("\nEmpleado seleccionado:\n");
							printEmployeeById(employees,ARRAY_LEN_EMPLOYEES,auxId);
							auxIndice = findEmployeeById(employees,ARRAY_LEN_EMPLOYEES,auxId);
							if(auxIndice>=0)
							{
								do
								{
									if( !utn_getNumero( &optionMenuEdit,
														"*****Menu de Opciones de Edicion*****\n"
														"Ingrese el campo que desea modificar:\n"
														"1 - Nombre\n"
														"2 - Apellido\n"
														"3 - Salario\n"
														"4 - Sector\n"
														"5 - Volver al menu principal\n"
														"-----------------------------\n"
														"Ingrese la opcion deseada: ",
														"ERROR",MIN_OPTION_EDIT,MAX_OPTION_EDIT,QTY_REINT))
									{
										switch(optionMenuEdit)
										{
											case 1:
												if(!editNameEmployee(employees,ARRAY_LEN_EMPLOYEES,auxIndice))
												{
													printf("\n***************************************\n");
													printf("El empleado se edito con exito!\n");
													printf("Empleado actualizado: \n");
													printEmployeeById(employees,ARRAY_LEN_EMPLOYEES,auxId);
													printf("***************************************\n");
												}
												break;
											case 2:
												if(!editLastNameEmployee(employees,ARRAY_LEN_EMPLOYEES,auxIndice))
												{
													printf("\n***************************************\n");
													printf("El empleado se edito con exito!\n");
													printf("Empleado actualizado: \n");
													printEmployeeById(employees,ARRAY_LEN_EMPLOYEES,auxId);
													printf("***************************************\n");
												}
												break;
											case 3:
												if(!editSalaryEmployee(employees,ARRAY_LEN_EMPLOYEES,auxIndice))
												{
													printf("\n***************************************\n");
													printf("El empleado se edito con exito!\n");
													printf("Empleado actualizado: \n");
													printEmployeeById(employees,ARRAY_LEN_EMPLOYEES,auxId);
													printf("***************************************\n");
												}
												break;
											case 4:
												if(!editSectorEmployee(employees,ARRAY_LEN_EMPLOYEES,auxIndice))
												{
													printf("\n***************************************\n");
													printf("El empleado se edito con exito!\n");
													printf("Empleado actualizado: \n");
													printEmployeeById(employees,ARRAY_LEN_EMPLOYEES,auxId);
													printf("***************************************\n");
												}
												break;
										}
									}
								}while(optionMenuEdit!=5);
							}
							else
							{
								printf("Usted ingreso un ID que no existe.\n");
							}
						}
					}
					printf("\n***************************************\n");
					break;
				case 3:
					printf("\n***************************************\n");
					printf("Opcion 3\nDar de baja un empleado:\n");
					if(printEmployees(employees,ARRAY_LEN_EMPLOYEES)==-1)
					{
						printf("La lista de empleado esta vacia.\nDebe cargar un empleado para poder continuar.\n");
					}
					else
					{
						if(!utn_getNumero(	&auxId,
											"Ingrese el numero de ID del empleado a borrar: ",
											"ERROR\n",ZERO,MAX_ID,QTY_REINT))
						{
							printf("\nEmpleado seleccionado:\n");
							printEmployeeById(employees,ARRAY_LEN_EMPLOYEES,auxId);
							if(!removeEmployee(employees, ARRAY_LEN_EMPLOYEES,auxId))
							{
								printf("El empleado fue dado de baja con exito!!\n");
								printf("Lista de empleados actualizada:\n");
								printEmployees(employees,ARRAY_LEN_EMPLOYEES);
							}
						}
					}
					printf("\n***************************************\n");
					break;
				case 4:
					printf("\n***************************************\n");
					if(checkListaVacia(employees,ARRAY_LEN_EMPLOYEES)==-1)
					{
						printf("La lista de empleado esta vacia.\nDebe cargar un empleado para poder continuar.\n");
					}
					else
					{
						do
						{
							if(!utn_getNumero(	&optionMenu,
												"\n*****Informar*****\n"
												"1 - Lista de Empleados ordenada.\n"
												"2 - Total y Promedio de los salarios.\n"
												"3 - Cantidad de empleados que superan el salario promedio.\n"
												"4 - Volver al Menu Principal.\n"
												"-----------------------------\n"
												"Elija una Opcion del Menu: ",
												"\nERROR",MIN_OPTION_MENU,MAX_OPTION_MENU_INFO,QTY_REINT))
							{
								switch(optionMenu)
								{
									case 1:
										printf("\n***************************************\n");
										if(!utn_getNumero(&auxSort,
														  "Indique como desea ordenar la lista:\n"
														  "1 - Ascendente\n"
														  "0 - Descendente\n"
														  "-----------------------------\n"
														  "Elija una Opcion del Menu: ",
														  "ERROR",ZERO,MAX_SORT,QTY_REINT))
										{
											if(auxSort)
											{
												printf("Lista de Emplados ordenada por Nombre y Sector Ascendente:\n");
												sortEmployees(employees,ARRAY_LEN_EMPLOYEES,auxSort);
												printEmployees(employees,ARRAY_LEN_EMPLOYEES);
											}
											else
											{
												printf("Lista de Emplados ordenada por Nombre y Sector Descendente:\n");
												sortEmployees(employees,ARRAY_LEN_EMPLOYEES,auxSort);
												printEmployees(employees,ARRAY_LEN_EMPLOYEES);
											}

										}
										printf("\n***************************************\n");
										break;
									case 2:
										printf("\n***************************************\n");
										printf("Total y Promedio de los salarios:\n");
										if(!info_PromedioTotalSalarios(&promedio, &totalSalario, employees, ARRAY_LEN_EMPLOYEES))
										{
											printf("El total de los salarios es: %.2f\n", totalSalario);
											printf("El promedio de todos los salarios es: %.2f\n", promedio);
										}
										printf("\n***************************************\n");
										break;
									case 3:
										printf("\n***************************************\n");
										printf("Cantidad de empleados que superan el salario promedio:\n");
										info_PromedioTotalSalarios(&promedio, &totalSalario, employees, ARRAY_LEN_EMPLOYEES);
										if(!info_calcularEmpleadosQueSuperanSalarioPromedio(employees,ARRAY_LEN_EMPLOYEES,promedio,&auxCantidad))
										{
											printf("La cantidad de empleados que superan el salario promedio son: %d\n", auxCantidad);
										}
										printf("\n***************************************\n");
										break;
								}
							}
						}while(optionMenu!=4);
					}
					printf("\n***************************************\n");
			}
		}
	}while(optionMenu);
	return EXIT_SUCCESS;
}
