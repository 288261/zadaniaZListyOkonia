// Należy wczytać ciąg liczb rzeczywistych. Wczytywanie należy zakończyć, gdy pojawi się liczba 0.
// Określić najmniejszą wczytywaną liczbę.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int najmniejszaLiczba;
    int liczba;

    while (liczba != 0)
    {
        scanf("%d", &liczba);

        if (liczba <= najmniejszaLiczba && liczba != 0)
            najmniejszaLiczba = liczba;
    }

    printf("%d\n", najmniejszaLiczba);

    return 0;
}