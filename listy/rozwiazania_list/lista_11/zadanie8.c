// Należy posortować tablicę struktur w kolejności narastania wartości ich pól
//  numerycznych. Należy założyć, że element tablicy jest strukturą, z jednym
// polem numerycznym typu zmiennoprzecinkowego oraz z jednym polem typu znakowego.
#include <stdlib.h>
#include <stdio.h>

typedef struct Tablica
{
    float liczba;
    char znak[2];
} Tablica;

void wprowadzDane(struct Tablica *tablica)
{
    printf("Podaj liczbe: ");
    scanf("%f", &tablica->liczba);

    printf("Podaj znak: ");
    scanf("%2s", tablica->znak);
}

int porownajTablice(const void *a, const void *b)
{
    struct Tablica *tab1 = (struct Tablica *)a;
    struct Tablica *tab2 = (struct Tablica *)b;

    if (tab1->liczba > tab2->liczba)
        return 1;
    if (tab1->liczba < tab2->liczba)
        return -1;

    return 0;
}

void wyswietlDane(Tablica *tablica, int ileTablic)
{
    for (int i = 0; i < ileTablic; i++)
    {
        printf("Liczba: %.2f, znak: %s\n", tablica[i].liczba, tablica[i].znak);
    }
}

int main()
{
    int ileTablic;

    printf("Podaj ile tablice chcesz podac: ");
    scanf("%d", &ileTablic);

    Tablica *tablica = (Tablica *)malloc(ileTablic * sizeof(Tablica));

    for (int i = 0; i < ileTablic; i++)
    {
        wprowadzDane(&tablica[i]);
    }

    qsort(tablica, ileTablic, sizeof(Tablica), porownajTablice);

    wyswietlDane(tablica, ileTablic);

    free(tablica);

    return 0;
}