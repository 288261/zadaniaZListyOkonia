// Napisz funkcję, która oblicza spadek napięcia na rezystorze R
// przez który przepływa prąd I (R oraz I są podawane z klawiatury)
#include <stdlib.h>
#include <stdio.h>

int spadekNapiecia(int R, int I)
{
    return R * I;
}

int main()
{
    int R, I;

    scanf("%d %d", &R, &I);

    int napiecie = spadekNapiecia(R, I);
    printf("%d\n", napiecie);

    return 0;
}