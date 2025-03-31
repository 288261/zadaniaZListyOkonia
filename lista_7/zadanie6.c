// Napisz makro, które oblicza przyspieszenie pojazdu, który w czasie t zwiększa prędkość
// z V1 do V2 (t, V1 i V2  podawane są z klawiatury).
#include <stdlib.h>
#include <stdio.h>

#define ACC(V1, V2, t) ((V2 - V1) / t);

int main()
{
    int t = 10;
    int v1, v2;

    scanf("%d %d", &v1, &v2);

    float acc = ACC(v1, v2, t);

    printf("%.2f\n", acc);

    return 0;
}