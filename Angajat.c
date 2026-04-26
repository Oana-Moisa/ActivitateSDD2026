#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Angajat {
    int id;
    char* nume;
    char* departament;
    float salariu;
    int varsta;
    int oreLucrate[5];
    int nrProiecte;
    char** proiecte;
} Angajat;

Angajat creareAngajat(int id, const char* nume, const char* departament, float salariu, int varsta, int oreLucrate[5]) {
    Angajat a;
    a.id = id;

    a.nume = (char*)malloc((strlen(nume) + 1) * sizeof(char));
    strcpy(a.nume, nume);

    a.departament = (char*)malloc((strlen(departament) + 1) * sizeof(char));
    strcpy(a.departament, departament);

    a.salariu = salariu;
    a.varsta = varsta;

    for (int i = 0; i < 5; i++) {
        a.oreLucrate[i] = oreLucrate[i];
    }

    a.nrProiecte = 0;
    a.proiecte = NULL;

    return a;
}

void afisareAngajat(Angajat a) {
    printf("ID: %d\n", a.id);
    printf("Nume: %s\n", a.nume);
    printf("Departament: %s\n", a.departament);
    printf("Salariu: %.2f\n", a.salariu);
    printf("Varsta: %d\n", a.varsta);
    printf("Ore lucrate: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", a.oreLucrate[i]);
    }
    printf("\n");
}

float salariuAnual(float salariu) {
    return salariu * 12;
}

float medieOreLucrate(int* ore, int nr) {
    float suma = 0;
    for (int i = 0; i < nr; i++) {
        suma += ore[i];
    }
    return suma / nr;
}

float calculBonus(float salariu, float procent) {
    return salariu * procent / 100;
}

int main() {
    int ore[5] = { 8, 7, 8, 6, 9 };
    Angajat a = creareAngajat(1, "Popescu Andrei", "IT", 5200.50f, 28, ore);

    a.nrProiecte = 3;
    a.proiecte = (char**)malloc(a.nrProiecte * sizeof(char*));

    a.proiecte[0] = (char*)malloc((strlen("Aplicatie Web") + 1) * sizeof(char));
    strcpy(a.proiecte[0], "Aplicatie Web");

    a.proiecte[1] = (char*)malloc((strlen("Baza de date") + 1) * sizeof(char));
    strcpy(a.proiecte[1], "Baza de date");

    a.proiecte[2] = (char*)malloc((strlen("Testare") + 1) * sizeof(char));
    strcpy(a.proiecte[2], "Testare");

    afisareAngajat(a);
    printf("Salariu anual: %.2f\n", salariuAnual(a.salariu));
    printf("Medie ore lucrate: %.2f\n", medieOreLucrate(a.oreLucrate, 5));
    printf("Bonus: %.2f\n", calculBonus(a.salariu, 10));

    printf("Proiecte:\n");
    for (int i = 0; i < a.nrProiecte; i++) {
        printf("%s\n", a.proiecte[i]);
    }

    for (int i = 0; i < a.nrProiecte; i++) {
        free(a.proiecte[i]);
    }
    free(a.proiecte);
    free(a.nume);
    free(a.departament);

    return 0;
}