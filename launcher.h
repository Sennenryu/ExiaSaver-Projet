#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>
#include <conio.h>
#define TAILLE_MAX 1000
int nbr =0;

void Random ()
{
    int iRandom = 0;
    int _iMin = 1;
    int _iMax = 3;

    system("cls");
    srand (time (NULL));
    getch();

    nbr = (_iMin + (rand () % (_iMax-_iMin+1)));
}

void choix ()
{
    if (nbr==1)
    {
    system("statique");
    }
    else if (nbr==2)
    {
    system("dynamique1");
    }
    else
    {
    system("dynamique2");
    }
    return 0;
}

void stati()
{
    FILE* fichier = NULL;
    FILE* fichier2 = NULL;
    FILE* fichier3 = NULL;
    char chaine[TAILLE_MAX] = "";
    int a = 0;
    char format[128];
    time_t temps;        //Déclaration des variables / format correspond à la longeur du résultat à afficher.
    struct tm date;
                         // On récupère la date et l'heure actuelles.
    fichier = fopen("stats.txt", "a");
    fichier2 = fopen("stats2.txt", "a");
    fichier3 = fopen("stats3.txt", "a");
    time(&temps);
    date=*localtime(&temps);
                         // On remplit la chaîne avec le format, puis on l'affiche.

    if (nbr==1)
    {
        char prog1[] = "ScreenSaver 1";
        strftime(format, 128, "%x   %X || ", &date);
        fprintf(fichier, format);
        fprintf(fichier, prog1);
        fprintf(fichier, "\n");
        fclose(fichier);

        strftime(format, 128, " || %x   %X", &date);
        fprintf(fichier2, prog1);
        fprintf(fichier2, format);
        fprintf(fichier2, "\n");
        fclose(fichier2);

        strftime(format, 128, "%x   %X\n", &date);
        fprintf(fichier3, format);
        fprintf(fichier3, prog1);
        fprintf(fichier3, "\n\n");
        fclose(fichier3);
    }

    if (nbr==2)
    {
        char prog2[] = "ScreenSaver 2";
        strftime(format, 128, "%x   %X || ", &date);
        fprintf(fichier, format);
        fprintf(fichier, prog2);
        fprintf(fichier, "\n");
        fclose(fichier);

        strftime(format, 128, " || %x   %X ", &date);
        fprintf(fichier2, prog2);
        fprintf(fichier2, format);
        fprintf(fichier2, "\n");
        fclose(fichier2);

        strftime(format, 128, "%x   %X\n", &date);
        fprintf(fichier3, format);
        fprintf(fichier3, prog2);
        fprintf(fichier3, "\n\n");
        fclose(fichier3);
    }
    if (nbr==3)
    {
        char prog3[] = "ScreenSaver 3";
        strftime(format, 128, "%x   %X || ", &date);
        fprintf(fichier, format);
        fprintf(fichier, prog3);
        fprintf(fichier, "\n");
        fclose(fichier);

        strftime(format, 128, " || %x   %X", &date);
        fprintf(fichier2, prog3);
        fprintf(fichier2, format);
        fprintf(fichier2, "\n");
        fclose(fichier2);
        strftime(format, 128, "%x   %X\n", &date);
        fprintf(fichier3, format);
        fprintf(fichier3, prog3);
        fprintf(fichier3, "\n\n");
        fclose(fichier3);
    }

    return 0;

}
