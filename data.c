#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

void adauga_angajat() {
    FILE *f = fopen("angajati.txt", "a");
    if (!f) {
        printf("\033[0;31m");
        printf(" | Eroare la deschiderea fisierului.\n"); 
        printf("\033[0m");
        
        return;
    }

    Employee emp;
    printf("===== ADAUGARE ANGAJATI =====\n\n");
    printf(" | ID: "); scanf("%d", &emp.id); getchar();
    printf(" | Nume (complet): "); fgets(emp.name, MAX_NAME, stdin); strtok(emp.name, "\n");
    printf(" | Adresa (completa): "); fgets(emp.address, MAX_ADDRESS, stdin); strtok(emp.address, "\n");
    printf(" | Post: "); fgets(emp.position, MAX_POSITION, stdin); strtok(emp.position, "\n");
    printf(" | Data angajarii (dd/mm/yyyy): "); fgets(emp.hire_date, 11, stdin); strtok(emp.hire_date, "\n");
    printf(" | Salariu: "); scanf("%f", &emp.salary); getchar();

    fprintf(f, "\n%d\n%s\n%s\n%s\n%s\n%.2f\n", 
            emp.id, emp.name, emp.address, emp.position, emp.hire_date, emp.salary);

    fclose(f);
    printf("\033[0;32m");
    printf(" | Angajat adaugat cu succes!\n");
    printf("\033[0m");
}

void afiseaza_angajati() {
    FILE *f = fopen("angajati.txt", "r");
    if (!f) {
        printf("\033[0;31m");
        printf("| Nu exista angajati sau nu s-a putut deschide fisierul.\n");
        printf("\033[0m");
        
        return;
    }

    Employee emp;

    printf("===== AFISARE ANGAJATI =====\n");
    while (fscanf(f, "%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%f\n", 
           &emp.id, emp.name, emp.address, emp.position, emp.hire_date, &emp.salary) == 6) {
        
        printf("\n | ID: %d\n | Nume: %s\n | Adresa: %s\n | Post: %s\n | Data Angajare: %s\n | Salariu: %.2f\n",
               emp.id, emp.name, emp.address, emp.position, emp.hire_date, emp.salary);
    }

    fclose(f);
}

void actualizeaza_angajat() {
    int id, found = 0;
    printf("===== ACTUALIZARE DATE ANGAJATI =====\n");
    printf(" | ID-ul angajatului: "); scanf("%d", &id); getchar();

    FILE *f = fopen("angajati.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!f || !temp) {
        printf("\033[0;31m"); 
        printf(" | Eroare la deschiderea fisierului.\n");
        printf("\033[0m");
        return;
    }

    Employee emp;
    while (fscanf(f, "%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%f\n", 
            &emp.id, emp.name, emp.address, emp.position, emp.hire_date, &emp.salary) == 6) {
        if (emp.id == id) {
            printf(" | Introduceti noile date:\n");
            printf(" | Nume (complet): "); fgets(emp.name, MAX_NAME, stdin); strtok(emp.name, "\n");
            printf(" | Adresa (completa): "); fgets(emp.address, MAX_ADDRESS, stdin); strtok(emp.address, "\n");
            printf(" | Post: "); fgets(emp.position, MAX_POSITION, stdin); strtok(emp.position, "\n");
            printf(" | Data angajarii (dd/mm/yyyy): "); fgets(emp.hire_date, 11, stdin); strtok(emp.hire_date, "\n");
            printf(" | Salariu: "); scanf("%f", &emp.salary); getchar();
            found = 1;
        }
        fprintf(temp, "%d\n%s\n%s\n%s\n%s\n%.2f\n", 
                emp.id, emp.name, emp.address, emp.position, emp.hire_date, emp.salary);
    }

    fclose(f);
    fclose(temp);

    remove("angajati.txt");
    rename("temp.txt", "angajati.txt");

    if (found) {
        printf("\033[0;32m");
        printf("\n | Angajat actualizat cu succes.\n");
        printf("\033[0m");
    } else {
        printf("\033[0;31m"); 
        printf("\n | Angajatul nu a fost gasit.\n");
        printf("\033[0m");
    }
}

void sterge_angajat() {
    int id;
    printf("===== STERGERE ANGAJAT =====\n");
    printf(" | ID angajat de sters: "); scanf("%d", &id); getchar();

    FILE *f = fopen("angajati.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!f || !temp) {
        printf("\033[0;31m"); 
        printf("\n | Eroare la deschiderea fisierului.\n");
        printf("\033[0m");
        return;
    }

    Employee emp;
    int found = 0;
    while (fscanf(f, "%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%f\n", 
            &emp.id, emp.name, emp.address, emp.position, emp.hire_date, &emp.salary) == 6) {
        if (emp.id != id) {
            fprintf(temp, "%d\n%s\n%s\n%s\n%s\n%.2f\n", 
                    emp.id, emp.name, emp.address, emp.position, emp.hire_date, emp.salary);
        } else {
            found = 1;
        }
    }

    fclose(f);
    fclose(temp);

    remove("angajati.txt");
    rename("temp.txt", "angajati.txt");

    if (found) {
        printf("\033[0;32m");
        printf("\n | Angajat sters cu succes.\n");
        printf("\033[0m");
    } else {
        printf("\033[0;31m");
        printf("\n | Angajatul nu a fost gasit.\n");
        printf("\033[0m");
    }
}

void cauta_angajat() {
    char nume[MAX_NAME], post[MAX_POSITION];
    printf("===== CAUTARE ANGAJAT =====\n");
    printf("\n | Nume (Enter pentru a sari): "); fgets(nume, MAX_NAME, stdin); strtok(nume, "\n");
    printf(" | Post (Enter pentru a sari): "); fgets(post, MAX_POSITION, stdin); strtok(post, "\n");

    FILE *f = fopen("angajati.txt", "r");
    if (!f) {
        printf("\033[0;31m"); 
        printf(" | Eroare la deschiderea fisierului.\n");
        printf("\033[0m");
        return;
    }

    Employee emp;
    int gasit = 0;
    while (fscanf(f, "%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%f\n", 
            &emp.id, emp.name, emp.address, emp.position, emp.hire_date, &emp.salary) == 6) {
        if ((strlen(nume) == 0 || strstr(emp.name, nume)) ||
            (strlen(post) == 0 || strstr(emp.position, post))) {
            printf("\n | ID: %d\n | Nume: %s\n | Adresa: %s\n | Post: %s\n | Salariu: %.2f\n", emp.id, emp.name, emp.address, emp.position, emp.salary);
            gasit = 1;
        }
    }

    if (!gasit) {
        printf("\033[0;31m");
        printf("\n | Nici un angajat gasit.\n");
        printf("\033[0m");
    }
    fclose(f);
}

int compara(const void *a, const void *b) {
    Employee *empA = (Employee *)a;
    Employee *empB = (Employee *)b;

    return strcmp(empA->name, empB->name);
}

void sorteaza_angajati() {
    FILE *f = fopen("angajati.txt", "r");
    if (!f) {
        printf("\033[0;31m"); 
        printf(" | Eroare la deschiderea fisierului.\n");
        printf("\033[0m");
        return;
    }

    Employee list[MAX_EMPLOYEES];
    int count = 0;

    while (fscanf(f, "%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%f\n", 
            &list[count].id, list[count].name, list[count].address, 
            list[count].position, list[count].hire_date, &list[count].salary) == 6) {
        count++;
    }

    fclose(f);

    qsort(list, count, sizeof(Employee), compara);

    printf("===== SORTARE ALFABETICA =====\n");
    for (int i = 0; i < count; i++) {
        printf("\n | ID: %d\n | Nume: %s\n | Post: %s\n | Salariu: %.2f\n", 
               list[i].id, list[i].name, list[i].position, list[i].salary);
    }
}
