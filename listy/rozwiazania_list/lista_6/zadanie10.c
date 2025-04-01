// Należy napisać program, który pyta się użytkownika o liczbę całkowitą N,
// a następnie oblicza silnię tej liczby.
#include <stdlib.h>
#include <stdio.h>

void obliczSilnie(int liczba)
{
    int silnia = 1;

    for (int i = 1; i <= liczba; i++)
    {
        silnia *= i;
    }

    printf("%d\n", silnia);
}

int main()
{
    int liczba;

    while (1)
    {
        scanf("%d", &liczba);
        obliczSilnie(liczba);
    }

    return 0;
}