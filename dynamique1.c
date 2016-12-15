#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include "pbmtab.h"
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define TAILLE_MAX 80

// permettra de récupérer les données de l'heure afin de l'afficher plus tard

int InitTime()
{
	time_t secondes;
	struct tm instant;
	time(&secondes);
	instant=*localtime(&secondes);
	int TimeS1 = (instant.tm_sec)/10;
	int TimeS2 = (instant.tm_sec)-(TimeS1*10);
	int TimeM1 = (instant.tm_min)/10;
	int TimeM2 = (instant.tm_min)-(TimeM1*10);
	int TimeH1 = (instant.tm_hour)/10;
	int TimeH2 = (instant.tm_hour)-(TimeH1*10);

	int Time[8];
	Time[0] = TimeH1;
	Time[1] = TimeH2;
	Time[2] = 15;
	Time[3] = TimeM1;
	Time[4] = TimeM2;
	Time[5] = 15;
	Time[6] = TimeS1;
	Time[7] = TimeS2;

	int z = 0;
	int TailleFich = 1;

	//

	//system("clear"); // fonction qui nettoie la console.

		int y=40-((4+TailleFich*2)*3+5), x=6;
	    	int i = 0, j = 0; // declaration des variables
	    	FILE* fichier = NULL; //permet l'initiallisation du pointeur
	    	char chaine[TAILLE_MAX];
	    	int chaine2[2];
	    	//permet l'ouverture de l'image
	     	int a,b;

	for (z=0; z<8; z++)
	{
		switch(Time[z])  //permet d'ouvrir les fichiers pbm contenant les chiffres préfaits
		{
			case 0:
				fichier = fopen("EXIASAVER2_PBM/zero.pbm", "r");
				break;
			case 1:
				fichier = fopen("EXIASAVER2_PBM/un.pbm", "r");
				break;
			case 2:
				fichier = fopen("EXIASAVER2_PBM/deux.pbm", "r");
				break;
			case 3:
				fichier = fopen("EXIASAVER2_PBM/trois.pbm", "r");
				break;
			case 4:
				fichier = fopen("EXIASAVER2_PBM/quatre.pbm", "r");
				break;
			case 5:
				fichier = fopen("EXIASAVER2h_PBM/cinq.pbm", "r");
				break;
			case 6:
				fichier = fopen("EXIASAVER2_PBM/six.pbm", "r");
				break;
			case 7:
				fichier = fopen("EXIASAVER2_PBM/sept.pbm", "r");
				break;
			case 8:
				fichier = fopen("EXIASAVER2_PBM/huit.pbm", "r");
				break;
			case 9:
				fichier = fopen("EXIASAVER2_PBM/neuf.pbm", "r");
				break;
			case 15:
				fichier = fopen("EXIASAVER2_PBM/doublepoint.pbm", "r");
				break;
		}

	    	if (fichier != NULL) // vérification de l'ouverture du fichier
	    	{
			fseek(fichier, 3, SEEK_SET);
			fscanf(fichier, "%d %d", &chaine2[0], &chaine2[1]);
			a = chaine2[0];
			b = chaine2[1];
			a = (a*2)-1;

			fseek(fichier, 1, SEEK_CUR);
			for(i=0; i<b; i++) // boucle qui va parcourir les lignes
			{
				gotoxy(x,y);
		    		fgets(chaine, TAILLE_MAX, fichier); // recuperation de la ligne
		    		for(j=0;j<a;j++) // boucle qui parcourt la ligne
		    		{
					gotoxy(x,y);
		        		if (chaine[j] == '0')
		            			chaine[j] = ' '; // changement des 0 en espace
		        		else if (chaine[j] == '1')
		            			chaine[j] = 'X'; // changement des 1 en X

					//x=x+1;
		   		}
				x=x+1;
		    		printf("%s", chaine); // la ligne modifié sera affiché

			}
			fclose(fichier); // fonction close pour fermer le fichier
			fichier = NULL;
	    	}
		x=x-5;
		y = y+7; //commence à 5+2 pour que le second chiffre soit espacé de 2 au premier

	}
}

int main()
{

	int RefreshT = 5;
	int ctrlc = 0; //arrête l'éxecution du screensaver
	int i;
	int a = 20,b = 15,c = 3,d = 25; //permet de centrer l'heure affichée
	system("clear");

	while (ctrlc != 1)
	{
		int x = 20;
		int y = 62;
		gotoxy(c,d);
		InitTime();
		gotoxy(a,b);
		if (RefreshT == 1)
		{
			gotoxy(a,b+10);
			printf("Cet écran est actualisé toutes les secondes \n"); //aff
		}
		else

			printf("Cet écran sera actualisé dans quelques secondes \n");

		for (i=0; i<RefreshT; i++)
		{
			sleep(1);
			gotoxy(x,y);
			printf(".\n");
			y++;
		}
		y=y-RefreshT;
		gotoxy(x,y);
		printf("                            ");

	}

	return 0;
}



char pbmtab(FILE* fichier)
{
  char curseur;


fseek(fichier, 9, SEEK_SET); // On place le curseur au 3eme curseur, au niveau des dimensions

/* DEBUT - Enlève les espaces, remplace les 0 par des espaces, et remplace les 1 par un caractère choisi, caractère par caractère */
  do
  {

curseur = fgetc(fichier); // Curseur accède à la x ème ligne

    if (curseur == ' ')
    {
      curseur = '\0'; // Remplace les espaces par u vide ( \0 = vide )
    }
    else if (curseur == '0')
    {
      curseur = ' '; // Remplace les 0 par un espace
    }
    else if(curseur == '1')
    {
      curseur = '*'; // Remplace les 1 par un caractère choisi
    }

    if (curseur == EOF)
    {
      return 0; // Si nous sommes à la fin du fichier (si le caractère à droite du curseur est égal au caractère de fin), alors on arrête le while avec un return 0;
    }
    else
    {
      printf("%c", curseur); // printf le caractère choisi
    }
  } while ((curseur) != EOF); // EOF: caractère de fin du fichier

/* FIN - Enlève les espaces, remplace les 0 par des espaces, et remplace les 1 par un caractère choisi, caractère par caractère */

  return 0;





}


