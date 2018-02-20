 /* EL KANDOUSSI ADNAN */
/* Fonctions de choix du joueur par tour */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Fonction de sélection d'unité par tour */

void ChoixUnite(int tour){
	int u; /* numéro de l'unité */
	if(tour == 1){ /* Si tour = 1 , le joueur 1 joue, sinon, le joueur 2 joue*/
		printf("C'est au tour du joueur 1\n");
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
		printf("C'est au tour du joueur 2\n");
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
}

void DebutPartie(int tour){
	
	int de1,de2; /* dé des deux joueurs */
	srand(time(NULL));
	printf("Début de la partie !\n");
	printf("Chaque joueur lance un dé de l'infini.\n");
	printf("Celui qui possède le plus grand nombre commence.\n");
	printf("Lancez les dés !\n");
	de1 = rand()%10;
	de2 = rand()%10;
	printf("Joueur 1 a obtenu un %i\n",de1);
	printf("Joueur 2 a obtenu un %i\n",de2);
	while(de1 == de2)
	{
		printf("Egalité !\n");
		printf("On recommence.\n");
		printf("Lancez les dés !\n");
		de1 = rand()%10;
		de2 = rand()%10;
		printf("Joueur 1 a obtenu un %i\n",de1);
		printf("Joueur 2 a obtenu un %i\n",de2);
			
	}
	if(de1 > de2)		/* Tour du joueur 1 */
	{
		printf("Joueur 1 commence !\n");
		tour = 1;
		ChoixUnite(tour);
	}
	else if(de1 < de2)	/* Tour du joueur 2 */
	{
		printf("Joueur 2 commence !\n");
		tour = 0;
		ChoixUnite(tour);
	}
	
	
}