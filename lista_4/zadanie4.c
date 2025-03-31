// Napisz program, który wczytuje ze standardowego wejścia trzy
// liczby całkowite i wypisuje na standardowym wyjściu ich średnią arytmetyczną
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // trzy zmienne calkowite oraz srednia, typ float gdyz srednia moze byc ulamkiem
    float a, b, c, avg;

    // stala n, liczba wczytywanych liczb
    const int n = 3;

    // Wczytanie 3 liczb
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    // Obliczenie sredniej arytmetycznej
    avg = (a + b + c) / n;

    // Wypisanie sredniej arytmetycznej z dokladnoscnia do 2 miejsc po przecinku
    printf("%f\n", avg);

    return 0;
}