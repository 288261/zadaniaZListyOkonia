// Należy wczytać ciąg liczb rzeczywistych. Wczytywanie należy zakończyć, gdy pojawi się liczba 0.
// Określić największą wczytywaną liczbę.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int najwiekszaLiczba = 0;
    int liczba;

    while (liczba != 0)
    {
        scanf("%d", &liczba);

        if (liczba > najwiekszaLiczba && liczba != 0)
            najwiekszaLiczba = liczba;
    }

    printf("%d\n", najwiekszaLiczba);

    return 0;
}