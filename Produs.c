//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct {
//    int id;
//    float pret;
//    char* denumire;
//    int* stocMagazine;
//    int nrMagazine;
//} Produs;
//
//Produs creareConsola() {
//    Produs p;
//    printf("Introduceti ID-ul produsului: ");
//    scanf("%d", &p.id);
//
//    printf("Introduceti pretul produsului: ");
//    scanf("%f", &p.pret);
//
//    p.denumire = (char*)malloc(50 * sizeof(char));
//    printf("Introduceti denumirea produsului: ");
//    scanf("%s", p.denumire);
//
//    printf("Introduceti numarul de magazine: ");
//    scanf("%d", &p.nrMagazine);
//
//    p.stocMagazine = (int*)malloc(p.nrMagazine * sizeof(int));
//    for (int i = 0; i < p.nrMagazine; i++) {
//        printf("Introduceti stocul pentru magazinul %d: ", i + 1);
//        scanf("%d", &p.stocMagazine[i]);
//    }
//    return p;
//}
//
//void afisareProdus(Produs p) {
//    printf("ID: %d\n", p.id);
//    printf("Pret: %.2f\n", p.pret);
//    printf("Denumire: %s\n", p.denumire);
//    printf("Stocuri in magazine: ");
//    for (int i = 0; i < p.nrMagazine; i++) {
//        printf("%d ", p.stocMagazine[i]);
//    }
//    printf("\n");
//}
//
//int calculStocTotal(Produs p) {
//    int total = 0;
//    for (int i = 0; i < p.nrMagazine; i++) {
//        total += p.stocMagazine[i];
//    }
//    return total;
//}
//
//void scriereFisierBinarDirect(Produs* produse, int nrProduse, const char* filename) {
//    FILE* file = fopen(filename, "wb");
//    if (!file) {
//        printf("Eroare la deschiderea fisierului.\n");
//        return;
//    }
//    fwrite(&nrProduse, sizeof(int), 1, file);
//    for (int i = 0; i < nrProduse; i++) {
//        fwrite(&produse[i].id, sizeof(int), 1, file);
//        fwrite(&produse[i].pret, sizeof(float), 1, file);
//        char buffer[50] = { 0 };
//        strncpy(buffer, produse[i].denumire, 50);
//        fwrite(buffer, sizeof(char), 50, file);
//        fwrite(&produse[i].nrMagazine, sizeof(int), 1, file);
//        fwrite(produse[i].stocMagazine, sizeof(int), produse[i].nrMagazine, file);
//    }
//    fclose(file);
//}
//
//Produs* citireFisierBinar(const char* filename, int* nrProduse) {
//    FILE* file = fopen(filename, "rb");
//    if (!file) {
//        printf("Eroare la deschiderea fisierului.\n");
//        return NULL;
//    }
//    fread(nrProduse, sizeof(int), 1, file);
//    Produs* produse = (Produs*)malloc((*nrProduse) * sizeof(Produs));
//    for (int i = 0; i < *nrProduse; i++) {
//        fread(&produse[i].id, sizeof(int), 1, file);
//        fread(&produse[i].pret, sizeof(float), 1, file);
//        produse[i].denumire = (char*)malloc(50 * sizeof(char));
//        fread(produse[i].denumire, sizeof(char), 50, file);
//        fread(&produse[i].nrMagazine, sizeof(int), 1, file);
//        produse[i].stocMagazine = (int*)malloc(produse[i].nrMagazine * sizeof(int));
//        fread(produse[i].stocMagazine, sizeof(int), produse[i].nrMagazine, file);
//    }
//    fclose(file);
//    return produse;
//}
//
//void dezalocareProdus(Produs* p) {
//    free(p->denumire);
//    free(p->stocMagazine);
//}
//
//int main() {
//    int nrProduse;
//    printf("Introduceti numarul de produse: ");
//    scanf("%d", &nrProduse);
//
//    Produs* produse = (Produs*)malloc(nrProduse * sizeof(Produs));
//    for (int i = 0; i < nrProduse; i++) {
//        printf("Citire produs %d:\n", i + 1);
//        produse[i] = creareConsola();
//    }
//
//    printf("Produsele introduse:\n");
//    for (int i = 0; i < nrProduse; i++) {
//        afisareProdus(produse[i]);
//    }
//
//    scriereFisierBinarDirect(produse, nrProduse, "produse.dat");
//
//    int nrCitite;
//    Produs* produseCitite = citireFisierBinar("produse.dat", &nrCitite);
//    if (produseCitite) {
//        printf("Produse citite din fisier:\n");
//        for (int i = 0; i < nrCitite; i++) {
//            afisareProdus(produseCitite[i]);
//            dezalocareProdus(&produseCitite[i]);
//        }
//        free(produseCitite);
//    }
//
//    for (int i = 0; i < nrProduse; i++) {
//        dezalocareProdus(&produse[i]);
//    }
//    free(produse);
//
//    return 0;
//}