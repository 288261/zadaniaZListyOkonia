// Policzyć liczbę znaków w zbiorze tekstowym zawierającym program źródłowy napisany do
// niniejszego zadania. Następnie utworzyć nowy zbiór zawierający program źródłowy oraz
//  tekst o postaci: ZBIÓR <nazwa programu źródłowego> ZAWIERA <liczba bajtów> BAJTÓW.
#include <stdio.h>

int main()
{
    FILE *plik_we;
    FILE *plik_wy;
    char znak;
    int licznik = 0;

    plik_we = fopen("test.c", "r");
    plik_wy = fopen("test_z_info.c", "w");

    if (plik_we == NULL || plik_wy == NULL)
    {
        printf("Nie można otworzyć plików.\n");
        return 1;
    }

    while ((znak = fgetc(plik_we)) != EOF)
    {
        fputc(znak, plik_wy);
        licznik++;
    }

    fprintf(plik_wy, "\n//ZBIÓR test.c ZAWIERA %d BAJTÓW\n", licznik);

    fclose(plik_we);
    fclose(plik_wy);

    printf("Utworzono plik 'test_z_info.c'\n");

    return 0;
}
