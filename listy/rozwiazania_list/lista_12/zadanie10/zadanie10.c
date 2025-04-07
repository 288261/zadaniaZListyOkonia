// W pliku przechowywane są informacje o pojazdach należących do bazy transportu. Z
// każdym pojazdem związane są takie informacje jak:

// nr rejestracyjny,
// marka pojazdu,
// jeżeli jest to samochód osobowy, to liczba osób, która może być przewożona, a
// jeżeli samochód ciężarowy, to największa masa ładunku, który może być załadowany
// do pojazdu.
// Należy napisać program, który zapewni:
// wpisanie nowych informacji do pliku,
//  wydruk zawartości pliku,
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nr_rejestracyjny[20];
    char marka[50];
    char typ_pojazdu[20];
    union
    {
        int liczba_osob;
        float masa_ładunku;
    };
} Pojazd;

void dodajPojazd(Pojazd *pojazd)
{
    printf("Numer rejestracyjny: ");
    fgets(pojazd->nr_rejestracyjny, sizeof(pojazd->nr_rejestracyjny), stdin);
    pojazd->nr_rejestracyjny[strcspn(pojazd->nr_rejestracyjny, "\n")] = '\0';

    printf("Marka pojazdu: ");
    fgets(pojazd->marka, sizeof(pojazd->marka), stdin);
    pojazd->marka[strcspn(pojazd->marka, "\n")] = '\0';

    printf("Typ pojazdu (osobowy/ciężarowy): ");
    fgets(pojazd->typ_pojazdu, sizeof(pojazd->typ_pojazdu), stdin);
    pojazd->typ_pojazdu[strcspn(pojazd->typ_pojazdu, "\n")] = '\0';

    if (strcmp(pojazd->typ_pojazdu, "osobowy") == 0)
    {
        printf("Liczba osób, które mogą być przewożone: ");
        scanf("%d", &pojazd->liczba_osob);
    }
    else if (strcmp(pojazd->typ_pojazdu, "ciężarowy") == 0)
    {
        printf("Maksymalna masa ładunku (w tonach): ");
        scanf("%f", &pojazd->masa_ładunku);
    }

    while (getchar() != '\n');
}

void zapiszDoPliku(Pojazd *pojazdy, int liczba_pojazdow, const char *nazwa_pliku)
{
    FILE *plik = fopen(nazwa_pliku, "w");

    if (plik == NULL)
    {
        printf("Nie udało się otworzyć pliku do zapisu.\n");
        return;
    }

    for (int i = 0; i < liczba_pojazdow; i++)
    {
        fprintf(plik, "Pojazd %d:\n", i + 1);
        fprintf(plik, "Numer rejestracyjny: %s\n", pojazdy[i].nr_rejestracyjny);
        fprintf(plik, "Marka pojazdu: %s\n", pojazdy[i].marka);
        fprintf(plik, "Typ pojazdu: %s\n", pojazdy[i].typ_pojazdu);

        if (strcmp(pojazdy[i].typ_pojazdu, "osobowy") == 0)
        {
            fprintf(plik, "Liczba osób: %d\n", pojazdy[i].liczba_osob);
        }
        else if (strcmp(pojazdy[i].typ_pojazdu, "ciężarowy") == 0)
        {
            fprintf(plik, "Masa ładunku: %.2f ton\n", pojazdy[i].masa_ładunku);
        }

        fprintf(plik, "\n");
    }

    fclose(plik);
    printf("Pojazdy zostały zapisane do pliku '%s'.\n", nazwa_pliku);
}

void wypiszZPliku(const char *nazwa_pliku)
{
    FILE *plik = fopen(nazwa_pliku, "r");

    if (plik == NULL)
    {
        printf("Nie udało się otworzyć pliku do odczytu.\n");
        return;
    }

    char znak;
    printf("\nZawartość pliku '%s':\n", nazwa_pliku);
    while ((znak = fgetc(plik)) != EOF)
    {
        putchar(znak);
    }

    fclose(plik);
}

int main()
{
    int liczba_pojazdow;

    printf("Ile pojazdów chcesz dodać? ");
    scanf("%d", &liczba_pojazdow);

    while (getchar() != '\n');

    Pojazd *pojazdy = (Pojazd *)malloc(liczba_pojazdow * sizeof(Pojazd));

    if (pojazdy == NULL)
    {
        printf("Błąd alokacji pamięci!\n");
        return 1;
    }

    for (int i = 0; i < liczba_pojazdow; i++)
    {
        printf("\nPodaj dane pojazdu %d:\n", i + 1);
        dodajPojazd(&pojazdy[i]);
    }

    zapiszDoPliku(pojazdy, liczba_pojazdow, "pojazdy.txt");

    wypiszZPliku("pojazdy.txt");

    free(pojazdy);

    return 0;
}
