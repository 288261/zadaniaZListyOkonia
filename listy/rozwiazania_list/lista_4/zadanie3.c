// Napisz program, który wczytuje ze standardowego wejścia liczbę wymierną i wypisuje ją na standardowym wyjściu z dokładnością
// do dwóch miejsc po przecinku
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // deklaracja zmiennej
    float number;

    // wczytanie liczby wymiernej
    scanf("%f", &number);

    // wyswietlenie liczby z dokladnoscia do dwoch miejsc po przecinku
    printf("%.2f\n", number);

    return 0;
}