//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct Farmacist {
//    unsigned int id;
//    char* nume;
//    float salariu;
//    int varsta;
//    int vanzari[4];
//    int nrBonusuri;
//    float* bonusuri;
//} Farmacist;
//
//Farmacist creareFarmacist(unsigned int id, const char* nume, float salariu, int varsta, int vanzari[4]) {
//    Farmacist f;
//    f.id = id;
//    f.nume = (char*)malloc(strlen(nume) + 1);
//    if (f.nume) {
//        strcpy(f.nume, nume);
//    }
//    f.salariu = salariu;
//    f.varsta = varsta;
//    for (int i = 0; i < 4; i++) {
//        f.vanzari[i] = vanzari[i];
//    }
//    f.nrBonusuri = 0;
//    f.bonusuri = NULL;
//    return f;
//}
//
//void afisareFarmacist(Farmacist f) {
//    printf("ID: %u\n", f.id);
//    printf("Nume: %s\n", f.nume);
//    printf("Salariu: %.2f\n", f.salariu);
//    printf("Varsta: %d\n", f.varsta);
//    printf("Vanzari: ");
//    for (int i = 0; i < 4; i++) {
//        printf("%d ", f.vanzari[i]);
//    }
//    printf("\n");
//}
//
//float salariuAnual(float salariuLunar) {
//    return salariuLunar * 12;
//}
//
//float sumaBonusuri(float* bonusuri, int nr) {
//    float s = 0;
//    for (int i = 0; i < nr; i++) {
//        s += bonusuri[i];
//    }
//    return s;
//}
//
//float medieVanzari(int* vanzari, int nr) {
//    float s = 0;
//    for (int i = 0; i < nr; i++) {
//        s += vanzari[i];
//    }
//    return s / nr;
//}
//
//int main() {
//    int vanzari1[4] = { 20, 25, 30, 28 };
//    Farmacist f = creareFarmacist(101, "Andrei Popescu", 4500.0f, 29, vanzari1);
//
//    afisareFarmacist(f);
//    printf("Salariu anual: %.2f\n", salariuAnual(f.salariu));
//    printf("Medie vanzari: %.2f\n", medieVanzari(f.vanzari, 4));
//
//    f.nrBonusuri = 3;
//    f.bonusuri = (float*)malloc(f.nrBonusuri * sizeof(float));
//    if (f.bonusuri) {
//        f.bonusuri[0] = 300.5f;
//        f.bonusuri[1] = 450.0f;
//        f.bonusuri[2] = 250.0f;
//        printf("Total bonusuri: %.2f\n", sumaBonusuri(f.bonusuri, f.nrBonusuri));
//    }
//
//    free(f.bonusuri);
//    free(f.nume);
//
//    return 0;
//}