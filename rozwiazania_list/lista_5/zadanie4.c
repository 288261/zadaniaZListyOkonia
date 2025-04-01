// Dana jest liczba całkowita z przedziału [1, 12] oznaczająca miesiąc. Wydrukować kwartał, w którym jest ten miesiąc.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int nrMiesiaca;

    const int MAX_MIESIAC = 12;
    const int KWARTAL_2 = 3;
    const int KWARTAL_3 = 6;
    const int KWARTAL_4 = 9;

    scanf("%d", &nrMiesiaca);

    if (nrMiesiaca > MAX_MIESIAC || nrMiesiaca < 1)
        printf("Nie ma takiego miesiaca!\n");
    else if (nrMiesiaca > KWARTAL_4)
        printf("Kwartal 4\n");
    else if (nrMiesiaca > KWARTAL_3)
        printf("Kwartal 3\n");
    else if (nrMiesiaca > KWARTAL_2)
        printf("Kwartal 2\n");
    else
        printf("Kwartal 1\n");

    return 0;
}