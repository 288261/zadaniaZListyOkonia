// Napisać program, który w tablicy struktur będzie przechowywał informacje o ocenach studentów. Informacjami tymi są:
// ---------------------------
// nazwisko i imię studenta,
// nr grupy,
// rok studiów,
// ocena.
// Program ma zapewnić:
// wypełnienie tablicy struktur,
// wydrukowanie listy studentów, których oceny mieszczą się w przedziale [4, 5] (należy zapewnić druk nazwiska i imienia studenta oraz oceny).
#include <stdlib.h>
#include <stdio.h>

typedef struct Student
{
    char imie[20];
    char nazwisko[50];
    int nrGrupy;
    int rokStudiow;
    float ocena;
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

        printf("Wprowadz nr. grupy: ");
        scanf("%d", &studenci[i].nrGrupy);

        printf("Wprowadz rok studiow: ");
        scanf("%d", &studenci[i].rokStudiow);

        printf("Podaj ocene: ");
        scanf("%f", &studenci[i].ocena);
    }
}

void wyczytajStudentow(Student *studenci, int iloscStudentow)
{
    for (int i = 0; i < iloscStudentow; i++)
    {
        if (studenci[i].ocena >= 4.0)
            printf("Imie: %s, Nazwisko: %s, nr. grupy: %d, rok studiow: %d, ocena: %.1f\n", studenci[i].imie, studenci[i].nazwisko, studenci[i].nrGrupy, studenci[i].rokStudiow, studenci[i].ocena);
    }
}

int main()
{
    int ileStudentow;

    printf("Podaj ile studentow: ");
    scanf("%d", &ileStudentow);

    Student *studenci = (Student *)malloc(ileStudentow * sizeof(Student));

    wprowadzStudentow(studenci, ileStudentow);
    wyczytajStudentow(studenci, ileStudentow);

    free(studenci);

    return 0;
}