#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	if(!utn_getNumero(   &option,
							"\n*****Menu de Opciones*****\n"
							"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
							"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
							"3. Alta de empleado.\n"
							"4. Modificar datos de empleado.\n"
							"5. Baja de empleado.\n"
							"6. Listar empleados.\n"
							"7. Ordenar empleados.\n"
							"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    						"9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    						"10. Salir.\n"
							"-----------------------------\n"
							"Elija una opcion del menu: ",
							"ERROR",MIN_OPTION_MENU,MAX_OPTION_MENU,QTY_REINT))
        switch(option)
        {
            case 1:
            	if(!controller_loadFromText("data.csv",listaEmpleados))
            	{
            		printf("Los datos fueron cargados con exito!!\n");
            	}
            	else
            	{
            		printf("ERROR, no se cargaron los datos\n");
            	}
                break;
            case 2:
				printf("2\n");
				break;
            case 3:
            	if(!controller_addEmployee(listaEmpleados))
            	{
            		printf("Se cargo un nuevo empleado!!");
            	}
            	else
				{
					printf("ERROR, no se cargaron los datos\n");
				}
				break;
            case 4:
            	controller_editEmployee(listaEmpleados);
				break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
				break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
				break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
				break;
            case 8:
            	controller_saveAsText("data.csv", listaEmpleados);
				break;
            case 9:
            	printf("9\n");
				break;
            case 10:
            	printf("Hasta luego!!\n");
				break;
        }
    }while(option != 10);
    return 0;
}

