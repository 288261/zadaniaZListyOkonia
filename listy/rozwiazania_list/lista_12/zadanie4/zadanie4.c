// Napisać program, który dopisze otrzymywane przy jego pomocy wyniki obliczeń na koniec
// zbioru zawierającego odpowiadający mu program źródłowy. Program ma podawać rozwiązanie układu równań
// które można zapisać następująco:
#include <stdio.h>

int main()
{
    // Dane układu równań
    double a1 = 2, b1 = 3, c1 = 8;
    double a2 = 1, b2 = -4, c2 = -2;

    // Wyznaczniki metodą Cramera
    double W = a1 * b2 - a2 * b1;
    double Wx = c1 * b2 - c2 * b1;
    double Wy = a1 * c2 - a2 * c1;

    if (W == 0)
    {
        printf("Układ nie ma jednoznacznego rozwiązania.\n");
        return 1;
    }

    double x = Wx / W;
    double y = Wy / W;

    printf("Rozwiązanie: x = %.2f, y = %.2f\n", x, y);

    FILE *src = fopen(__FILE__, "a");
    if (src != NULL)
    {
        fprintf(src, "\n// Rozwiązanie: x = %.2f, y = %.2f\n", x, y);
        fclose(src);
    }
    else
    {
        printf("Nie udało się otworzyć pliku źródłowego do zapisu.\n");
    }

    return 0;
}
