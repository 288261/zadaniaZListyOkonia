// W tablicy struktur mogą być przechowywane informacje o osobach wypożyczających
// książki z pewnej biblioteki. Dla jednej osoby ma być pamiętane:
// nazwisko i imię,
// sygnatura książki (liczba!),
// data wypożyczenia książki (łańcuch 10 znakowy).
// Program ma zapewnić:
// dopisywanie informacji o kolejnej osobie,
// znajdowanie informacji odnoszących się do osoby, która zwraca książkę,
// kasowanie struktur odnoszącego się do osoby określonej w b),
// druk tablicy struktur.
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Osoba
{
    char imie[20];
    char nazwisko[30];
    int sygnaturaKsiazki;
    char dataWypozyczenia[11];
} Osoba;

void dodajOsobe(struct Osoba *osoba)
{
    printf("Podaj imie: ");
    scanf("%19s", osoba->imie);

    printf("Podaj nazwisko: ");
    scanf("%29s", osoba->nazwisko);

    printf("Podaj sygnature ksiazki: ");
    scanf("%d", &osoba->sygnaturaKsiazki);

    printf("Podaj date wypozyczenia: ");
    scanf("%10s", osoba->dataWypozyczenia);
}

void pokazOsobe(struct Osoba *osoba)
{
    printf("Imie i nazwisko: %s %s, sygnatura ksiazki: %d, data wypozyczenia: %s\n", osoba->imie, osoba->nazwisko, osoba->sygnaturaKsiazki, osoba->dataWypozyczenia);
}

void wyszukajKsiazke(Osoba *osoby, int ileOsob)
{
    int sygnatura;
    bool znaleziono = false;

    printf("Podaj sygnature ksiazki: ");
    scanf("%d", &sygnatura);

    for (int i = 0; i < ileOsob; i++)
    {
        if (osoby[i].sygnaturaKsiazki == sygnatura)
        {
            pokazOsobe(&osoby[i]);
            znaleziono = true;
        }
    }

    if (znaleziono == false)
        printf("Nie znaleziono ksiazki o syngaturze: %d\n", sygnatura);
}

void usunKsiazke(Osoba *osoby, int *ileOsob)
{
    int sygnatura;
    int index = -1;

    printf("Podaj sygnature ksiazki: ");
    scanf("%d", &sygnatura);

    for (int i = 0; i < *ileOsob; i++)
    {
        if (osoby[i].sygnaturaKsiazki == sygnatura)
            index = i;
    }

    if (index == -1)
        printf("Nie znaleziono ksiazki o syngaturze: %d\n", sygnatura);
    else
    {
        for (int i = index; i < *ileOsob - 1; i++)
        {
            osoby[i] = osoby[i + 1];
        }

        (*ileOsob)--;
        osoby = (Osoba *)realloc(osoby, *ileOsob * sizeof(Osoba));

        if (osoby == NULL && *ileOsob > 0)
        {
            printf("Błąd przy realokacji pamięci.\n");
            exit(1);
        }
    }
}

void pokazListe(int ileOsob, Osoba *osoby)
{
    printf("Ilosc wypozyczonych ksiazek: %d\n", ileOsob);

    for (int i = 0; i < ileOsob; i++)
        pokazOsobe(&osoby[i]);
}

void przelaczZadania(int wybor, Osoba *osoby, int *ileOsob)
{
    switch (wybor)
    {
    case 1:
        *ileOsob += 1;
        osoby = (Osoba *)realloc(osoby, *ileOsob * sizeof(Osoba));
        dodajOsobe(&osoby[*ileOsob - 1]);
        break;
    case 2:
        wyszukajKsiazke(osoby, *ileOsob);
        break;
    case 3:
        usunKsiazke(osoby, ileOsob);
        break;
    case 4:
        pokazListe(*ileOsob, osoby);
        break;
    default:
        printf("Wybrano nie prawidlowy numer!\n");
        break;
    }
}

void wyswietlMenu(Osoba *osoby, int *ileOsob)
{
    int wybor;

    printf("1. Dodaj nowa osobe.\n");
    printf("2. Wyszukaj ksiazke.\n");
    printf("3. Usun osobe zwracajaca ksiazke.\n");
    printf("4. Aktualna lista osob ktore maja wypozyczona ksiazke.\n");

    printf("Twoj wybor: ");
    scanf("%d", &wybor);

    przelaczZadania(wybor, osoby, ileOsob);
}

int main()
{
    int ileOsob;
    bool czyAplikacjaTrwa = true;

    printf("Podaj ilosc osob: ");
    scanf("%d", &ileOsob);

    Osoba *osoby = (Osoba *)malloc(ileOsob * sizeof(Osoba));

    for (int i = 0; i < ileOsob; i++)
    {
        dodajOsobe(&osoby[i]);
    }

    while (czyAplikacjaTrwa)
    {
        wyswietlMenu(osoby, &ileOsob);
    }

    return 0;
}