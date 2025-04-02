// Zainicjuj tablicę dynamiczną A, a następnie przekopiuj jej niezerowe elementy do macierzy B.
#include <stdlib.h>
#include <stdio.h>

void kopiujTablice(int *tablica, int *kopia, int n)
{
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (tablica[i] != 0)
        {
            *(kopia + j) = *(tablica + i);
            j++;
        }
    }
}

void podajWartoscDoTablicy(int *tablica, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Wpisz wartosc do tablicy[%d]: ", i);
        scanf("%d", &tablica[i]);
    }
}

void pokazWartosciTablicy(int *tablica, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Element tablicy[%d]: ma wartosc: %d\n", i, tablica[i]);
    }
}

int sprawdzBladTablicy(int tablica[])
{
    if (tablica == NULL)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int n;
    int *tablica;
    int *kopiaTablicy;

    printf("Podaj rozmiar tablicy: ");
    scanf("%d", &n);

    tablica = (int *)malloc(n * sizeof(int));

    int bladTablicy = sprawdzBladTablicy(tablica);
    if (bladTablicy == 0)
        return 1;

    podajWartoscDoTablicy(tablica, n);

    // Liczymy, ile elementów niezerowych jest w tablicy
    int nonZeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (tablica[i] != 0)
        {
            nonZeroCount++;
        }
    }

    kopiaTablicy = (int *)malloc(nonZeroCount * sizeof(int));

    int bladKopiiTablicy = sprawdzBladTablicy(kopiaTablicy);
    if (bladKopiiTablicy == 0)
        return 1;

    kopiujTablice(tablica, kopiaTablicy, n);

    pokazWartosciTablicy(kopiaTablicy, nonZeroCount);

    free(tablica);
    free(kopiaTablicy);

    return 0;
}