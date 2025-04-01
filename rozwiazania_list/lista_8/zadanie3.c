// Napisz funkcję, która zwraca wartość bezwzględna podawanej w argumencie liczby
#include <stdlib.h>
#include <stdio.h>

int bezwzgledna(int liczba)
{
    if (liczba < 0)
        return -liczba;
    return liczba;
}

int main()
{
    printf("%d\n", bezwzgledna(-5));

    return 0;
}