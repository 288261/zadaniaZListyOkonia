// Napisz funkcję, która znajduje sumę elementów oraz sumę
// wartości bezwzględnych elementów tablicy dynamicznej.
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

void obliczSumy(int *tablica, int n, int *suma, int *sumaBezwzgledna)
{
    for (int i = 0; i < n; i++)
    {
        *suma += tablica[i];

        if (tablica[i] < 0)
            *sumaBezwzgledna += tablica[i] * -1;
        else
            *sumaBezwzgledna += tablica[i];
    }
}

int main()
{
    int n;
    int *tablica;
    int suma = 0;
    int sumaBezwzgledna = 0;

    printf("Podaj ilosc elementow w tablicy: ");
    scanf("%d", &n);

    tablica = (int *)malloc(n * sizeof(int));
    if (tablica == NULL)
        return 1;

    wprowadzWartosciDoTablicy(tablica, n);

    obliczSumy(tablica, n, &suma, &sumaBezwzgledna);

    printf("Suma: %d\n", suma);
    printf("Suma bezwzgledna: %d\n", sumaBezwzgledna);

    free(tablica);

    return 0;
}