// Wczytać elementy macierzy kwadratowej o wymiarach n  n (n – zadawane w programie,
// n  10) oraz wektora o n składowych. Obliczyć elementy wektora, będącego wynikiem
// mnożenia macierzy przez wektor.
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int nMacierzy;
    float macierz[MAX][MAX];
    float wektor[MAX];
    float nowaMacierz[MAX];

    printf("Podaj rozmiar macierzy: ");
    scanf("%d", &nMacierzy);

    if (nMacierzy <= 0 || nMacierzy > MAX)
    {
        printf("Niepoprawny rozmiar macierzy!\n");
        return 1;
    }

    printf("Podaj elementy macierzy:\n");
    for (int i = 0; i < nMacierzy; i++)
    {
        for (int j = 0; j < nMacierzy; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &macierz[i][j]);
        }
    }

    printf("Podaj elementy wektora:\n");
    for (int i = 0; i < nMacierzy; i++)
    {
        printf("x[%d]: ", i);
        scanf("%f", &wektor[i]);
    }

    // Mnożenie macierzy przez wektor
    for (int i = 0; i < nMacierzy; i++)
    {
        nowaMacierz[i] = 0;
        for (int j = 0; j < nMacierzy; j++)
        {
            nowaMacierz[i] += macierz[i][j] * wektor[j];
        }
    }

    printf("Nowy wektor:\n");
    for (int i = 0; i < nMacierzy; i++)
    {
        printf("%8.4f\n", nowaMacierz[i]);
    }

    return 0;
}