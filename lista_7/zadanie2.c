// Napisz makro, które dostaje jako argumenty dwie liczby całkowite i
// wypisuje na standardowym wyjściu mniejszą z nich
#include <stdlib.h>
#include <stdio.h>

#define MIN(a, b) ((a < b) ? a : b);

int main()
{
    int min = MIN(1, 2);

    printf("%d\n", min);

    return 0;
}