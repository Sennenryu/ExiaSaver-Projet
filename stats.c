#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_MAX 1000

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";
    int a=0;
    int x = 1;
    int y = 2;
    int z = 3;
    int caractereLu, ligne = 1, caractereoui;

    printf("==============STATISTIQUES==============\n\n");
    printf(" Nous vous proposons 3 modes          \n");
    printf(" d'affichages :                       \n\n");
    printf("    1. Date/ScreenSaver/Parametre     \n");
    printf("    2. ScreenSaver/Parametre/Date     \n");
    printf("    3.          Date\n       ScreenSaver/Parametre\n\n\n");
    while ((a!=1)||(a!=2)||(a!=3))
    {
        printf("Quel affichage voules-vous ?\n");
        scanf("%d", &a);
        if (a==1)
        {
            fichier = fopen("stats.txt", "r");

            caractereoui=fgetc(fichier);
            printf("%c", caractereoui);
    		fclose(fichier);
    		fichier = fopen("stats.txt", "r");
      		while (caractereLu!=EOF)
      		{
			    caractereLu=fgetc(fichier);
			    if (caractereLu=='\n')
   			    {
   			    	ligne++;

   				}

				if(ligne == x)
   				{
   					fgets(chaine,TAILLE_MAX,fichier);
				    printf("%s", chaine);
				    x = x+4;

				}

      	 	}

            fclose(fichier);
            break;
        }

        if (a==2)
        {

    		fichier = fopen("stats.txt", "r");
      		while (caractereLu!=EOF)
      		{
			    caractereLu=fgetc(fichier);
			    if (caractereLu=='\n')
   			    {
   			    	ligne++;

   				}

				if(ligne == y)
   				{
   					fgets(chaine,TAILLE_MAX,fichier);
				    printf("%s", chaine);
				    y = y+4;

				}

      	 	}


            fclose(fichier);
            break;
        }

        if (a==3)
        {

    		fichier = fopen("stats.txt", "r");
      		while (caractereLu!=EOF)
      		{
			    caractereLu=fgetc(fichier);
			    if (caractereLu=='\n')
   			    {
   			    	ligne++;

   				}

				if(ligne == z)
   				{
   					fgets(chaine,TAILLE_MAX,fichier);
				    printf("%s", chaine);
				    fgets(chaine,TAILLE_MAX,fichier);
					printf("%s", chaine);
   					printf("\n");
				    z = z+3;

				}


      	 	}

            fclose(fichier);
            break;
        }
    }
    printf("\n");
    char c = getchar();
    system("stty cbreak -echo");
    getchar();
    system("stty cooked echo");
    system("clear");

    return 0;
}
