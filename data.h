#ifndef DATA_H
#define DATA_H

#define MAX_NAME 100
#define MAX_ADDRESS 200
#define MAX_POSITION 100
#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[MAX_NAME];
    char address[MAX_ADDRESS];
    char position[MAX_POSITION];
    char hire_date[11];
    float salary;
} Employee;

void adauga_angajat();
void afiseaza_angajati();
void actualizeaza_angajat();
void sterge_angajat();
void cauta_angajat();
void sorteaza_angajati();

#endif