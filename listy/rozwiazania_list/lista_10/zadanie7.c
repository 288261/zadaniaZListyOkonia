// Napisz program, w którym funkcja będzie zamieniała wartości zmiennych.
#include <stdlib.h>
#include <stdio.h>

void zamienWartosci(int *a, int *b)
{
    int kopia = *a;

    *a = *b;
    *b = kopia;
}

void pokazWartosci(int a, int b)
{
    printf("Wartosc a teraz wynosi: %d\n", a);
    printf("Wartosc b teraz wynosi: %d\n", b);
}

int main()
{
    int a;
    int b;

    printf("Podaj wartosc a oraz b: ");
    scanf("%d %d", &a, &b);

    // dlaczego &a oraz &b? w funkcji przekazalismy nie same wartosci funkcji a ich wartosci w pamieci
    // co to zmienia? jesli zmienilibysmy wartosci w innej funkcji poza main, to okazalo by sie potem ze
    // w funkcji main tak naprawde zostaly te same wartosci, a nie te zmieione
    zamienWartosci(&a, &b);
    pokazWartosci(a, b);

    return 0;
}