// Należy wczytać ciąg liczb rzeczywistych. Wczytywanie należy zakończyć, gdy pojawi się liczba ujemna.
// Obliczyć iloczyn odwrotności wczytanych liczb.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    float iloczyn = 1;
    float liczba = 0;

    while (liczba >= 0)
    {
        scanf("%f", &liczba);

        if (liczba >= 0)
            iloczyn *= 1 / liczba;
    }

    printf("%.2f\n", iloczyn);

    return 0;
}