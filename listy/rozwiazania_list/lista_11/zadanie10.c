// W tablicy struktur przechowywane są dane o osobach. Dla jednej osoby
// pamiętane jest nazwisko i imię oraz wysokość poborów. Uporządkować
// tablicę w ten sposób, by w początkowej części w kolejności malenia
// poborów były przechowywane dane o osobach posiadających pobory większe
// od a, a w drugiej części w kolejności alfabetycznej nazwisk i imion dane
// o osobach posiadających pobory mniejsze od liczby a.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Osoba
{
    char imie[20];
    char nazwisko[30];
    float pobor;
} Osoba;

void wprowadzDane(struct Osoba *osoba)
{
    printf("Podaj imie: ");
    scanf("%19s", osoba->imie);

    printf("Podaj nazwisko: ");
    scanf("%29s", osoba->nazwisko);

    printf("Podaj liczbe: ");
    scanf("%f", &osoba->pobor);
}

int porownajLiczbyWieksze(const void *a, const void *b)
{
    struct Osoba *osb1 = (struct Osoba *)a;
    struct Osoba *osb2 = (struct Osoba *)b;

    if (osb1->pobor == osb2->pobor)
    {
        if (osb1->pobor > osb2->pobor)
            return -1;
        else
            return 1;
    }
    if (osb1->pobor > osb2->pobor)
        return -1;
    if (osb1->pobor < osb2->pobor)
        return 1;

    return 0;
}

int porownajLiczbyMniejsze(const void *a, const void *b)
{
    struct Osoba *osb1 = (struct Osoba *)a;
    struct Osoba *osb2 = (struct Osoba *)b;

    if (strcmp(osb1->nazwisko, osb2->nazwisko) == 0)
    {
        if (osb1->imie > osb2->imie)
            return -1;
        else
            return 1;
    }
    if (osb1->nazwisko > osb2->nazwisko)
        return -1;
    if (osb1->nazwisko < osb2->nazwisko)
        return 1;

    return 0;
}

void wyswietlOsoby(Osoba *osoby, int ileLiczb)
{
    for (int i = 0; i < ileLiczb; i++)
    {
        printf("Nazwisko i imie: %s %s, pobor: %.2f\n", osoby[i].nazwisko, osoby[i].imie, osoby[i].pobor);
    }
}

int main()
{
    int ileOsob;
    int a;

    printf("Ile chcesz podac osob: ");
    scanf("%d", &ileOsob);

    printf("Podaj prog liczby a: ");
    scanf("%d", &a);

    Osoba *osoby = (Osoba *)malloc(ileOsob * sizeof(Osoba));

    for (int i = 0; i < ileOsob; i++)
    {
        wprowadzDane(&osoby[i]);
    }

    int ileWiecejLiczb = 0;
    int ileMniejLiczb = 0;

    for (int i = 0; i < ileOsob; i++)
    {
        if (osoby[i].pobor > a)
            ileWiecejLiczb += 1;
        else if (osoby[i].pobor < a)
            ileMniejLiczb += 1;
    }

    Osoba *osobyMniej = (Osoba *)malloc(ileMniejLiczb * sizeof(Osoba));
    Osoba *osobyWiecej = (Osoba *)malloc(ileWiecejLiczb * sizeof(Osoba));

    int indexMniej = 0;
    int indexWiecej = 0;

    for (int i = 0; i < ileOsob; i++)
    {
        if (osoby[i].pobor > a)
        {
            osobyWiecej[indexWiecej] = osoby[i];
            indexWiecej++;
        }
        else if (osoby[i].pobor < a)
        {
            osobyMniej[indexMniej] = osoby[i];
            indexMniej++;
        }
    }

    qsort(osobyWiecej, ileWiecejLiczb, sizeof(Osoba), porownajLiczbyWieksze);
    qsort(osobyMniej, ileMniejLiczb, sizeof(Osoba), porownajLiczbyMniejsze);

    // wyswietlOsoby(osobyWiecej, ileWiecejLiczb);
    wyswietlOsoby(osobyMniej, ileMniejLiczb);

    free(osoby);
    free(osobyWiecej);
    free(osobyMniej);

    return 0;
}