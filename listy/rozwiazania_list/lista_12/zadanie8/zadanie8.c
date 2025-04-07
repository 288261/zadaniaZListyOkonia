// Napisać program, który dwa zbiory tekstowe, przepisze do jednego zbioru tekstowego.
#include <stdio.h>

int main()
{
    FILE *plik1;
    FILE *plik2;
    FILE *plik_wynik;
    char znak;

    // Otwarcie plików do odczytu i zapisania wyniku
    plik1 = fopen("plik1.txt", "r");
    plik2 = fopen("plik2.txt", "r");
    plik_wynik = fopen("polaczony.txt", "w");

    // Sprawdzenie, czy udało się otworzyć pliki
    if (plik1 == NULL || plik2 == NULL || plik_wynik == NULL)
    {
        printf("Nie można otworzyć któregoś z plików.\n");
        return 1;
    }

    // Kopiowanie zawartości pliku1 do pliku wynikowego
    while ((znak = fgetc(plik1)) != EOF)
    {
        fputc(znak, plik_wynik);
    }

    // Dodanie nowej linii między tekstami
    fputc('\n', plik_wynik); // Dodaje nową linię przed zapisaniem drugiego pliku

    // Kopiowanie zawartości pliku2 do pliku wynikowego
    while ((znak = fgetc(plik2)) != EOF)
    {
        fputc(znak, plik_wynik);
    }

    // Zamknięcie plików
    fclose(plik1);
    fclose(plik2);
    fclose(plik_wynik);

    printf("Utworzono plik 'polaczony.txt'\n");

    return 0;
}
