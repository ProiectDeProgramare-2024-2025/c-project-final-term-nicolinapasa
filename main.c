#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main()
{
    int option;
    do
    {
        clear_screen();
        printf("\n");
        printf("===== MENIU PRINCIPAL =====\n");
        printf(" | 0 - Exit\n");
        printf(" | 1 - Afisarea angajatilor.\n");
        printf(" | 2 - Adaugare angajat.\n");
        printf(" | 3 - Actualizare date angajat.\n");
        printf(" | 4 - Stergere angajat.\n");
        printf(" | 5 - Cautare angajat dupa nume si/sau postul ocupat.\n");
        printf(" | 6 - Sortare alfabetica a angajatilor.\n");
        printf("Introduceti optiunea dorita: ");
        scanf("%d", &option);
        getchar();
        printf("\n");
        
        clear_screen();
        switch (option) {
            case 1: afiseaza_angajati(); break;
            case 2: adauga_angajat(); break;
            case 3: actualizeaza_angajat(); break;
            case 4: sterge_angajat(); break;
            case 5: cauta_angajat(); break;
            case 6: sorteaza_angajati(); break;
            case 0: {
                printf("\033[0;36m");
                printf("Exit"); break;
                printf("\033[0m");
            }
            default: {
                printf("\033[0;31m");
                printf("\n | Optiune invalida.\n");
                printf("\033[0m");
            }
        }
        if (option != 0) {
            printf("\033[0;36m");
            printf("\nApasa Enter pentru a reveni la meniul principal ↑");
            printf("\033[0m");
            getchar();
        }
    } while (option != 0);

    return 0;
}