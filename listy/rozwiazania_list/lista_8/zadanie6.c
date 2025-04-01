// Napisz funkcję, która oblicza przyspieszenie pojazdu, który w czasie
// t zwiększa prędkość z V1 do V2 (t, V1 i V2  podawane są z klawiatury).
#include <stdlib.h>
#include <stdio.h>

float przyspieszenie(int t, int V1, int V2)
{
    return (V2 - V1) / t;
}

int main()
{
    int t = 10, V1, V2;

    scanf("%d %d", &V1, &V2);

    float a = przyspieszenie(t, V1, V2);

    printf("%.2f\n", a);

    return 0;
}