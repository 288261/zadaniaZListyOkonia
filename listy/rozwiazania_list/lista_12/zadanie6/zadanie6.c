// Wprowadzić z klawiatury ciąg liczb rzeczywistych do pliku tekstowego (każda liczba powinna
// znaleźć się w oddzielnej linii).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *plik;
    char linia[100];
    int ile_liczb;
    int i;
    double liczba;

    printf("Ile liczb chcesz wprowadzić? ");
    fgets(linia, sizeof(linia), stdin);
    ile_liczb = atoi(linia);

    plik = fopen("liczby.txt", "w");

    for (i = 0; i < ile_liczb; i++)
    {
        printf("Wprowadź liczbę %d: ", i + 1);
        fgets(linia, sizeof(linia), stdin);
        liczba = atof(linia);
        fprintf(plik, "%.10g\n", liczba);
    }

    fclose(plik);
    printf("Liczby zapisane do pliku 'liczby.txt'\n");

    return 0;
}
