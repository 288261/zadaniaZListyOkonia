// Należy wczytać ciąg liczb rzeczywistych. Wczytywanie należy zakończyć, gdy pojawi się liczba 0.
// Obliczyć sumę wczytanych liczb.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int suma = 0;
    int liczba;

    while (liczba != 0)
    {
        scanf("%d", &liczba);

        suma += liczba;
    }

    printf("%d\n", suma);

    return 0;
}