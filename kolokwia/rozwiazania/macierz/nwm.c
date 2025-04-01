#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Funkcja do wprowadzania macierzy A
void wprowadzMacierz(float macierz[MAX][MAX], int n) {
    printf("Podaj elementy macierzy A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &macierz[i][j]);
        }
    }
}

// Funkcja do wprowadzania wektora x
void wprowadzWektor(float wektor[MAX], int n) {
    printf("Podaj elementy wektora x:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &wektor[i]);
    }
}

// Funkcja do obliczania b = A * x
void obliczWektorB(float macierz[MAX][MAX], float wektor[MAX], float wynik[MAX], int n) {
    for (int i = 0; i < n; i++) {
        wynik[i] = 0;
        for (int j = 0; j < n; j++) {
            wynik[i] += macierz[i][j] * wektor[j];
        }
    }
}

// Funkcja do wyświetlania wektora b
void wyswietlWektor(float wynik[MAX], int n) {
    printf("Wektor b = A * x:\n");
    for (int i = 0; i < n; i++) {
        printf("%8.4f\n", wynik[i]);
    }
}

int main() {
    int nMacierzy;
    float macierz[MAX][MAX];
    float wektor[MAX];
    float wynik[MAX];

    // Wprowadzanie rozmiaru macierzy
    printf("Podaj rozmiar macierzy n (max 10): ");
    scanf("%d", &nMacierzy);

    if (nMacierzy <= 0 || nMacierzy > MAX) {
        printf("Niepoprawny rozmiar macierzy!\n");
        return 1;
    }

    // Wprowadzenie macierzy A
    wprowadzMacierz(macierz, nMacierzy);

    // Wprowadzenie wektora x
    wprowadzWektor(wektor, nMacierzy);

    // Obliczanie b = A * x
    obliczWektorB(macierz, wektor, wynik, nMacierzy);

    // Wyświetlanie wyniku
    wyswietlWektor(wynik, nMacierzy);

    return 0;
}