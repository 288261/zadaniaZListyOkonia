// Zainicjuj tablicę dynamiczną, a następnie przekopiuj jej
// zawartość do dwóch innych tablic.Użyj funkcji, wykorzystującej notację wskaźnikową.
#include <stdlib.h>
#include <stdio.h>

void kopiujTablice(int *zrodlo, int *cel, int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        *(cel + i) = *(zrodlo + i);
    }
}

int main()
{
    int *tablica;
    int *tablicaKopia;
    int *tablicaKopia2;
    int n;

    scanf("%d", &n);

    // rezerwuje dynamicznie tablice o rozmiarze n
    tablica = (int *)malloc(n * sizeof(int));
    tablicaKopia = (int *)malloc(n * sizeof(int));
    tablicaKopia2 = (int *)malloc(n * sizeof(int));

    // robi niezalezna kopie do dwoch kopii tablic
    kopiujTablice(tablica, tablicaKopia, n);
    kopiujTablice(tablica, tablicaKopia2, n);

    // Sprawdzanie poprawności alokacji pamięci
    if (tablica == NULL || tablicaKopia == NULL || tablicaKopia2 == NULL)
    {
        printf("Błąd alokacji pamięci!\n");
        free(tablica);
        free(tablicaKopia);
        free(tablicaKopia2);
        return 1;
    }

    // zwalnia pamiec wskaznika, do optymalizacji
    free(tablica);
    free(tablicaKopia);
    free(tablicaKopia2);

    return 0;
}