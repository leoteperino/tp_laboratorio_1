#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define QTY_REINT 2
#define MIN_OPTION_MENU 1
#define MAX_OPTION_MENU 10
#define LEN_NOMBRE 128
#define LEN_ID 999999999

typedef struct
{
    int id;
    char nombre[LEN_NOMBRE];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new(void);
Employee* employee_newParametrosTXT(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldStr);
Employee* employee_newParam(int id, char* nombre, int horasTrabajadas, float sueldo);
int employee_delete(Employee* this);
int employee_sortEmployeesByName(void*, void*);
int employee_sortEmployeesById(void*, void*);
int employee_sortEmployeesByHorasTrabajadas(void*, void*);
int employee_sortEmployeesBySueldo(void*, void*);

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

//Getter y setter Binarios
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

//Getter y Setter de textos
int employee_setIdChar(Employee* this,char* id);
int employee_getIdChar(Employee* this,char* id);
int employee_setHorasTrabajadasChar(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadasChar(Employee* this,char* horasTrabajadas);
int employee_setSueldoChar(Employee* this,char* sueldo);
int employee_getSueldoChar(Employee* this,char* sueldo);

#endif // employee_H_INCLUDED
