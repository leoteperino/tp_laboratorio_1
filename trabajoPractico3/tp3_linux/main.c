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
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
				printf("2\n");
				break;
            case 3:
            	printf("3\n");
				break;
            case 4:
            	printf("4\n");
				break;
            case 5:
            	printf("5\n");
				break;
            case 6:
            	printf("6\n");
				break;
            case 7:
            	printf("7\n");
				break;
            case 8:
            	printf("8\n");
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

