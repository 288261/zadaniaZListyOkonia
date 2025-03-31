// Napisz program, który wystawi ocenę z testu:`
// 0 - 20 pkt – 2.0
// 21- 25 pkt – 3.0
// 26 - 30 pkt – 3.5
// 36 - 40 pkt – 4.0
// 41- 45 pkt – 4.5
// 46 - 50 pkt – 5.0
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // zmienna przechowujaca ilosc punktow
    int iloscPunktow;
    // maksymalna ilosc punktow, stala ktorej nie mozna zmienic w trakcie dzialania programu
    const int MAX_PUNKTOW = 50;

    // wczytanie ilosc punktow
    scanf("%d", &iloscPunktow);

    // sprawdzenie ilosci punktow i wypisanie oceny
    if (iloscPunktow > MAX_PUNKTOW || iloscPunktow < 0) // sprawdzenie czy ilosc punktow nie przewyzsza maksymalnej ilosci punktow oraz czy nie jest ponizej 0
        printf("Niepoprawna ilosc punktow\n");
    else if (iloscPunktow >= 46)
        printf("5.0\n");
    else if (iloscPunktow >= 41)
        printf("4.5\n");
    else if (iloscPunktow >= 36)
        printf("4.0\n");
    else if (iloscPunktow >= 26)
        printf("3.5\n");
    else if (iloscPunktow >= 21)
        printf("3.0\n");
    else
        printf("2.0\n");

    return 0;
}