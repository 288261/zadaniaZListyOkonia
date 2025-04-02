// Napisz funkcję, która znajduje największą wartość przechowywaną
// w tablicy dynamicznej oraz indeks tej wartości.
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

void znajdzMaxWTablicy(int *tablica, int n)
{
    int maxLiczba;
    int maxIndex;

    for (int i = 0; i < n; i++)
    {
        if (maxLiczba < tablica[i])
        {
            maxLiczba = tablica[i];
            maxIndex = i;
        }
    }

    printf("Najwieksza wartosc w tablicy to: %d, oraz jej indeks to: %d\n", maxLiczba, maxIndex + 1);
}

int main()
{
    int n;
    int *tablica;

    printf("Podaj ilosc wartosci w tablicy: ");
    scanf("%d", &n);

    tablica = (int *)malloc(n * sizeof(int));

    if (tablica == NULL)
    {
        return 1;
    }

    wprowadzWartosciDoTablicy(tablica, n);
    znajdzMaxWTablicy(tablica, n);

    free(tablica);

    return 0;
}