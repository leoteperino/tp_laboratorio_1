/*
 ============================================================================
 Name        : trabajoPractico1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

#define QTY_MIN -999999999
#define QTY_MAX 999999999
#define QTY_REINT 2

int main(void) {
	int opcionesMenu;
	float num_a = 0;
	float num_b = 0;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	long resultadoFactorialA;
	long resultadoFactorialB;
	//Menu de Inicio
	do{
		printf( "--Menu de opciones--\n"
				"1. Ingresar primer operando (A=%.2f)\n"
				"2. Ingresar Segundo operando (B=%.2f)\n"
				"3. Calcular todas las operaciones:\n"
				"   a) Calcular la suma (%.2f+%.2f)\n"
				"   b) Calcular la resta (%.2f-%.2f)\n"
				"   c) Calcular la division (%.2f/%.2f)\n"
				"   d) Calcular la multiplicacion (%.2f*%.2f)\n"
				"   e) Calcular el factorial (A=%.2f!) y (B=%.2f!)\n"
				"4. Informar resultados\n"
				"s. Salir\n",
				num_a,
				num_b,
				num_a,
				num_b,
				num_a,
				num_b,
				num_a,
				num_b,
				num_a,
				num_b,
				num_a,
				num_b);
		if(!utn_getInt(	&opcionesMenu,
						"Ingrese la opcion de Menu deseada: ",
						"ERROR",
						QTY_MIN,
						QTY_MAX,
						QTY_REINT))
		{
			//Seteo de la opcion deseada
			switch(opcionesMenu){
					case 1:
						printf("\n*********************************************\n");
						printf("--Opcion 1--\n");
						if(!utn_getFloat(	&num_a,
											"Ingrese un numero: ",
											"ERROR",
											QTY_MIN,
											QTY_MAX,
											QTY_REINT))
						{
							printf("Su numero se cargo con exito!!\n");
						}
						else
						{
							printf("Algo salio mal, se acabaron tus reintentos\n");
						}
						printf("*********************************************\n\n");
						break;
					case 2:
						printf("\n*********************************************\n");
						printf("--Opcion 2--\n");
						if(!utn_getFloat(	&num_b,
											"Ingrese un numero: ",
											"ERROR",
											QTY_MIN,
											QTY_MAX,
											QTY_REINT))
						{
							printf("Su numero se cargo con exito!!\n");
						}
						else
						{
							printf("Algo salio mal, se acabaron tus reintentos\n");
						}
						printf("*********************************************\n\n");
						break;
					case 3:
						printf("\n*********************************************\n");
						printf("--Opcion 3--\n");
						printf( "Calculando Operaciones\n"
								"Para ver los resultados de las operaciones, \n"
								"Ingrese la Opcion 4 del Menu.\n");
						printf("*********************************************\n\n");
						break;
					case 4:
						printf("\n*********************************************\n");
						printf("--Opcion 4--\n");

						if(!utn_sumar(num_a, num_b, &resultadoSuma))
						{
							printf(	"a) El resultado de %.2f + %.2f es: %.2f\n",
									num_a,
									num_b,
									resultadoSuma);
						}
						else
						{
							printf("No se pudo realizar la operacion SUMA\n");
						}

						if(!utn_restar(num_a, num_b, &resultadoResta))
						{
							printf(	"b) El resultado de %.2f - %.2f es: %.2f\n",
									num_a,
									num_b,
									resultadoResta);
						}
						else
						{
							printf("b) No se pudo realizar la operacion RESTA\n");
						}

						if(utn_dividir(num_a, num_b, &resultadoDivision)==0)
						{
							printf("c) El resultado de %.2f/%.2f es: %.2f\n",
									num_a,
									num_b,
									resultadoDivision);
						}
						else if(utn_dividir(num_a, num_b, &resultadoDivision)==-2)
						{
							printf("c) No es posible dividir por 0\n");
						}
						else
						{
							printf("C) No se pudo realizar la operacion DIVISION\n");
						}

						if(!utn_multiplicar(num_a, num_b, &resultadoMultiplicacion))
						{
							printf("d) El resultado de %.2f*%.2f es: %.2f\n",
									num_a,
									num_b,
									resultadoMultiplicacion);
						}
						else
						{
							printf("d) No se pudo realizar la operacion MULTIPLICACION\n");
						}

						if(!utn_factorial(num_a, &resultadoFactorialA))
						{
							printf("e) El factorial de %.2f es: %ld",
									num_a,
									resultadoFactorialA);
						}
						else
						{
							printf("e) No se pudo realizar el calculo del FACTORIAL\n");
						}

						if(!utn_factorial(num_b, &resultadoFactorialB))
						{
							printf(" y el factorial de %.2f es: %ld\n",
									num_b,
									resultadoFactorialB);
						}
						else
						{
							printf("e) No se pudo realizar el calculo del FACTORIAL\n");
						}

						printf("*********************************************\n\n");
						break;
					case 5:
						printf("\n*********************************************\n");
						printf("Gracias por usar la calculadora!!");
						printf("\n*********************************************\n");
						break;
					default:
						printf( "ERROR, Usted ingreso un numero incorrecto.\n"
								"Vuelva a intentarlo.\n\n");
						break;
			}
		}
		else
		{
			printf("Algo salio mal, se acabaron tus reintentos\n\n");
		}
	}while(opcionesMenu != 5);
	return EXIT_SUCCESS;
}
