#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define Largeur_console 80
#define Longueur_console 24


int main()
{
    int nbr;
    srand (time (NULL));
    int _iMin = 1;
    int _iMax = 7;
    int iRandom = 0;
	int a = 0;
	// int fils;
	// int pere;
    int carren = 70;
    nbr = (_iMin + (rand () % (_iMax-_iMin+1)));
    system("clear");

    if (nbr==1)
    {
        // fils = fork();
        FILE* fichier = NULL;  // Défini le pointeur a Null
        fichier = malloc(sizeof(FILE));

        int caractereActuel = 0;
        fichier = fopen("EXIASAVER1_PBM/Test_Maison.pbm", "r"); // "r" Dit que l'on veut juste lire le fichier
                            // Emplacement du fichier ( sous Linux on écrit le chemin cmme sous linux )

        while (caractereActuel != EOF)
        {
            caractereActuel = fgetc(fichier);
            if(caractereActuel==49)
            {
                printf("%c", carren);
            }
            if(caractereActuel==48)
            {
                printf(" ");
            }
            a+= 1;
            if (a==101)
            {
                printf("\n");
                a=0;
            }
        }
        fclose(fichier); // On ferme le fichier, on libère la memoire

    }

    else if (nbr==2)
    {
        // fils = fork();
        FILE* fichier = NULL;
        fichier = malloc(sizeof(FILE));
        int caractereActuel2 = 0;
        fichier = fopen("EXIASAVER1_PBM/Test_Genji.pbm", "r");

        while (caractereActuel2 != EOF)
        {
            caractereActuel2 = fgetc(fichier);
            if(caractereActuel2==49)
            {
                printf("%c", carren);
            }
            if(caractereActuel2==48)
            {
                printf(" ");
            }
            a+= 1;

            if (a==101)
            {
                printf("\n");
                a=0;
            }
        }
        fclose(fichier); // On ferme le fichier, on libère la memoire
    }

    else if (nbr==3)
    {
        // fils = fork();
        FILE* fichier = NULL;
        fichier = malloc(sizeof(FILE));
        int caractereActuel3 = 0;
        fichier = fopen("EXIASAVER1_PBM/Test_2_bonhommes.pbm", "r");

        while (caractereActuel3 != EOF)
        {
            caractereActuel3 = fgetc(fichier);
            if(caractereActuel3==49)
            {
                printf("%c", carren);
            }
            if(caractereActuel3==48)
            {
                printf(" ");
            }
            a+= 1;

            if (a==101)
            {
                printf("\n");
                a=0;

            }
        }
        fclose(fichier); // On ferme le fichier, on libère la memoire
    }

    else if (nbr==4)
    {
        // fils = fork();
        FILE* fichier = NULL;
        fichier = malloc(sizeof(FILE));
        int caractereActuel4 = 0;
        fichier = fopen("EXIASAVER1_PBM/Test_Sapin.pbm", "r");

        while (caractereActuel4 != EOF)
        {
            caractereActuel4 = fgetc(fichier);
            if(caractereActuel4==49)
            {
                printf("%c", carren);
            }
            if(caractereActuel4==48)
            {
                printf(" ");
            }
            a+= 1;

            if (a==101)
            {
                printf("\n");
                a=0;
            }
        }
        fclose(fichier); // On ferme le fichier, on libère la memoire
    }

    else if (nbr==5)
    {
        // fils = fork();
        FILE* fichier = NULL;
        fichier = malloc(sizeof(FILE));
        int caractereActuel5 = 0;
        fichier = fopen("EXIASAVER1_PBM/Test_Trident.pbm", "r");

        while (caractereActuel5 != EOF)
        {
            caractereActuel5 = fgetc(fichier);
            if(caractereActuel5==49)
            {
                printf("%c", carren);
            }
            if(caractereActuel5==48)
            {
                printf(" ");
            }
            a+= 1;
            if (a==101)
            {
                printf("\n");
                a=0;
            }
        }
        fclose(fichier); // On ferme le fichier, on libère la memoire
    }
    else if (nbr==6)
    {
        // fils = fork();
        FILE* fichier = NULL;
        fichier = malloc(sizeof(FILE));
        int caractereActuel6 = 0;
        fichier = fopen("EXIASAVER1_PBM/Test_Snake.pbm", "r");

        while (caractereActuel6 != EOF)
        {
            caractereActuel6 = fgetc(fichier);
            if(caractereActuel6==49)
            {
                printf("%c", carren);
            }
            if(caractereActuel6==48)
            {
                printf(" ");
            }
            a+= 1;
            if (a==101)
            {
                printf("\n");
                a=0;
            }
        }
        fclose(fichier); // On ferme le fichier, on libère la memoire
    }
    else if (nbr==7)
    {
        // fils = fork();
        FILE* fichier = NULL;
        fichier = malloc(sizeof(FILE));
        int caractereActuel7 = 0;
        fichier = fopen("EXIASAVER1_PBM/Test_Poisson.pbm", "r"); //emplacement du fichier


        while (caractereActuel7 != EOF)
        {
            caractereActuel7 = fgetc(fichier);
            if(caractereActuel7==49)
            {
                printf("%c", carren);
            }
            if(caractereActuel7==48)
            {
                printf("~");
            }
            if(caractereActuel7==50)
            {
                printf(" ");
            }
            a+= 1;
            if (a==101)
            {
                printf("\n");
                a=0;
            }
        }
        fclose(fichier); // On ferme le fichier, on libère la memoire
    }
    printf("\n");
    char c = getchar();
    system("stty cbreak -echo");
    getchar();
    system("stty cooked echo");
    system("clear");
    return 0;

}
