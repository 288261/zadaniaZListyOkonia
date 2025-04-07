// Wprowadzić z klawiatury ciąg dat zapisanych w postaci łańcuchów dziesięcioznakowych do
//  pliku tekstowego (każda data powinna znaleźć się w oddzielnej linii).
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *plik;
    char linia[100];
    int liczba_dat;
    int i;
    char data[11];

    printf("Ile dat chcesz wprowadzić? ");
    fgets(linia, sizeof(linia), stdin);
    liczba_dat = atoi(linia);

    plik = fopen("daty.txt", "w");

    for (i = 0; i < liczba_dat; i++)
    {
        printf("Wprowadź datę %d (RRRR-MM-DD): ", i + 1);
        fgets(data, sizeof(data), stdin);

        if (strchr(data, '\n'))
        {
            data[strcspn(data, "\n")] = '\0';
        }
        else
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

        fprintf(plik, "%s\n", data);
    }

    fclose(plik);
    printf("Daty zapisane do pliku 'daty.txt'\n");

    return 0;
}
