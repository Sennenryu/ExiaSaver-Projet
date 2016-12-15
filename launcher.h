#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#define TAILLE_MAX 1000
int nbr1 =0;

void choix ()
{
    int nbr;
    srand (time (NULL));
    int _iMin = 1;
    int _iMax = 7;
    DIR *dir= NULL;

    dir = opendir("EXIASAVER1_PBM/");

    nbr = (_iMin + (rand () % (_iMax-_iMin+1)));

    if (nbr1==1)
    {
    	execl("statique","statique", 0, 0);
    }
    else if (nbr1==2)
    {
    	execl("dynamique1","dynamique1", 0, 0);
    }
    else
    {
    	execl("dynamique2","dynamique2", 0, 0);
    }
}
void randomm ()
{
    int iRandom = 0;
    int _iMin = 1;
    int _iMax = 3;

    system("clear");
    srand (time (NULL));

    nbr1 = (_iMin + (rand () % (_iMax-_iMin+1)));
}


void stati()
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";
    int a = 0;
    char format[128];
    time_t temps;        //D�claration des variables / format correspond � la longeur du r�sultat � afficher.
    struct tm date;
                         // On r�cup�re la date et l'heure actuelles.
    fichier = fopen("stats.txt", "a");
    time(&temps);
    date=*localtime(&temps);
                         // On remplit la cha�ne avec le format, puis on l'affiche.

    if (nbr1==1)
    {
        char prog1[] = "ScreenSaver 1";
        strftime(format, 128, "%x   %X || ", &date);
        fprintf(fichier, format);
        fprintf(fichier, prog1);
        fprintf(fichier, "\n");

        strftime(format, 128, " || %x   %X", &date);
        fprintf(fichier, prog1);
        fprintf(fichier, format);
        fprintf(fichier, "\n");

        strftime(format, 128, "%x   %X\n", &date);
        fprintf(fichier, format);
        fprintf(fichier, prog1);
        fprintf(fichier, "\n\n");
        fclose(fichier);
    }

    if (nbr1==2)
    {
        char prog2[] = "ScreenSaver 2";
        strftime(format, 128, "%x   %X || ", &date);
        fprintf(fichier, format);
        fprintf(fichier, prog2);
        fprintf(fichier, "\n");

        strftime(format, 128, " || %x   %X ", &date);
        fprintf(fichier, prog2);
        fprintf(fichier, format);
        fprintf(fichier, "\n");

        strftime(format, 128, "%x   %X\n", &date);
        fprintf(fichier, format);
        fprintf(fichier, prog2);
        fprintf(fichier, "\n\n");
        fclose(fichier);
    }
    if (nbr1==3)
    {
        char prog3[] = "ScreenSaver 3";
        strftime(format, 128, "%x   %X || ", &date);
        fprintf(fichier, format);
        fprintf(fichier, prog3);
        fprintf(fichier, "\n");

        strftime(format, 128, " || %x   %X", &date);
        fprintf(fichier, prog3);
        fprintf(fichier, format);
        fprintf(fichier, "\n");

        strftime(format, 128, "%x   %X\n", &date);
        fprintf(fichier, format);
        fprintf(fichier, prog3);
        fprintf(fichier, "\n\n");
        fclose(fichier);
    }

}
