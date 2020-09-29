/*
 * informes.h
 *
 *  Created on: Sep 29, 2020
 *      Author: leandro
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int info_PromedioTotalSalarios(float* pPromedio, float* pTotalSalario, Employee* list, int len);
int info_calcularEmpleadosQueSuperanSalarioPromedio(Employee* list, int len, float promedio, int* pResultado);
int checkListaVacia(Employee* list, int len);

#endif /* INFORMES_H_ */
