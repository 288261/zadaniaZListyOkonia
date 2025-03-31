// Napisz program wyznaczający największą z czterech liczb podanych przez użytkownika.
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // zadeklarowanie 4 liczby
    int a, b, c, d;

    // wpisanie 4 liczb
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // sprawdzenie, ktora liczba jest najwieksza

    if (a > b && a > c && a > d) // czy liczba a jest najwieksza
    {
        printf("%d\n", a);
    }
    else if (b > a && b > c && b > d) // czy liczba b jest najwieksza
    {
        printf("%d\n", b);
    }
    else if (c > a && c > b && c > d) // czy liczba c jest najwieksza
    {
        printf("%d\n", c);
    }
    else
    {
        printf("%d\n", d); // czy liczba d jest najwieksza, badz wszystkie liczby sa takie same
    }
}