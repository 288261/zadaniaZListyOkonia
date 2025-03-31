// Napisz makro, które dla czterech otrzymanych w argumentach liczb zwraca ich średnią
#include <stdlib.h>
#include <stdio.h>

#define SREDNIA(a, b, c, d) ((a + b + c + d) / 4);

int main()
{
    float srednia = SREDNIA(1, 2, 3, 4);

    printf("%f\n", srednia);

    return 0;
}