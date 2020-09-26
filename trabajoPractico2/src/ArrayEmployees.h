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

typedef struct
{
	int id;
	char name[ARRAY_NAME_LEN];
	char lastName[ARRAY_LASTNAME_LEN];
	float salary;
	int sector;
	int isEmpty;
}Employee;

#endif /* ARRAYEMPLOYEES_H_ */
