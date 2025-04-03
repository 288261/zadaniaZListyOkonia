// Wykorzystując tablicę, załóż katalog książek pewnej biblioteki. Dla jednej książki ma być pamiętane:
// nazwisko i imię autora,
// tytuł książki,
// rok wydania.
// Program ma zapewnić:
// wydruk listy autorów, których książki są ujęte w katalogu;
// wydruk tytułów książek wraz z nazwiskiem i imionami autorów;
// określenie roku najnowszej książki.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Ksiazka
{
    char tytul[100];
    char imie[20];
    char nazwisko[30];
    int rok;
} Ksiazka;

void wczytajKsiazki(Ksiazka *ksiazki, int ileKsiazek, char *tytulKsiazki, int *rokKsiazki)
{
    for (int i = 0; i < ileKsiazek; i++)
    {
        printf("Podaj tytul: ");
        fgets(ksiazki[i].tytul, sizeof(ksiazki[i].tytul), stdin);
        ksiazki[i].tytul[strcspn(ksiazki[i].tytul, "\n")] = 0;

        printf("Podaj imie autora: ");
        scanf("%19s", ksiazki[i].imie);

        printf("Podaj nazwisko autora: ");
        scanf("%29s", ksiazki[i].nazwisko);

        printf("Podaj rok wydania: ");
        scanf("%d", &ksiazki[i].rok);

        if (*rokKsiazki < ksiazki[i].rok)
        {
            *rokKsiazki = ksiazki[i].rok;
            strcpy(tytulKsiazki, ksiazki[i].tytul);
        }

        getchar();
    }
}

void wyczytajKsiazki(Ksiazka *ksiazki, int ileKsiazek)
{
    for (int i = 0; i < ileKsiazek; i++)
        printf("Tytul: %s, Imie i nazwisko autora: %s %s, rok wydania: %d\n", ksiazki[i].tytul, ksiazki[i].imie, ksiazki[i].nazwisko, ksiazki[i].rok);
}

void wyczytajNajnowszaKsiazke(char *tytul, int rokWydania)
{
    printf("Najnowsza ksiazka to: %s, rok wydania: %d", tytul, rokWydania);
}

int main()
{
    int ileKsiazek;
    char tytulNajnowszejKsiazki[100];
    int rokNajnowszejKsiazki = 0;

    printf("Ile ksiazek: ");
    scanf("%d", &ileKsiazek);
    getchar();

    Ksiazka *ksiazki = (Ksiazka *)malloc(ileKsiazek * sizeof(Ksiazka));

    wczytajKsiazki(ksiazki, ileKsiazek, tytulNajnowszejKsiazki, &rokNajnowszejKsiazki);
    wyczytajKsiazki(ksiazki, ileKsiazek);
    wyczytajNajnowszaKsiazke(tytulNajnowszejKsiazki, rokNajnowszejKsiazki);

    free(ksiazki);

    return 0;
}