// Napisz program, który wczytuje ze standardowego wejścia trzy
// liczby rzeczywiste i wypisuje na standardowym wyjściu wypisuje ich sumę
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // deklaracja 3 liczb
    int a, b, c, suma;

    // wczytanie 3 liczb, tym razem w jednej linii da sie jak widac
    scanf("%d %d %d", &a, &b, &c);

    // obliczenie sumy
    suma = a + b + c;

    // wyswietlenie sumy
    printf("%d\n", suma);

    return 0;
}