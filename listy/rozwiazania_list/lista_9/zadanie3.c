// Wczytać elementy dwóch macierzy kwadratowych o wymiarach n  n (n –
// wczytywane do programu, n  10). Obliczyć elementy macierzy, będącej sumą wczytanych macierzy.
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

void dodajMacierze(int n, float macierzA[n][n], float macierzB[n][n])
{
    float dodanaMacierz[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dodanaMacierz[i][j] = macierzA[i][j] + macierzB[i][j];
            printf("Nowa macierz[%d][%d] ma wartosc: %.1f\n", i + 1, j + 1, dodanaMacierz[i][j]);
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

    dodajMacierze(n, macierzA, macierzB);

    return 0;
}