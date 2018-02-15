 /* EL KANDOUSSI ADNAN */
/* Fonctions de choix du joueur par tour */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Fonction de sélection d'unité par tour */

void ChoixDeplacement(int tour){
	int u; /* numéro de l'unité */
	if(tour == 1){ /* Si tour = 1 , le joueur joue, sinon, l'IA joue*/
		printf("C'est au tour du joueur\n");
		printf("Selectionnez une unité (1,2,3 ou 4) :\n");
		scanf("%d",&u);
		switch(u)
		{
		case 1: printf("Vous avez selectionné l'unité 1.\n"); break;
		case 2: printf("Vous avez selectionné l'unité 2.\n"); break;
		case 3: printf("Vous avez selectionné l'unité 3.\n"); break;
		case 4: printf("Vous avez selectionné l'unité 4.\n"); break;
		}	
			

	}
	else if(tour == 0)
	{
		printf("C'est au tour de l'IA\n");

	}
}

int main(void){
	int tour;
	int de1,de2; /* dé des deux joueurs */
	srand(time(NULL));
	printf("Début de la partie !\n");
	printf("Chaque joueur lance un dé de l'infini.\n");
	printf("Celui qui possède le plus grand nombre commence.\n");
	printf("Lancez les dés !\n");
	de1 = rand()%10;
	de2 = rand()%10;
	printf("Le joueur a obtenu un %i\n",de1);
	printf("L'IA a obtenu un %i\n",de2);
	if(de1 > de2)		/* Tour du joueur */
	{
		printf("Le joueur commence !\n");
		tour = 1;
		ChoixDeplacement(tour);
	}
	else if(de1 < de2)	/* Tour de l'IA */
	{
		printf("L'IA commence !\n");
		tour = 0;
		ChoixDeplacement(tour);
	}
	else		/* Egalité aux dés */
	{
		while(de1 == de2)
		{
			printf("Egalité !\n");
			printf("On recommence.\n");
			de1 = rand();
			de2 = rand();
		}
		
	}
	return 0;




}