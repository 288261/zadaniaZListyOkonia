// TE SAME ZADANIE BYLO W KOLOKWIACH OKONIA, TYLKO OKAZUJE SIE ZE MOZNNA JE ZROBIC O WIELE LATWIEJ

// Napisz funkcje wykonujące operacje na liczbach zespolonych: dodawanie,
// odejmowanie, mnożenie, dzielenie, moduł, sprzężenie, moduł oraz kąt.
//  Wywołaj funkcje w programie głównym
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>

typedef struct Zespolona
{
    double re;
    double im;
} Zespolona;

void dodawanie(double complex z1, double complex z2)
{
    double complex wynik = z1 + z2;

    printf("Wynik dodawania: %.2f + %.2fI\n", creal(wynik), cimag(wynik));
}

void odejmowanie(double complex z1, double complex z2)
{
    double complex wynik = z1 - z2;

    printf("Wynik odejmowania: %.2f + %.2fI\n", creal(wynik), cimag(wynik));
}

void mnozenie(double complex z1, double complex z2)
{
    double complex wynik = z1 * z2;

    printf("Wynik mnozenia: %.2f + %.2fI\n", creal(wynik), cimag(wynik));
}

void dzielenie(double complex z1, double complex z2)
{
    double complex wynik = z1 / z2;

    printf("Wynik dzielenia: %.2f + %.2fI\n", creal(wynik), cimag(wynik));
}

void modulPierwszejLiczby(double complex z)
{
    printf("Moduł liczby: %.2f\n", cabs(z));
}

void sprzezenie(double complex z)
{
    printf("Sprzenie: %.2f+%.2fI\n", creal(z), cimag(z) * -1);
}

void kat(double complex z)
{
    printf("Kąt fazowy (w radianach): %.2f\n", carg(z));
}

int main()
{
    Zespolona *zespolone = (Zespolona *)malloc(2 * sizeof(Zespolona));

    printf("Podaj czesc Re: ");
    scanf("%lf", &zespolone[0].re);

    printf("Podaj czesc Im: ");
    scanf("%lf", &zespolone[0].im);

    printf("Podaj czesc Re: ");
    scanf("%lf", &zespolone[1].re);

    printf("Podaj czesc Im: ");
    scanf("%lf", &zespolone[1].im);

    double complex z1 = zespolone[0].re + zespolone[0].im * I;
    double complex z2 = zespolone[1].re + zespolone[1].im * I;

    dodawanie(z1, z2);
    odejmowanie(z1, z2);
    mnozenie(z1, z2);
    dzielenie(z1, z2);
    modulPierwszejLiczby(z1);
    sprzezenie(z1);
    kat(z1);

    free(zespolone);

    return 0;
}