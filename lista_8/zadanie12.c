// Obliczyć n wartości funkcji
#include <stdlib.h>
#include <stdio.h>

float Wn(float n, float x)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else
    {
        return ((2 * n - 1) * Wn(n - 1, x) - (n - 1) * Wn(n - 2, x)) / n;
    }
}

int main()
{
    float n, x;

    scanf("%f %f", &n, &x);

    float wnOdX = Wn(n, x);

    printf("%.2f\n", wnOdX);

    return 0;
}