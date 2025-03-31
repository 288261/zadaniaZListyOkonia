// Należy wczytać z klawiatury liczbę naturalną n (n  100), określającą wiek pewnej osoby w latach.
// Wiek ten ma być wyświetlony na ekranie monitora łącznie z odpowiednim słowem “rok”, “lata” lub “lat”,
// np. 1 rok, 3 lata, 18 lat, 43 lata itd.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int wiek;

    scanf("%d", &wiek);

    if (wiek > 100 || wiek < 0)
        return printf("Podano zly wiek\n");

    if (wiek == 1)
        printf("%d rok", wiek);
    else if ((wiek % 10 == 2 || wiek % 10 == 3 || wiek % 10 == 4) && wiek != 12 && wiek != 13 && wiek != 14)
        printf("%d lata\n", wiek);
    else
        printf("%d lat\n", wiek);

    return 0;
}