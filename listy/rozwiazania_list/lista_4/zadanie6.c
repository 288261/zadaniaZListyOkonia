// Napisz program, który wczytuje ze standardowego wejścia dwie
// liczby rzeczywiste i wypisuje na standardowym wyjściu wypisuje ich iloraz.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // zmienne
    float a, b, iloraz;

    // wczytanie dwoch liczb rzeczywistych
    scanf("%f %f", &a, &b);

    // obliczenie ilorazu
    iloraz = a / b;

    // wyswietlenie wyniku
    printf("%f\n", iloraz);

    return 0;
}