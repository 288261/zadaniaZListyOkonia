// Napisać program, który w tablicy struktur będzie przechowywał informacje o akademikach.
//  Dla każdego akademika ma być przechowywane:
// -------------------------
// adres akademika,
// nr akademika,
// liczba miejsc w akademiku,
// aktualna liczba mieszkańców.
// Program ma zapewnić:
// wpisywanie kolejnych informacji do tablicy w taki sposób, by były one uporządkowane według numeru akademika,
// wydruk zawartości tablicy.

#include <stdlib.h>
#include <stdio.h>

typedef struct Akademik
{
    char adres[50];
    int nr;
    int liczbaMiejsc;
    int liczbaMieszkancow;
} Akademik;

void wprowadzAkademiki(Akademik *akademiki, int ileAkademikow)
{
    for (int i = 0; i < ileAkademikow; i++)
    {
        printf("Wprowadz adres akademika: ");
        scanf("%s", akademiki[i].adres);

        printf("Wprowadz nr. akademika: ");
        scanf("%d", &akademiki[i].nr);

        printf("Wprowadz liczbe miejsc: ");
        scanf("%d", &akademiki[i].liczbaMiejsc);

        printf("Wprowadz liczbe mieszkancow: ");
        scanf("%d", &akademiki[i].liczbaMieszkancow);
    }
}

void wyczytajAkademiki(Akademik *akademiki, int ileAkademikow)
{
    for (int i = 0; i < ileAkademikow; i++)
    {
        printf("Nr: %d, adres: %s, liczba miejsc: %d, liczba mieszkancow: %d\n", akademiki[i].nr, akademiki[i].adres, akademiki[i].liczbaMiejsc, akademiki[i].liczbaMieszkancow);
    }
}

int porownajAkademiki(const void *a, const void *b)
{
    Akademik *ak1 = (Akademik *)a;
    Akademik *ak2 = (Akademik *)b;

    if (ak1->nr < ak2->nr)
        return -1;
    if (ak1->nr > ak2->nr)
        return 1;

    return 0;
}

int main()
{
    int ileAkademikow;

    printf("Podaj ile akademikow: ");
    scanf("%d", &ileAkademikow);

    Akademik *akademiki = (Akademik *)malloc(ileAkademikow * sizeof(Akademik));

    wprowadzAkademiki(akademiki, ileAkademikow);

    qsort(akademiki, ileAkademikow, sizeof(Akademik), porownajAkademiki);

    wyczytajAkademiki(akademiki, ileAkademikow);

    return 0;
}