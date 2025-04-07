// W pliku przechowywane są informacje o mieszkaniach będących w dyspozycji pewnej spółdzielni. Dla każdego mieszkania pamiętane jest:
// adres,
// powierzchnia mieszkalna,
// liczba pokoi,
// numer piętra,
// cena.
// Należy napisać program, który zapewni:
// wpisanie nowych informacji do pliku,
// wydruk zawartości pliku.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char adres[100];
    float powierzchnia;
    int liczba_pokoi;
    int numer_pietra;
    float cena;
} Mieszkanie;

void dodajMieszkanie(Mieszkanie *mieszkanie) {
    printf("Adres mieszkania: ");
    fgets(mieszkanie->adres, sizeof(mieszkanie->adres), stdin);
    mieszkanie->adres[strcspn(mieszkanie->adres, "\n")] = '\0';

    printf("Powierzchnia mieszkalna (w m2): ");
    scanf("%f", &mieszkanie->powierzchnia);

    printf("Liczba pokoi: ");
    scanf("%d", &mieszkanie->liczba_pokoi);

    printf("Numer piętra: ");
    scanf("%d", &mieszkanie->numer_pietra);

    printf("Cena mieszkania: ");
    scanf("%f", &mieszkanie->cena);

    while (getchar() != '\n'); // Oczyszczenie bufora po scanf
}

void zapiszDoPliku(Mieszkanie *mieszkania, int liczba_mieszkan, const char *nazwa_pliku) {
    FILE *plik = fopen(nazwa_pliku, "w");

    if (plik == NULL) {
        printf("Nie udało się otworzyć pliku do zapisu.\n");
        return;
    }

    for (int i = 0; i < liczba_mieszkan; i++) {
        fprintf(plik, "Mieszkanie %d:\n", i + 1);
        fprintf(plik, "Adres: %s\n", mieszkania[i].adres);
        fprintf(plik, "Powierzchnia: %.2f m2\n", mieszkania[i].powierzchnia);
        fprintf(plik, "Liczba pokoi: %d\n", mieszkania[i].liczba_pokoi);
        fprintf(plik, "Numer piętra: %d\n", mieszkania[i].numer_pietra);
        fprintf(plik, "Cena: %.2f PLN\n\n", mieszkania[i].cena);
    }

    fclose(plik);
    printf("Mieszkania zostały zapisane do pliku '%s'.\n", nazwa_pliku);
}

void wypiszZPliku(const char *nazwa_pliku) {
    FILE *plik = fopen(nazwa_pliku, "r");

    if (plik == NULL) {
        printf("Nie udało się otworzyć pliku do odczytu.\n");
        return;
    }

    char znak;
    printf("\nZawartość pliku '%s':\n", nazwa_pliku);
    while ((znak = fgetc(plik)) != EOF) {
        putchar(znak);
    }

    fclose(plik);
}

int main() {
    int liczba_mieszkan;

    printf("Ile mieszkań chcesz dodać? ");
    scanf("%d", &liczba_mieszkan);

    while (getchar() != '\n'); // Oczyszczenie bufora po scanf

    Mieszkanie *mieszkania = (Mieszkanie *)malloc(liczba_mieszkan * sizeof(Mieszkanie));

    if (mieszkania == NULL) {
        printf("Błąd alokacji pamięci!\n");
        return 1;
    }

    for (int i = 0; i < liczba_mieszkan; i++) {
        printf("\nPodaj dane mieszkania %d:\n", i + 1);
        dodajMieszkanie(&mieszkania[i]);
    }

    zapiszDoPliku(mieszkania, liczba_mieszkan, "mieszkania.txt");

    wypiszZPliku("mieszkania.txt");

    free(mieszkania);

    return 0;
}
