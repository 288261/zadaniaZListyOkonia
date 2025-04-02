// Napisz funkcję, która znajduje najmniejszą wartość
// przechowywaną w tablicy dynamicznej oraz indeks tej wartości.
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

void znajdzMinWTablicy(int *tablica, int n)
{
    int minLiczba = tablica[0];
    int minIndex = 0;

    for (int i = 0; i < n; i++)
    {
        if (minLiczba > tablica[i])
        {
            minLiczba = tablica[i];
            minIndex = i;
        }
    }

    printf("Najmniejsza wartosc w tablicy to: %d, oraz jej indeks to: %d\n", minLiczba, minIndex + 1);
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
    znajdzMinWTablicy(tablica, n);

    free(tablica);

    return 0;
}