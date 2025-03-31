// Należy wczytać ciąg liczb rzeczywistych. Wczytywanie należy zakończyć, gdy pojawi się
// liczba ujemna. Dla każdej wczytanej liczby należy obliczyć jej kwadrat. Numer kolejny
// liczby, tę  liczbę oraz jej kwadrat należy wyświetlić na ekranie.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int liczba;

    while (liczba >= 0)
    {
        scanf("%d", &liczba);

        if (liczba >= 0)
        {
            int kwadratLiczby = liczba * liczba;
            int numerKolejnyLiczby = liczba + 1;

            printf("Liczba %d %d %d\n", numerKolejnyLiczby, liczba, kwadratLiczby);
        }
    }

    return 0;
}