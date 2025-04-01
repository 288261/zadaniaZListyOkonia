// Napisz funkcję, która oblicza rezystancje zastępczą dwóch połączonych
// równolegle rezystorów, rezystancje mają być podawane z klawiatury.
#include <stdlib.h>
#include <stdio.h>

float Rz(int R1, int R2)
{
    return (R1 * R2) / (R1 + R2);
}

int main()
{
    int R1, R2;

    scanf("%d %d", &R1, &R2);
    float Rzastepcza = Rz(R1, R2);

    printf("%.2f\n", Rzastepcza);

    return 0;
}