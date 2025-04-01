// Obliczyc sume
#include <stdlib.h>
#include <stdio.h>

float silnia(float liczba)
{
    float iloczyn = 1;

    for (int i = 1; i <= liczba; i++)
    {
        iloczyn *= i;
    }

    return iloczyn;
}

float potega(float podstawa, float wykladnik)
{
    float wynik = 1;

    for (int i = 1; i <= wykladnik; i++)
    {
        wynik *= podstawa;
    }

    return wynik;
}

float obliczSume(float n, float x)
{
    float silniaLicznik = silnia(2 * n);
    float mianowik4DoN = potega(4, n);
    float nSilniaKwadrat = potega(silnia(n), 2);
    float mianownikSumaIloczynu = 2 * n + 1;
    float xDoN = potega(x, 2 * n + 1);

    return ((silniaLicznik) / (mianowik4DoN * nSilniaKwadrat * mianownikSumaIloczynu)) * xDoN;
}

int main()
{
    float n, x;
    float suma = 0;

    scanf("%f %f", &n, &x);

    for (int i = 0; i <= n; i++)
    {
        suma += obliczSume(i, x);
    }

    printf("%.2f\n", suma);

    return 0;
}