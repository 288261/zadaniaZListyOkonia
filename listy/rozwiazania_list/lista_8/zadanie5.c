// Napisz funkcję, która dla czterech otrzymanych w argumentach liczb zwraca ich iloczyn
#include <stdlib.h>
#include <stdio.h>

int iloczyn(int a, int b, int c, int d)
{
    return a * b * c * d;
}

int main()
{
    printf("%d\n", iloczyn(1, 2, 3, 4));

    return 0;
}