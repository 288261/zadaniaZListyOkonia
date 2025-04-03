// W tablicy przechowywane są informacje o członkach pewnej spółdzielni. Informacje te obejmują:
// nazwisko i imię,
// data wstąpienia do spółdzielni,
// wysokość wkładu.
// Należy napisać program, który umożliwi:
// wpisanie nowych informacji do tablicy,
// wydruk zawartości tablicy,
// wydruk listy członków spółdzielni, których wkład jest wyższy od zadanej wartości.
#include <stdlib.h>
#include <stdio.h>

typedef struct Czlonek
{
    char imie[20];
    char nazwisko[30];
    char data[11];
    int wysokoscWkladu;
} Czlonek;

void wprowadzCzlonka(struct Czlonek *czlonek)
{
    printf("Wprowadz imie: ");
    scanf("%19s", czlonek->imie);

    printf("Wprowadz nazwisko: ");
    scanf("%29s", czlonek->nazwisko);

    printf("Wprowadz date: ");
    scanf("%10s", czlonek->data);

    printf("Wprowadz wysokosc wkladu: ");
    scanf("%d", &czlonek->wysokoscWkladu);
}

void wypiszCzlonka(struct Czlonek *czlonek)
{
    printf("Imie i nazwisko: %s %s, data: %s, wklad: %d\n", czlonek->imie, czlonek->nazwisko, czlonek->data, czlonek->wysokoscWkladu);
}

void wypiszCzlonkow(Czlonek *czlonkowie, int ileCzlonkow)
{
    printf("Liczba czlonkow wspoldzielni: %d", ileCzlonkow);

    for (int i = 0; i < ileCzlonkow; i++)
        wypiszCzlonka(&czlonkowie[i]);
}

void wypiszCzlonkowPowyzejKwoty(Czlonek *czlonkowie, int ileCzlonkow)
{
    int kwota;

    printf("Podaj powyzej jakiej kwoty pokazac czlonkow: ");
    scanf("%d", &kwota);

    for (int i = 0; i < ileCzlonkow; i++)
    {
        if (czlonkowie[i].wysokoscWkladu >= kwota)
        {
            wypiszCzlonka(&czlonkowie[i]);
        }
    }
}

void pokazMenu(Czlonek *czlonkowie, int *ileCzlonkow)
{
    int wybor;

    printf("1. Dodaj czlonka\n");
    printf("2. Wypisz czlonkow\n");
    printf("3. Powyzej danej kwoty wypisz czlonkow\n");
    printf("Podaj swoj wybor: ");
    scanf("%d", &wybor);

    switch (wybor)
    {
    case 1:
        (*ileCzlonkow)++;
        czlonkowie = (Czlonek *)realloc(czlonkowie, *ileCzlonkow * sizeof(Czlonek));
        wprowadzCzlonka(&czlonkowie[*ileCzlonkow - 1]);
        break;
    case 2:
        wypiszCzlonkow(czlonkowie, *ileCzlonkow);
        break;
    case 3:
        wypiszCzlonkowPowyzejKwoty(czlonkowie, *ileCzlonkow);
        break;
    }
}

int main()
{
    int ileCzlonkow;

    printf("Podaj ilosc czlonkow: ");
    scanf("%d", &ileCzlonkow);

    Czlonek *czlonkowie = (Czlonek *)malloc(ileCzlonkow * sizeof(Czlonek));

    for (int i = 0; i < ileCzlonkow; i++)
    {
        wprowadzCzlonka(&czlonkowie[i]);
    }

    while (1)
    {
        pokazMenu(czlonkowie, &ileCzlonkow);
    }

    return 0;
}