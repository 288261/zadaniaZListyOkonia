// Napisz funkcję, która dostaje jako argumenty dwie liczby całkowite i
// wypisuje na standardowym wyjściu mniejszą z nich
#include <stdlib.h>
#include <stdio.h>

int min(int a, int b)
{
    if (a < b)
        return a;

    return b;
}

int main()
{
    printf("%d\n", min(1, 2));

    return 0;
}