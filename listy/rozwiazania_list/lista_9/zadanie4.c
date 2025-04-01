// Wczytać elementy dwóch macierzy kwadratowych o wymiarach n  n
//  (n – wczytywane do programu, n  10). Obliczyć elementy macierzy,
// będącej iloczynem wczytanych macierzy.
#include <stdlib.h>
#include <stdio.h>

#define MAX 10

void wprowadzWartoscDoMacierzy(int n, float macierz[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &macierz[i][j]);
        }
    }
}

void mnozMacierze(int n, float macierzA[n][n], float macierzB[n][n])
{
    float nowaMacierz[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            float nowaWartosc = 0.0;

            for (int k = 0; k < n; k++)
            {
                nowaWartosc += macierzA[i][k] * macierzB[k][j];
            }

            nowaMacierz[i][j] = nowaWartosc;
            printf("Macierz [%d][%d]: %.1f\n", i + 1, j + 1, nowaMacierz[i][j]);
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    if (n > 10)
        return 1;

    float macierzA[n][n];
    float macierzB[n][n];

    wprowadzWartoscDoMacierzy(n, macierzA);
    wprowadzWartoscDoMacierzy(n, macierzB);

    mnozMacierze(n, macierzA, macierzB);

    return 0;
}