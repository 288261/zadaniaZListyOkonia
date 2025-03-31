// Napisz makro, które zwraca wartość bezwzględna podawanej w argumencie liczby
#include <stdlib.h>
#include <stdio.h>

#define BEZWZGLEDNA(a) ((a < 0) ? -a : a);

int main()
{
    int bezwzgledna = BEZWZGLEDNA(-1);

    printf("%d\n", bezwzgledna);

    return 0;
}