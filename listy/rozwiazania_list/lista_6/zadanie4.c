// Należy wczytać ciąg liczb rzeczywistych. Wczytywanie należy zakończyć, gdy pojawi się liczba 0.
// Obliczyć iloczyn wczytanych liczb.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int iloczyn = 1;
    int liczba;

    while (liczba != 0)
    {
        scanf("%d", &liczba);

        if (liczba != 0)
            iloczyn *= liczba;
    }

    printf("%d\n", iloczyn);

    return 0;
}