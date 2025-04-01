// Napisz program, który odpowiada na pytanie, czy wśród czterech liczb są choć dwie takie same.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // zmienne 4 liczby
    int a, b, c, d;

    // wczytanie 4 liczb
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // sprawdzenie czy sa dwie takie same liczby
    if (a == b || a == c || a == d || b == c || b == d || c == d)
    {
        printf("Tak\n");
    }
    // jesli nie
    else
    {
        printf("Nie\n");
    }

    return 0;
}