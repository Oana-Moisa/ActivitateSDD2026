#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carte {
    int id;
    char* titlu;
    char* autor;
    float pret;
    int nrPagini;
    int note[5];
    int nrCapitole;
    char** capitole;
} Carte;

Carte creareCarte(int id, const char* titlu, const char* autor, float pret, int nrPagini, int note[5]) {
    Carte c;
    c.id = id;

    c.titlu = (char*)malloc((strlen(titlu) + 1) * sizeof(char));
    strcpy(c.titlu, titlu);

    c.autor = (char*)malloc((strlen(autor) + 1) * sizeof(char));
    strcpy(c.autor, autor);

    c.pret = pret;
    c.nrPagini = nrPagini;

    for (int i = 0; i < 5; i++) {
        c.note[i] = note[i];
    }

    c.nrCapitole = 0;
    c.capitole = NULL;

    return c;
}

void afisareCarte(Carte c) {
    printf("ID: %d\n", c.id);
    printf("Titlu: %s\n", c.titlu);
    printf("Autor: %s\n", c.autor);
    printf("Pret: %.2f\n", c.pret);
    printf("Numar pagini: %d\n", c.nrPagini);
    printf("Note: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", c.note[i]);
    }
    printf("\n");
}

float calculMedieNote(int* note, int nr) {
    float suma = 0;
    for (int i = 0; i < nr; i++) {
        suma += note[i];
    }
    return suma / nr;
}

float calculPretCuReducere(float pret, float reducere) {
    return pret - pret * reducere / 100;
}

int sumaPagini(int a, int b) {
    return a + b;
}

int main() {
    int note[5] = { 10, 9, 8, 10, 9 };
    Carte c = creareCarte(1, "Programare in C", "Ion Popescu", 59.99f, 320, note);

    c.nrCapitole = 3;
    c.capitole = (char**)malloc(c.nrCapitole * sizeof(char*));

    c.capitole[0] = (char*)malloc((strlen("Introducere") + 1) * sizeof(char));
    strcpy(c.capitole[0], "Introducere");

    c.capitole[1] = (char*)malloc((strlen("Pointeri") + 1) * sizeof(char));
    strcpy(c.capitole[1], "Pointeri");

    c.capitole[2] = (char*)malloc((strlen("Structuri") + 1) * sizeof(char));
    strcpy(c.capitole[2], "Structuri");

    afisareCarte(c);
    printf("Medie note: %.2f\n", calculMedieNote(c.note, 5));
    printf("Pret redus: %.2f\n", calculPretCuReducere(c.pret, 15));
    printf("Suma pagini cu inca o carte de 280 pagini: %d\n", sumaPagini(c.nrPagini, 280));

    printf("Capitole:\n");
    for (int i = 0; i < c.nrCapitole; i++) {
        printf("%s\n", c.capitole[i]);
    }

    for (int i = 0; i < c.nrCapitole; i++) {
        free(c.capitole[i]);
    }
    free(c.capitole);
    free(c.titlu);
    free(c.autor);

    return 0;
}