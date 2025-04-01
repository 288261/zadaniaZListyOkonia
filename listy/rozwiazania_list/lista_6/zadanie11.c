// Należy napisać program, który pyta się o pewną stałą liczbę tak długo,
// aż zostanie ona odgadnięta. Po nieudanej próbie program informuje,
// że szukana liczba jest większa albo mniejsza od podanej liczby.

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    bool zgadnietaLiczba = false;
    // zakres od 1 do 100, zgadywanej liczby
    int szukanaLiczba = rand() % 100 + 1;

    while (!zgadnietaLiczba)
    {
        int liczba;

        scanf("%d", &liczba);

        if (liczba > szukanaLiczba)
            printf("Za duzo\n");
        else if (liczba < szukanaLiczba)
            printf("Za malo\n");
        else
        {
            printf("%d\n", szukanaLiczba);
            zgadnietaLiczba = true;
        }
    }

    return 0;
}