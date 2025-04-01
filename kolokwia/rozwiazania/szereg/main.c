#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int obliczSilnie(int n) {
    int silnia = 1;

    if(n != 0) {
        for(int i = 1; i <= n; i++) {
            silnia *= i;
        }
    }

    return silnia;
}

float obliczSzereg(float x, int n) {
    if(x > 1 || x < -1) {
        return -1;
    } else {
        float pierwszaSilnia = obliczSilnie(2*n);
        float mianownik = pow(2, n) * pow(obliczSilnie(n), 2) * (2*n + 1);
        float reszta = pow(x, 2*n + 1);
    
        return (pierwszaSilnia / mianownik) * reszta;
    }
}

int main() {
    int n;
    float x;
    float calkowitaSuma = 0;

    printf("\n Podaj x: ");
    scanf("%f", &x);
    printf("Podaj do jakiej liczby n  obliczyc silnie: ");
    scanf("%d", &n);

    if(x <= 1 || x >= -1) {
        for(int i=0; i <= n; i++) {
            calkowitaSuma += obliczSzereg(x, i);
        }
    }

    printf("%f\n", calkowitaSuma);

    return 0;
}