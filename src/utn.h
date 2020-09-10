/*
 * utn.h
 *
 *  Created on: Sep 5, 2020
 *      Author: leandro
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int* pResultado, char* pMensaje, char* pError, int minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError, float min, float max, int reintentos);
int utn_getChar(char* pResultado, char* pMensaje, char* pMensajeError, char min, char max, int reintentos);
void utn_cargandoArrayInt(int Array[], int len, int min, int max, int reintentos);
void utn_imprimirArrayInt(int Array[], int len);
int utn_promedioArrayInt(int Array[], int len, float* pResultado);
int utn_sumar(float num_a, float num_b,  float* pResultado);
int utn_restar(float num_a, float num_b,  float* pResultado);
int utn_dividir(float num_a, float num_b, float* pResultado);
int utn_multiplicar(float num_a, float num_b,  float* pResultado);
int utn_factorial(int num_a, long* pResultado);

#endif /* UTN_H_ */
