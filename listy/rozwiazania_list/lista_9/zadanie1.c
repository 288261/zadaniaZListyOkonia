// TO JEST KURWA KOD DO NAPISANIA W GODZINE?! XDDD

// W tablicy posiadającej n wierszy i m kolumn przechowywane są dane o energii elektrycznej
// pobranej w przeciągu jednego roku. Poszczególne wiersze odpowiadają poszczególnym odbiorcom,
//  kolumny – miesiącom. Należy:
//
// dla każdego odbiorcy obliczyć energię pobraną w ciągu całego roku, !
// dla każdego odbiorcy określić minimalną energię pobraną w ciągu jednego miesiąca, !
// dla każdego odbiorcy określić maksymalną energię pobraną w ciągu jednego miesiąca, !
// dla każdego odbiorcy określić miesiąc, w którym pobrana energia jest najmniejsza, !
// dla każdego odbiorcy określić miesiąc, w którym pobrana energia jest największa, !
// określić odbiorcę, który najwięcej pobrał energii w ciągu całego roku, !
// określić odbiorcę, który najmniej pobrał energii w ciągu całego roku, ! !
// obliczyć energię pobraną w każdym z wyróżnionych miesięcy, !
// określić miesiąc, w którym całkowita pobrana energia jest najmniejsza, !
// określić miesiąc, w którym całkowita pobrana energia jest największa, !
// obliczyć całą energię pobraną w ciągu roku, !
// obliczyć średnią energię pobraną w ciągu jednego miesiąca, !
// obliczyć średnią energię pobraną w ciągu jednego miesiąca przez jednego odbiorcę.
#include <stdlib.h>
#include <stdio.h>

void wprowadzDane(int n, float odbiorcy[][12])
{
    for (int u = 0; u < n; u++)
    {
        for (int m = 0; m < 12; m++)
        {
            scanf("%f", &odbiorcy[u][m]);
        }
    }
}

float obliczEnergieWRoku(float odbiorca[12])
{
    float suma = 0;

    for (int i = 0; i < 12; i++)
    {
        suma += odbiorca[i];
    }

    return suma;
}

void znajdzMaxMin(float wynikiOdbiorcy[12], int n)
{
    int minMiesiac = 1;
    int maxMiesiac = 1;

    float wartoscMinMiesiac = wynikiOdbiorcy[0];
    float wartoscMaxMiesiac = wynikiOdbiorcy[0];

    for (int i = 0; i < 12; i++)
    {
        if (wynikiOdbiorcy[i] > wartoscMaxMiesiac)
        {
            wartoscMaxMiesiac = wynikiOdbiorcy[i];
            maxMiesiac = i + 1;
        }
        if (wynikiOdbiorcy[i] < wartoscMinMiesiac)
        {
            wartoscMinMiesiac = wynikiOdbiorcy[i];
            minMiesiac = i + 1;
        }
    }

    printf("Uzytkownik[%d] ma najwieksza wartosc wynoszaca: %.2f w miesiacu: %d, oraz ma najmniejsza wartosc wynoszaca: %.2f w miesiacu: %d\n", n, wartoscMaxMiesiac, maxMiesiac, wartoscMinMiesiac, minMiesiac);
}

void obliczDane(float odbiorcy[][12], int n)
{
    float najwiekszyWynik = 0;
    int uzytkownikNajwiekszyWynik;
    float sumaKazdyMiesiac[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    const char nazwyMiesiecy[12][12] = {"styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec", "sierpien", "wrzesien", "pazdziernik", "listopad", "grudzien"};

    int uzytkownikKtoryNajwiecejPobral;
    float sumaNajwiecejPobral;

    int uzytkownikKtoryNajmniejPobral = -10;
    float sumaNajmniejPobral;

    for (int i = 0; i < n; i++)
    {
        // Obliczenie oraz pokazanie uzytkownika z suma energii w ciagu roku
        float suma = obliczEnergieWRoku(odbiorcy[i]);
        printf("suma[%i] %.2f\n", i + 1, suma);

        // ustawienie uzytkownika ktory pobral najwiecej energii
        if (suma > najwiekszyWynik)
        {
            najwiekszyWynik = suma;
            uzytkownikNajwiekszyWynik = i + 1;
        }

        // wypisanie kazdego uzytkownika jesli chodzi o najwiekszy miesiac najwieksza wartosc, oraz najmniejsza
        znajdzMaxMin(odbiorcy[i], i + 1);

        // znalezenie ktory uzytkownik pobral najwiecej energii w roku
        if (sumaNajwiecejPobral < suma)
        {
            sumaNajwiecejPobral = suma;
            uzytkownikKtoryNajwiecejPobral = i + 1;
        }

        // znalezenie ktory uzytkownik pobral najmniej energii w roku
        if (sumaNajmniejPobral > suma || uzytkownikKtoryNajmniejPobral == -10)
        {
            sumaNajmniejPobral = suma;
            uzytkownikKtoryNajmniejPobral = i + 1;
        }

        // Suma dla kazdego miesiaca
        for (int j = 0; j < 12; j++)
        {
            sumaKazdyMiesiac[j] += odbiorcy[i][j];
        }
    }

    printf("Uzytkownik ktory pobral najwiecej[%d] wartosc: %.2f\n", uzytkownikKtoryNajwiecejPobral, sumaNajwiecejPobral);
    printf("Uzytkownik ktory pobral najmniej[%d] wartosc: %.2f\n", uzytkownikKtoryNajmniejPobral, sumaNajmniejPobral);

    int miesiacNajwiecej = 0;
    float najwiecejWMiesiacu = sumaKazdyMiesiac[0];
    int miesiacNajmniej = 0;
    float najmniejWMiesiacu = sumaKazdyMiesiac[0];

    float sumaCalegoRoku = 0;

    // wyswietlenie poboru energii kazdy miesiac
    printf("Rozklad sumy poboru energii dla kazdego miesiaca: \n");
    for (int i = 0; i < 12; i++)
    {
        if (sumaKazdyMiesiac[i] > najwiecejWMiesiacu || miesiacNajwiecej == 0)
        {
            najwiecejWMiesiacu = sumaKazdyMiesiac[i];
            miesiacNajwiecej = i;
        }
        if (sumaKazdyMiesiac[i] < najmniejWMiesiacu || miesiacNajmniej == 0)
        {
            najmniejWMiesiacu = sumaKazdyMiesiac[i];
            miesiacNajmniej = i;
        }

        printf("%s: %.2f\n", nazwyMiesiecy[i], sumaKazdyMiesiac[i]);
        sumaCalegoRoku += sumaKazdyMiesiac[i];
    }
    printf("\n");

    // w ktorych miesiach suma zuzytych pradow byla najwieksza oraz najmniejsza
    printf("Najwiecej pradu zuzyto w miesiacu: %s\n", nazwyMiesiecy[miesiacNajwiecej]);
    printf("Najmniej pradu zuzyto w miesiacu: %s\n", nazwyMiesiecy[miesiacNajmniej]);

    // wyswietlenie calego zuzytego pradu w roku
    printf("Calkowity zuzyty prad: %.2f\n", sumaCalegoRoku);

    // wyswietlenie calego zuzytego pradu na miesiac(srednia)
    float sredniaNaMiesiac = sumaCalegoRoku / 12;
    printf("Srednia pradu zuzytego na miesiac to: %.2f\n", sredniaNaMiesiac);

    // wyswietlenie calego zuzytego pradu na miesiac(srednia) na jednego uzytkownika
    float sredniaNaMiesiacNaUzytkownika = sredniaNaMiesiac / n;
    printf("Srednia pradu zuzytego na miesiac przez jednego uzytkownika to: %.2f\n", sredniaNaMiesiacNaUzytkownika);
}

int main()
{
    int n;
    scanf("%d", &n);

    const int MAX_ILOSC_MIESIECY = 12;
    float odbiorcy[n][MAX_ILOSC_MIESIECY];

    wprowadzDane(n, odbiorcy);
    obliczDane(odbiorcy, n);

    return 0;
}