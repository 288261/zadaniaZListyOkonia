// Napisz makro, które oblicza spadek napięcia na rezystorze R
// przez który przepływa prąd I (R oraz I są podawane z klawiatury)
#include <stdlib.h>
#include <stdio.h>

#define SPADKI_NAPIECIA(R, I) (R * I);

int main()
{
    int R, I, U;

    scanf("%d %d", &R, &I);

    U = SPADKI_NAPIECIA(R, I);

    printf("%d\n", U);

    return 0;
}