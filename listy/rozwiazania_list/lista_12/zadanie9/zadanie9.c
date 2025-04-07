// Załóż w pliku kartotekę studentów mieszkających w akademikach. Dla każdego studenta należy pamiętać:
// nazwisko i imię,
// adres zamieszkania,
// numer akademika,
// wielkość dochodu przypadającego na jedną osobę w rodzinie studenta.
// Program powinien zapewnić wydruk zawartości kartoteki.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char imie[50];
    char nazwisko[50];
    char adres[100];
    int numer_akademika;
    float dochod_na_osobe;
} Student;

void dodajStudenta(Student *student) {
    printf("Imie studenta: ");
    fgets(student->imie, sizeof(student->imie), stdin);
    student->imie[strcspn(student->imie, "\n")] = '\0';  
    
    printf("Nazwisko studenta: ");
    fgets(student->nazwisko, sizeof(student->nazwisko), stdin);
    student->nazwisko[strcspn(student->nazwisko, "\n")] = '\0'; 

    printf("Adres zamieszkania: ");
    fgets(student->adres, sizeof(student->adres), stdin);
    student->adres[strcspn(student->adres, "\n")] = '\0';  

    printf("Numer akademika: ");
    scanf("%d", &student->numer_akademika);
    
    printf("Dochód na osobę w rodzinie: ");
    scanf("%f", &student->dochod_na_osobe);

    while (getchar() != '\n');
}

void zapiszDoPliku(Student *studenci, int liczba_studentow, const char *nazwa_pliku) {
    FILE *plik = fopen(nazwa_pliku, "w");

    if (plik == NULL) {
        printf("Nie udało się otworzyć pliku do zapisu.\n");
        return;
    }

    for (int i = 0; i < liczba_studentow; i++) {
        fprintf(plik, "Student %d:\n", i + 1);
        fprintf(plik, "Imię i nazwisko: %s %s\n", studenci[i].imie, studenci[i].nazwisko);
        fprintf(plik, "Adres: %s\n", studenci[i].adres);
        fprintf(plik, "Numer akademika: %d\n", studenci[i].numer_akademika);
        fprintf(plik, "Dochód na osobę w rodzinie: %.2f\n\n", studenci[i].dochod_na_osobe);
    }

    fclose(plik);
    printf("Kartoteka została zapisana do pliku '%s'.\n", nazwa_pliku);
}

void wypiszKartoteke(Student *studenci, int liczba_studentow) {
    printf("\nKartoteka studentów:\n");
    for (int i = 0; i < liczba_studentow; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Imię i nazwisko: %s %s\n", studenci[i].imie, studenci[i].nazwisko);
        printf("Adres: %s\n", studenci[i].adres);
        printf("Numer akademika: %d\n", studenci[i].numer_akademika);
        printf("Dochód na osobę w rodzinie: %.2f\n", studenci[i].dochod_na_osobe);
    }
}

int main() {
    int liczba_studentow;
    
    printf("Ile studentów chcesz dodać? ");
    scanf("%d", &liczba_studentow);
    
    while (getchar() != '\n');

    Student *studenci = (Student *)malloc(liczba_studentow * sizeof(Student));
    if (studenci == NULL) {
        printf("Błąd alokacji pamięci!\n");
        return 1;
    }

    for (int i = 0; i < liczba_studentow; i++) {
        printf("\nPodaj dane studenta %d:\n", i + 1);
        dodajStudenta(&studenci[i]);
    }

    zapiszDoPliku(studenci, liczba_studentow, "kartoteka.txt");

    wypiszKartoteke(studenci, liczba_studentow);

    free(studenci);

    return 0;
}
