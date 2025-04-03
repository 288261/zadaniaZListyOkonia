// Załóż w tablicy kartotekę studentów mieszkających w akademikach. Dla każdego studenta należy pamiętać:
// ---------------------
// nazwisko i imię,
// adres zamieszkania,
// numer akademika,
// wielkość dochodu przypadającego na jedną osobę w rodzinie studenta.
// Program powinien zapewnić wydruk zawartości kartoteki.

#include <stdlib.h>
#include <stdio.h>

typedef struct Student
{
    char imie[20];
    char nazwisko[50];
    int nrAkademika;
    int iloscCzlonkowRodziny;
    float dochod;
    float dochodNaOsobe;
} Student;

void wprowadzStudentow(Student *studenci, int iloscStudentow)
{
    for (int i = 0; i < iloscStudentow; i++)
    {
        char pobieraStypendium[2];

        printf("Wprowadz imie: ");
        scanf("%19s", studenci[i].imie);

        printf("Wprowadz nazwisko: ");
        scanf("%49s", studenci[i].nazwisko);

        printf("Wprowadz nr. akademika: ");
        scanf("%d", &studenci[i].nrAkademika);

        printf("Wprowadz ilosc czlonkow rodziny: ");
        scanf("%d", &studenci[i].iloscCzlonkowRodziny);

        printf("Wprowadz jaki jest dochod w calej rodzinie: ");
        scanf("%f", &studenci[i].dochod);

        float dochodNaOsobe = studenci[i].dochod / (float)studenci[i].iloscCzlonkowRodziny;
        studenci[i].dochodNaOsobe = dochodNaOsobe;
    }
}

void wyczytajStudentow(Student *studenci, int iloscStudentow)
{
    for (int i = 0; i < iloscStudentow; i++)
    {
        printf("Imie: %s, Nazwisko: %s, nr. akademika: %d, ilosc czlonkow rodziny: %d, dochod w rodzinie: %.2f, dochod na jedna osobe: %.2f\n", studenci[i].imie, studenci[i].nazwisko, studenci[i].nrAkademika, studenci[i].iloscCzlonkowRodziny, studenci[i].dochod, studenci[i].dochodNaOsobe);
    }
}

int main()
{
    int ileStudentow;

    printf("Ile chcesz podac studentow: ");
    scanf("%d", &ileStudentow);

    Student *studenci = (Student *)malloc(ileStudentow * sizeof(Student));

    wprowadzStudentow(studenci, ileStudentow);
    wyczytajStudentow(studenci, ileStudentow);

    free(studenci);

    return 0;
}