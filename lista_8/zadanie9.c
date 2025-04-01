// Obliczyć sumę szeregu  gdy x jest liczbą rzeczywistą.
// W programie należy wykorzystać funkcję obliczania potęgi
// . W programie należy zdefiniować funkcje na potęgę.
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int obliczaniePotegi(int podstawa, int wykladnik)
{
    int iloczyn = 0;

    iloczyn += pow(podstawa, wykladnik);

    return iloczyn;
}

int main()
{
    int podstawa, wykladnik, suma = 0;

    scanf("%d %d", &podstawa, &wykladnik);

    for (int i = 0; i <= wykladnik; i++)
    {
        suma += obliczaniePotegi(podstawa, i);
    }

    printf("%d\n", suma);

    return 0;
}