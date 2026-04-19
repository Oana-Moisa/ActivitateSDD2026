//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct student {
//    unsigned int id;
//    char serie;
//    unsigned char nr;
//    char* nume;
//    int note[5];
//    int nrOptionale;
//    int* noteOptional;
//    int nrCuvinte;
//    char** descriere;
//} student;
//
//student creareStudent(unsigned int id, const char* nume, int note[5]) {
//    student s;
//    s.id = id;
//
//    s.nume = (char*)malloc((strlen(nume) + 1) * sizeof(char));
//    if (s.nume) {
//        strcpy(s.nume, nume);
//    }
//
//    for (int i = 0; i < 5; i++) {
//        s.note[i] = note[i];
//    }
//
//    s.nrOptionale = 0;
//    s.noteOptional = NULL;
//    s.nrCuvinte = 0;
//    s.descriere = NULL;
//
//    return s;
//}
//
//void afisareStudent(student s) {
//    printf("ID: %u, Nume: %s, Note: ", s.id, s.nume);
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", s.note[i]);
//    }
//    printf("\n");
//}
//
//int functie(int x) {
//    return 2 * x + 3;
//}
//
//void afisareMesaj(const char* mesaj) {
//    printf("%s\n", mesaj);
//}
//
//int suma(int a, int b) {
//    return a + b;
//}
//
//int suma2(int* pa, int* pb) {
//    return *pa + *pb;
//}
//
//int main() {
//    printf("Suma 3 + 10: %d\n", suma(3, 10));
//
//    int a = 3;
//    int* pa = &a;
//    printf("Adresa lui a: %p\n", &a);
//    printf("Valoarea lui a prin pointer: %d\n", *pa);
//
//    int b = 10;
//    printf("Suma a + b prin pointeri: %d\n", suma2(pa, &b));
//
//    int v1[5] = { 4, 2, 7, 3, 9 };
//
//    int dim = 5;
//    int* vd = (int*)malloc(dim * sizeof(int));
//    if (vd) {
//        vd[0] = 4;
//        vd[1] = 14;
//        vd[2] = 24;
//        vd[3] = 34;
//        vd[4] = 44;
//        free(vd);
//    }
//
//    printf("Adrese elemente vector static:\n");
//    for (int i = 0; i < 5; i++) {
//        printf("v[%d]: %p\n", i, (v1 + i));
//    }
//
//    printf("Valori accesate prin pointeri:\n");
//    for (int i = 0; i < 5; i++) {
//        printf("*(v + %d) = %d\n", i, *(v1 + i));
//    }
//
//    int* p = v1;
//    printf("Prima valoare prin pointer: %d\n", *p);
//    p++;
//    *p = 12;
//    printf("Noua valoare a lui v1[1]: %d\n", *(v1 + 1));
//
//    p = &v1[2];
//    *p = 17;
//    p = v1 + 3;
//    *p = 13;
//
//    *(v1 + 4) = 99;
//    printf("Vector dupa modificari:\n");
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", v1[i]);
//    }
//    printf("\n");
//
//    int note1[5] = { 10, 7, 8, 9, 9 };
//    student s = creareStudent(111, "Mara", note1);
//    afisareStudent(s);
//
//    free(s.nume);
//
//    return 0;
//}