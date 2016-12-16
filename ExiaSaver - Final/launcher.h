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
}
void randomm ()
{
    int iRandom = 0;
    int _iMin = 1;
    int _iMax = 2;

    system("clear");
    srand (time (NULL));

    nbr1 = (_iMin + (rand () % (_iMax-_iMin+1)));
}

