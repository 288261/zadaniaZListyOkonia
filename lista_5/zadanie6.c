// Dany jest dzień i  miesiąc. Wydrukować nazwę pory roku.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int miesiac, dzien;

    const int ILOSC_POR_ROKU = 4;
    const int ILOSC_MIESIECY = 12;
    const int DNI_W_MIESIACU[ILOSC_MIESIECY] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d %d", &miesiac, &dzien);

    // sprawdzenie poprawnosci wprowadzonych danych, czy miesiac nie jest ujemny lub wiekszy niz 12
    if (miesiac > ILOSC_MIESIECY || miesiac < 1)
        return printf("Podano zly numer miesiaca\n");
    // sprawdzenie czy dany miesiac ma rzeczywiscie dana ilosc dni
    if (dzien > DNI_W_MIESIACU[miesiac - 1] || dzien < 1)
        return printf("Podano zly numer dnia\n");

    // sprawdzenie pory roku
    if (miesiac == 1 || miesiac == 2 || (miesiac == 3 && dzien < 21) || (miesiac == 12 && dzien >= 22))
        printf("Zima\n");
    else if (miesiac == 4 || miesiac == 5 || (miesiac == 6 && dzien < 22) || (miesiac == 3 && dzien >= 21))
        printf("Wiosna\n");
    else if (miesiac == 7 || miesiac == 8 || (miesiac == 9 && dzien < 23) || (miesiac == 6 && dzien >= 22))
        printf("Lato\n");
    else
        printf("Jesien\n");

    return 0;
}