#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_MAX 1000
#include "launcher.h"

void choix();
void randomm();
void stati();


int main(int argc, char **argv)
{


    if (strcmp(argv[1] ,"-stat")== 0)
    {
        execl("stats","stats", 0, 0);
    }

    randomm ();
    choix();
    stati();

}
