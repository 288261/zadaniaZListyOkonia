// Należy wczytać ciąg liczb rzeczywistych. Wczytywanie należy zakończyć, gdy pojawi się liczba ujemna.
// Obliczyć sumę odwrotności wczytanych liczb.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    float suma = 0;
    float liczba = 0;

    while (liczba >= 0)
    {
        scanf("%f", &liczba);

        if (liczba >= 0)
            suma += 1 / liczba;
    }

    printf("%.2f\n", suma);

    return 0;
}