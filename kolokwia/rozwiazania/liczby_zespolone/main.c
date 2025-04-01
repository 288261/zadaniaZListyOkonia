#include <stdlib.h>
#include <stdio.h>

// Funkcja dodająca liczby zespolone
float *dodawanieLiczbZespolonych(float a[2], float b[2])
{
    static float c[2]; // Tablica statyczna, aby zwrócić jej wskaźnik

    c[0] = a[0] + b[0]; // Część rzeczywista
    c[1] = a[1] + b[1]; // Część urojona

    return c; // Zwracamy wskaźnik na tablicę
}

// Funkcja odejmująca liczby zespolone
float *odejmowanieLiczbZespolonych(float a[2], float b[2])
{
    static float c[2];

    c[0] = a[0] - b[0];
    c[1] = a[1] - b[1];

    return c;
}

// Funkcja obliczająca sprzężenie liczby zespolonej
float *sprzezenieLiczbyZespolonej(float a[2])
{
    static float b[2];

    b[0] = a[0];  // Część rzeczywista
    b[1] = -a[1]; // Część urojona (zmiana znaku)

    return b; // Zwracamy wskaźnik na tablicę
}

// Funkcja dzieląca liczby zespolone
float *dzielenieLiczbyZespolonej(float a[2], float b[2])
{
    static float c[2]; // Tablica statyczna, aby zwrócić jej wskaźnik

    float licznikCzescRe = a[0] * b[0] + a[1] * b[1]; // Część rzeczywista
    float licznikCzescIm = a[1] * b[0] - a[0] * b[1]; // Część urojona

    float mianownik = b[0] * b[0] + b[1] * b[1]; // Moduł b^2

    c[0] = licznikCzescRe / mianownik; // Część rzeczywista wyniku
    c[1] = licznikCzescIm / mianownik; // Część urojona wyniku

    return c; // Zwracamy wskaźnik na tablicę
}

float *mnozenieLiczbZespolonych(float a[2], float b[2])
{
    static float c[2];
    c[0] = a[0] * b[0] - a[1] * b[1];
    c[1] = a[0] * b[1] + a[1] * b[0];
    return c;
}

int main()
{
    float z1[2] = {1, 2}; // z1 = 3 + 3i
    float z2[2] = {3, 4}; // z2 = 1 + i
    float z3[2] = {2, 2};

    float *z1Sprzezenie = sprzezenieLiczbyZespolonej(z1);
    float *z2Sprzezenie = sprzezenieLiczbyZespolonej(z2);
    float *z3Sprzezenie = sprzezenieLiczbyZespolonej(z3);
    float *dodawanieLicznik = dodawanieLiczbZespolonych(z1, z3);
    float *dodawanieMianownik = dodawanieLiczbZespolonych(z2, z1);
    float *dzielenieLiczbyZespolonejWynik = dzielenieLiczbyZespolonej(dodawanieLicznik, dodawanieMianownik);
    float *koncowyWynik = dodawanieLiczbZespolonych(z1Sprzezenie, dzielenieLiczbyZespolonejWynik);

    printf("pojebane gowno: %f + %fi\n", koncowyWynik[0], koncowyWynik[1]);

    return 0;
}
