#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pacient {
    int id;
    char* nume;
    int varsta;
    float greutate;
    float analize[5];
    int nrMedicamente;
    char** medicamente;
} Pacient;

Pacient crearePacient(int id, const char* nume, int varsta, float greutate, float analize[5]) {
    Pacient p;
    p.id = id;
    p.nume = (char*)malloc(strlen(nume) + 1);
    if (p.nume) {
        strcpy(p.nume, nume);
    }
    p.varsta = varsta;
    p.greutate = greutate;
    for (int i = 0; i < 5; i++) {
        p.analize[i] = analize[i];
    }
    p.nrMedicamente = 0;
    p.medicamente = NULL;
    return p;
}

void afisarePacient(Pacient p) {
    printf("ID: %d\n", p.id);
    printf("Nume: %s\n", p.nume);
    printf("Varsta: %d\n", p.varsta);
    printf("Greutate: %.2f\n", p.greutate);
    printf("Analize: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", p.analize[i]);
    }
    printf("\n");
}

float medieAnalize(float* analize, int nr) {
    float s = 0;
    for (int i = 0; i < nr; i++) {
        s += analize[i];
    }
    return s / nr;
}

int main() {
    float analize[5] = { 4.5f, 5.2f, 6.1f, 5.8f, 4.9f };
    Pacient p = crearePacient(501, "Maria Ionescu", 34, 62.5f, analize);

    p.nrMedicamente = 3;
    p.medicamente = (char**)malloc(p.nrMedicamente * sizeof(char*));
    if (p.medicamente) {
        p.medicamente[0] = (char*)malloc(strlen("Nurofen") + 1);
        p.medicamente[1] = (char*)malloc(strlen("Vitamina C") + 1);
        p.medicamente[2] = (char*)malloc(strlen("Aerius") + 1);

        if (p.medicamente[0]) strcpy(p.medicamente[0], "Nurofen");
        if (p.medicamente[1]) strcpy(p.medicamente[1], "Vitamina C");
        if (p.medicamente[2]) strcpy(p.medicamente[2], "Aerius");
    }

    afisarePacient(p);
    printf("Medie analize: %.2f\n", medieAnalize(p.analize, 5));

    printf("Medicamente:\n");
    for (int i = 0; i < p.nrMedicamente; i++) {
        printf("%s\n", p.medicamente[i]);
    }

    for (int i = 0; i < p.nrMedicamente; i++) {
        free(p.medicamente[i]);
    }
    free(p.medicamente);
    free(p.nume);

    return 0;
}