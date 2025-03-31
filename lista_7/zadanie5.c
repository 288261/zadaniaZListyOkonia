// Napisz makro, które dla czterech otrzymanych w argumentach liczb zwraca ich iloczyn
#include <stdlib.h>
#include <stdio.h>

#define ILOCZYN(a, b, c, d) (a * b * c * d);

int main()
{
    int iloczyn = ILOCZYN(1, 2, 3, 4);

    printf("%d\n", iloczyn);

    return 0;
}