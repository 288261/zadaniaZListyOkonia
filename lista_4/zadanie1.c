// Zadanie 1 Napisz program, który wczytuje ze standardowego wejścia trzy liczby
// całkowite, a następnie wypisuje je w oddzielnych liniach na standardowym wyjściu.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // zadeklarowanie 3 zmiennych, liczby calkowite
    int a, b, c;

    // Wczytanie 3 liczb
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    // Wypisanie 3 liczb w odzielnych liniach
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);

    return 0;
}