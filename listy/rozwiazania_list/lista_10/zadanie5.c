// Napisz funkcję, która znajduje największą i także najmniejszą wartość
// przechowywaną w tablicy dynamicznej oraz ich różnicę.
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

void znajdzMinMaxWTablicy(int *tablica, int n)
{
    int minLiczba = tablica[0];
    int minIndex = 0;
    int maxLiczba = tablica[0];
    int maxIndex = 0;

    for (int i = 0; i < n; i++)
    {
        if (minLiczba > tablica[i])
        {
            minLiczba = tablica[i];
            minIndex = i;
        }
        if (maxLiczba < tablica[i])
        {
            maxLiczba = tablica[i];
            maxIndex = i;
        }
    }

    int roznica = maxLiczba - minLiczba;

    printf("Najmniejsza wartosc w tablicy to: %d, oraz jej indeks to: %d\n", minLiczba, minIndex + 1);
    printf("Najwieksza wartosc w tablicy to: %d, oraz jej indeks to: %d\n", maxLiczba, maxIndex + 1);
    printf("Oraz roznica to: %d\n", roznica);
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
    znajdzMinMaxWTablicy(tablica, n);

    free(tablica);

    return 0;
}