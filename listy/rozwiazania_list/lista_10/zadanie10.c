// Napisz funkcję, która znajduje sumę elementów o numerach parzystych
// oraz sumę elementów o numerach nieparzystych w pewnej tablicy dynamicznej.
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

void ileElementowParzystychIleNieParzystych(int *tablica, int *ileElementowParzystych, int *ileElementowNieParzystych, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (tablica[i] % 2 == 0)
            *ileElementowParzystych += 1;
        else if (tablica[i] % 2 != 0)
            *ileElementowNieParzystych += 1;
    }
}

void segregujDoTablic(int *tablica, int *tablicaParzystych, int *tablicaNieParzystych, int n)
{
    int parzystyIndex = 0;
    int nieParzystyIndex = 0;

    for (int i = 0; i < n; i++)
    {
        if (tablica[i] % 2 == 0)
        {
            tablicaParzystych[parzystyIndex] = tablica[i];
            parzystyIndex += 1;
        }
        else if (tablica[i] % 2 != 0)
        {
            tablicaNieParzystych[nieParzystyIndex] = tablica[i];
            nieParzystyIndex += 1;
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

    int ileElementowParzystych = 0;
    int ileElementowNieParzystych = 0;

    ileElementowParzystychIleNieParzystych(tablica, &ileElementowParzystych, &ileElementowNieParzystych, n);

    int *tablicaParzystych;
    int *tablicaNieParzystych;

    tablicaParzystych = (int *)malloc(ileElementowParzystych * sizeof(int));
    tablicaNieParzystych = (int *)malloc(ileElementowNieParzystych * sizeof(int));

    if (tablicaNieParzystych == NULL || tablicaParzystych == NULL)
        return 1;

    segregujDoTablic(tablica, tablicaParzystych, tablicaNieParzystych, n);

    pokazElementyTablicy(tablicaParzystych, ileElementowParzystych, "parzystej");
    pokazElementyTablicy(tablicaNieParzystych, ileElementowNieParzystych, "nieparzystej");

    free(tablica);
    free(tablicaParzystych);
    free(tablicaNieParzystych);

    return 0;
}