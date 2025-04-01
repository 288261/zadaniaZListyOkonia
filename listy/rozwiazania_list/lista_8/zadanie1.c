// Napisz funkcję, która dla czterech otrzymanych w argumentach liczb zwraca ich średnią
#include <stdlib.h>
#include <stdio.h>

float srednia(int a, int b, int c, int d)
{
    return (a + b + c + d) / 4;
}

int main()
{
    printf("%.2f\n", srednia(1, 2, 3, 4));

    return 0;
}