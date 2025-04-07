// Utworzyć zbiór zawierający dowolny tekst. Napisać program wyświetlający ten tekst
// na ekranie z pominięciem zbędnych odstępów między słowami tekstu tzn. należy
// pozostawić tylko jedną spację między kolejnymi słowami.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *text = "  To jest    przykładowy tekst  z   wieloma     odstępami.    ";

    char *result = malloc(strlen(text) + 1);
    if (result == NULL)
    {
        printf("Błąd alokacji pamięci!\n");
        return 1;
    }

    int i = 0, j = 0;

    while (text[i] != '\0')
    {
        if (text[i] == ' ' && text[i + 1] == ' ')
        {
            i++;
        }
        else
        {
            result[j++] = text[i++];
        }
    }

    if (j > 0 && result[j - 1] == ' ')
    {
        j--;
    }

    result[j] = '\0';

    printf("Przetworzony tekst: '%s'\n", result);

    free(result);

    return 0;
}
