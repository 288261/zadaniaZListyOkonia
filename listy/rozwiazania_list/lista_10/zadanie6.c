// Napisz funkcję, która rozpoczynając od elementu n i kończąc na
// elemencie m, kopiuje elementy macierzy A do macierzy B.
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

void skopiujTabliceOdDo(int *tablica, int *kopiaTablicy, int odLiczby, int doLiczby)
{
    for (int i = 0; i <= doLiczby - odLiczby; i++)
    {
        kopiaTablicy[i] = tablica[odLiczby + i];
    }
}

void pokazElementyTablicyKopii(int *tablica, int iloscElementow)
{
    for (int i = 0; i < iloscElementow; i++)
    {
        printf("Element tablicy[%d] ma wartosc: %d\n", i + 1, tablica[i]);
    }
}

int main()
{
    int n;
    int *tablica;
    int *kopiaTablicy;

    printf("Podaj ilosc liczb w tablicy: ");
    scanf("%d", &n);

    tablica = (int *)malloc(n * sizeof(int));

    if (tablica == NULL)
        return 1;

    wprowadzWartosciDoTablicy(tablica, n);

    int odLiczby;
    int doLiczby;

    printf("Teraz wprowadz od ktorego do ktorego indeksu chce skopiowac dane: ");
    scanf("%d %d", &odLiczby, &doLiczby);

    odLiczby -= 1; // zmniejszamy o 1, bo indeksowanie w C zaczyna się od 0
    doLiczby -= 1;

    // Obliczenie liczby elementów do skopiowania
    int iloscElementow = doLiczby - odLiczby + 1;

    kopiaTablicy = (int *)malloc(iloscElementow * sizeof(int));

    if (kopiaTablicy == NULL)
        return 1;

    skopiujTabliceOdDo(tablica, kopiaTablicy, odLiczby, doLiczby);
    pokazElementyTablicyKopii(kopiaTablicy, iloscElementow);

    free(tablica);
    free(kopiaTablicy);

    return 0;
}
