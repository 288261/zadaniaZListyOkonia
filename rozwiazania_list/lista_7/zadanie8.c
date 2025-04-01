// Napisz makro, które oblicza rezystancje zastępczą dwóch połączonych
// równolegle rezystorów, rezystancje mają być podawane z klawiatury.
#include <stdlib.h>
#include <stdio.h>

#define Rzast(R1, R2) ((R1 * R2) / (R1 + R2));

int main()
{
    float R1, R2, Rz;

    scanf("%f %f", &R1, &R2);
    Rz = Rzast(R1, R2);

    printf("%.2f\n", Rz);

    return 0;
}