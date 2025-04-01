// Napisz program, który wczytuje ze standardowego wejścia dwie
// liczby rzeczywiste i wypisuje na standardowym wyjściu wypisuje ich iloczyn.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // zmienne
    float a, b, iloczyn;

    // wczytanie dwoch liczb rzeczywistych
    scanf("%f %f", &a, &b);

    // obliczenie iloczynu
    iloczyn = a * b;

    // wyswietlenie wyniku
    printf("%f\n", iloczyn);

    return 0;
}