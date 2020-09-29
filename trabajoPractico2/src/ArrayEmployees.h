/*
 * ArrayEmployees.h
 *
 *  Created on: Sep 26, 2020
 *      Author: leandro
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define ARRAY_NAME_LEN 51
#define ARRAY_LASTNAME_LEN 51
#define ZERO 0
#define QTY_REINT 3
#define TRUE 1
#define FALSE 0
#define ARRAY_LEN_EMPLOYEES 1000
#define MIN_OPTION_MENU 1
#define MAX_OPTION_MENU 4
#define MAX_OPTION_MENU_INFO 5
#define MAX_SALARY 999999
#define MAX_SECTOR 50
#define MAX_ID 999999

typedef struct
{
	int id;
	char name[ARRAY_NAME_LEN];
	char lastName[ARRAY_LASTNAME_LEN];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int findEmployeeById(Employee* list, int len,int id);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int printEmployees(Employee* list, int len);
int buscarVacio(Employee* list, int len);
int mocksEmployees(Employee* list, int len, int indice, int id, char* name,char* lastName,float salary,int sector);

#endif /* ARRAYEMPLOYEES_H_ */
