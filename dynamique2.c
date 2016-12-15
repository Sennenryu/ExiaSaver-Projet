#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fichier_avb = NULL;
    FILE* fichier_avd = NULL;
    FILE* fichier_avg = NULL;
    FILE* fichier_avh = NULL;
    int a = 0;
    int caractereActuel = 0;
    int carren = 254;
    fichier_avb = fopen("EXIASAVER3_PBM/Avion_bas.pbm", "r");
    fichier_avd = fopen("EXIASAVER3_PBM/Avion_droite.pbm", "r");
    fichier_avg = fopen("EXIASAVER3_PBM/Avion_gauche.pbm", "r");
    fichier_avh = fopen("EXIASAVER3_PBM/Avion_haut.pbm", "r");
    system("clear");

    while (caractereActuel != EOF)
    {
        caractereActuel = fgetc(fichier_avb);
        if(caractereActuel==49)
        {
            printf("%c", carren);
        }
        if(caractereActuel==48)
        {
            printf(" ");
        }
        a += 1;
        if (a==13)
        {
            printf("\n");
            a=0;
        }

    }


    fclose(fichier_avb);

}
