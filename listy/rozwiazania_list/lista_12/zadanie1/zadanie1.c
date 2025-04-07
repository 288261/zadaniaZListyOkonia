// Napisać program wczytujący jedną datę i aktualny kurs dolara. Dopisać wczytywane
// dane do zbioru. Wydrukować całą (zawartą w zbiorze) historię zmian kursu dolara.
#include <stdio.h>
#include <stdlib.h>

typedef struct Kurs
{
    char data[11];
    float cena;
} Kurs;

void zapiszDoPliku(struct Kurs *kurs)
{
    FILE *plik = fopen("kursy.txt", "a");

    if (plik == NULL)
    {
        printf("Nie mozna otworzyc pliku!\n");
        exit(1);
    }

    fprintf(plik, "%s %.2f\n", kurs->data, kurs->cena);

    fclose(plik);
}

void wyswietlPlik()
{
    FILE *plik = fopen("kursy.txt", "r");

    char data[11];
    float cena;

    if (plik == NULL)
    {
        printf("Nie mozna otworzyc pliku!\n");
        exit(1);
    }

    printf("Historia kursu dolara: \n");
    while (fscanf(plik, "%s", data) != EOF)
    {
        fscanf(plik, "%f", &cena);
        printf("%s %.2f\n", data, cena);
    }

    fclose(plik);
}

int main()
{
    Kurs *kurs = malloc(sizeof(Kurs));

    printf("Podaj date: ");
    scanf("%s", kurs->data);

    printf("Podaj kurs dolara: ");
    scanf("%f", &kurs->cena);

    zapiszDoPliku(kurs);
    wyswietlPlik();

    free(kurs);

    return 0;
}