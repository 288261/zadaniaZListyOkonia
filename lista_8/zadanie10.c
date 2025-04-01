// Przy założeniu, że x jest rzeczywiste obliczyć:
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float sinhx(float x, float i)
{
    return (exp(i * x) - exp(-i * x)) / 2;
}

float coshx(float x, float i)
{
    return (exp(i * x) + exp(-i * x)) / 2;
}

float tghx(float x, float i)
{
    return (exp(i * x) - exp(-i * x)) / (exp(x * i) + exp(-i * x));
}

float ctghx(float x, float i)
{
    return (exp(x * i) + exp(-x * i)) / (exp(x * i) - exp(-x * i));
}

float sinh2x(float x, float i)
{
    return sinhx(x, i) + sinhx(x, i) * sinhx(x, i);
}

int main()
{
    // program moze wyliczac w zly sposob, znowu nie mam pojecia o co mu chodzi XD
    float podstawa;
    float wykladnik;

    scanf("%f %f", &podstawa, &wykladnik);

    float sinhix = 0;
    float coshix = 0;
    float tghix = 0;
    float ctghix = 0;
    float tghix2 = 0;

    for (int i = 0; i <= wykladnik; i++)
    {
        sinhix += sinhx(podstawa, i);
        coshix += coshx(podstawa, i);
        tghix += tghx(podstawa, i);
        ctghix += ctghx(podstawa, i);
        tghix2 += sinh2x(podstawa, i);
    }

    printf("%f %f %f %f %f\n", sinhix, coshix, tghix, ctghix, tghix2);

    return 0;
}