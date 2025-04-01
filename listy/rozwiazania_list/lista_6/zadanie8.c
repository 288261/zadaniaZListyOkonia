// Tak jak w zadaniu 7, lecz zamiast kwadratu należy wyświetlić sześcian wczytywanych liczb.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int liczba;

    while (liczba >= 0)
    {
        scanf("%d", &liczba);

        if (liczba >= 0)
        {
            int szescianLiczby = liczba * liczba * liczba;
            int numerKolejnyLiczby = liczba + 1;

            printf("Liczba %d %d %d\n", numerKolejnyLiczby, liczba, szescianLiczby);
        }
    }

    return 0;
}