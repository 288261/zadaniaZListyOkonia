// Dana jest liczba całkowita z przedziału [1, 4] oznaczająca numer kwartału. Wydrukować nazwy miesięcy, które są w kwartale o podanym numerze.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int kwartal;

    const int ILOSC_KWARTALOW = 4;
    const int KWARTAL_MIESIECY = 3;
    const char KWARTALY[ILOSC_KWARTALOW][3][11] = {
        {"Styczen", "Luty", "Marzec"},
        {"Kwiecien", "Maj", "Czerwiec"},
        {"Lipiec", "Sierpien", "Wrzesien"},
        {"Pazdziernik", "Listopad", "Grudzien"}};

    scanf("%d", &kwartal);

    // sprawdzamy czy podany kwartal jest z przedzialu [1,4]
    if (kwartal > ILOSC_KWARTALOW || kwartal < 1)
        return printf("Podano zly numer kwartalu\n");

    // da sie to zrobic bez petli for, o wiele prosciej sie to da zrobic
    for (int i = 0; i < KWARTAL_MIESIECY; i++)
    {
        printf("%s\n", KWARTALY[kwartal - 1][i]);
    }

    return 0;
}