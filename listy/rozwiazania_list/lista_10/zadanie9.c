// Napisz funkcję, która znajduje sumę elementów mniejszych oraz
// sumę elementów większych od zera w pewnej tablicy dynamicznej.
#include <stdlib.h>
#include <stdio.h>

void wprowadzWartosciDoTablicy(int *tablica, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Wprowadz wartosc do tablicy[%d]: ", i + 1);
        scanf("%d", &tablica[i]);
    }
}

void ileElementowDodatnichIleUjemnych(int *tablica, int *ileElementowDodanich, int *ileElementowUjemnych, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (tablica[i] > 0)
            *ileElementowDodanich += 1;
        else if (tablica[i] < 0)
            *ileElementowUjemnych += 1;
    }
}

void segregujDoTablic(int *tablica, int *tablicaDodatnich, int *tablicaUjemnych, int n)
{
    int dodatniIndex = 0;
    int ujemnyIndex = 0;

    for (int i = 0; i < n; i++)
    {
        if (tablica[i] > 0)
        {
            tablicaDodatnich[dodatniIndex] = tablica[i];
            dodatniIndex += 1;
        }
        else if (tablica[i] < 0)
        {
            tablicaUjemnych[ujemnyIndex] = tablica[i];
            ujemnyIndex += 1;
        }
    }
}

void pokazElementyTablicy(int *tablica, int n, char *tekst)
{
    for (int i = 0; i < n; i++)
    {
        printf("Element tablicy %s [%d]: %d\n", tekst, i + 1, tablica[i]);
    }
}

int main()
{
    int n;
    int *tablica;

    printf("Wprowadz ilosc elementow w tablicy: ");
    scanf("%d", &n);

    tablica = (int *)malloc(n * sizeof(int));

    if (tablica == NULL)
        return 1;

    wprowadzWartosciDoTablicy(tablica, n);

    int ileElementowDodatnich = 0;
    int ileElementowUjemnych = 0;

    ileElementowDodatnichIleUjemnych(tablica, &ileElementowDodatnich, &ileElementowUjemnych, n);

    int *tablicaDodatnich;
    int *tablicaUjemnych;

    tablicaDodatnich = (int *)malloc(ileElementowDodatnich * sizeof(int));
    tablicaUjemnych = (int *)malloc(ileElementowUjemnych * sizeof(int));

    if (tablicaDodatnich == NULL || tablicaUjemnych == NULL)
        return 1;

    segregujDoTablic(tablica, tablicaDodatnich, tablicaUjemnych, n);

    pokazElementyTablicy(tablicaDodatnich, ileElementowDodatnich, "+");
    pokazElementyTablicy(tablicaUjemnych, ileElementowUjemnych, "-");

    free(tablica);
    free(tablicaDodatnich);
    free(tablicaUjemnych);

    return 0;
}