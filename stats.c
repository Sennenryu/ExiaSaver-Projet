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

    printf("==============STATISTIQUES==============\n\n");		///Affichage du menu de l'historique
    printf(" Nous vous proposons 3 modes          \n");
    printf(" d'affichages :                       \n\n");
    printf("    1. Date/ScreenSaver/Parametre     \n");
    printf("    2. ScreenSaver/Parametre/Date     \n");
    printf("    3.          Date\n       ScreenSaver/Parametre\n\n\n");
    while ((a!=1)||(a!=2)||(a!=3))
    {
        printf("Quel affichage voules-vous ?\n");     ///Choix de l'affichage
        scanf("%d", &a);
        if (a==1)
        {
            fichier = fopen("stats.txt", "r");		///On ouvre le fichier stat et on le lit

            caractereoui=fgetc(fichier);			
            printf("%c", caractereoui);
    		fclose(fichier);
    		fichier = fopen("stats.txt", "r");	
      		while (caractereLu!=EOF)			///boucle pour lire tout le fichier		
      		{
			    caractereLu=fgetc(fichier);		///On lit le caractère
			    if (caractereLu=='\n')
   			    {
   			    	ligne++;

   				}

				if(ligne == x)			//Quel ligne lire
   				{
   					fgets(chaine,TAILLE_MAX,fichier);	///afficher la ligne
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
      		while (caractereLu!=EOF)		///boucle pour lire tout le fichier
      		{
			    caractereLu=fgetc(fichier);		///On lit le caractère
			    if (caractereLu=='\n')
   			    {
   			    	ligne++;

   				}

				if(ligne == y)			///Quel ligne lire
   				{
   					fgets(chaine,TAILLE_MAX,fichier);		///afficher la ligne
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
      		while (caractereLu!=EOF)		///boucle pour lire tout le fichier
      		{
			    caractereLu=fgetc(fichier);		///On lit lecaractère
			    if (caractereLu=='\n')
   			    {
   			    	ligne++;

   				}

				if(ligne == z)			///Quel ligne lire
   				{
   					fgets(chaine,TAILLE_MAX,fichier);	///afficher la ligne
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
	
    char c = getchar();			/// Permet de quitter le programme 
    system("stty cbreak -echo");
    getchar();
    system("stty cooked echo");
    system("clear");

    return 0;
}
