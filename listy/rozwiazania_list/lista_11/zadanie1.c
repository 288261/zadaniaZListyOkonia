// Wypełnij z klawiatury, a następnie wyświetl na ekranie tablicę struktur
// zawierających informacje o studentach. Informacjami tymi są:
// -------------------------
// nazwisko i imię studenta,
// rok studiów,
// nr grupy,
// czy pobiera stypendium?

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Student
{
    char imie[20];
    char nazwisko[50];
    int rokStudiow;
    int nrGrupy;
    bool czyPobieraStypendium;
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

        printf("Wprowadz rok studiow: ");
        scanf("%d", &studenci[i].rokStudiow);

        printf("Wprowadz nr. grupy: ");
        scanf("%d", &studenci[i].nrGrupy);

        printf("Napisz czy pobiera stypendium(wpisz 't' dla tak lub 'n' dla nie): ");
        scanf("%s", pobieraStypendium);

        if (strcmp(pobieraStypendium, "t") == 0 || strcmp(pobieraStypendium, "T") == 0)
            studenci[i].czyPobieraStypendium = true;
        else
            studenci[i].czyPobieraStypendium = false;
    }
}

void wyczytajStudentow(Student *studenci, int iloscStudentow)
{
    for (int i = 0; i < iloscStudentow; i++)
    {
        char czyPobieraStypendium[4] = "";

        if (studenci[i].czyPobieraStypendium)
            strcpy(czyPobieraStypendium, "Tak");
        else
            strcpy(czyPobieraStypendium, "Nie");

        printf("Imie: %s, Nazwisko: %s, Rok studiow: %d, Nr. grupy: %d, czy pobiera stypendium: %s\n", studenci[i].imie, studenci[i].nazwisko, studenci[i].rokStudiow, studenci[i].nrGrupy, czyPobieraStypendium);
    }
}

int main()
{
    int ileStudentow;

    printf("Ile studentow: ");
    scanf("%d", &ileStudentow);

    Student *studenci = (Student *)malloc(ileStudentow * sizeof(Student));

    if (studenci == NULL)
    {
        printf("Blad alokacji pamieci!\n");
        return 1;
    }

    wprowadzStudentow(studenci, ileStudentow);
    wyczytajStudentow(studenci, ileStudentow);

    return 0;
}