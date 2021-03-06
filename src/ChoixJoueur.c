#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/structures.h"

/**
*\file ChoixJoueur.c
*\author El Kandoussi Adnan
*\date 6 avril 2018
*\version 1.0
*\brief Définie le choix du joueur qui débute et le choix du pion qui joue.
*
*\details Permet de choisir le joueur qui débute la partie en premier et de permettre au joueur de choisir le pion qui va effectuer une action.
*
*/

/**
*\brief Choisis le pion qui effectue une action.
*\details Permet de choisir laisser le choix au joueur de choisir le pion dans sa liste pour effectuer une action.
*\param int tour Connaitre le joueur qui commence à jouer en premier.
*\param armee_t armee_j1 Contient les pions du joueur 1.
*\param armee_t armee_j2 Contient les pions du joueur 2.
*/
sbires_t ChoixUnite(int tour, armee_t armee_j1, armee_t armee_j2){
	int num; /* numéro de l'unité */
	
	/*Affichage des pions du joueur 1.*/
	if(tour == 1){ /* Si tour = 1 , le joueur 1 joue, sinon, le joueur 2 joue*/
		printf("C'est au tour du joueur 1\n\n");
		printf("Selectionnez une unité :\n");
		printf("1 - %s\n",armee_j1.A.nom);
		printf("2 - %s\n",armee_j1.B.nom);
		printf("3 - %s\n",armee_j1.C.nom);
		printf("4 - %s\n",armee_j1.D.nom);
		printf("5 - %s\n",armee_j1.E.nom);
		
		scanf("%d",&num);
		
		printf("\n");
		
		switch(num){
		case 1:	
			printf("Vous avez selectionné l'unité %s.\n\n", armee_j1.A.nom); 
			return(armee_j1.A);
			break;
		case 2: 
			printf("Vous avez selectionné l'unité %s.\n\n", armee_j1.B.nom); 
			return(armee_j1.B);
			break;
		case 3: 
			printf("Vous avez selectionné l'unité %s.\n\n", armee_j1.C.nom); 
			return(armee_j1.C);
			break;
		case 4: 
			printf("Vous avez selectionné l'unité %s.\n\n", armee_j1.D.nom); 
			return(armee_j1.D);
			break;
		case 5: 
			printf("Vous avez selectionné l'unité %s.\n\n", armee_j1.E.nom); 
			return(armee_j1.E);
			break;
		}
	}
	
	else if(tour == 0){
		/*Affichage des pions du joueur 2.*/
		printf("C'est au tour du joueur 2\n");
		printf("Selectionnez une unité :\n");
		printf("1 - %s\n",armee_j2.A.nom);
		printf("2 - %s\n",armee_j2.B.nom);
		printf("3 - %s\n",armee_j2.C.nom);
		printf("4 - %s\n",armee_j2.D.nom);
		printf("5 - %s\n",armee_j2.E.nom);
		
		scanf("%d",&num);
		switch(num)
		{
		case 1:	
			printf("Vous avez selectionné l'unité %s.\n\n", armee_j2.A.nom); 
			return(armee_j2.A);
			break;
		case 2: 
			printf("Vous avez selectionné l'unité %s.\n\n", armee_j2.B.nom); 
			return(armee_j2.B);
			break;
		case 3: 
			printf("Vous avez selectionné l'unité %s.\n\n", armee_j2.C.nom); 
			return(armee_j2.C);
			break;
		case 4: 
			printf("Vous avez selectionné l'unité %s.\n\n", armee_j2.D.nom); 
			return(armee_j2.D);
			break;
		case 5: 
			printf("Vous avez selectionné l'unité %s.\n\n", armee_j2.E.nom); 
			return(armee_j2.E);
			break;
		}
	}
}

/**
*\brief Choisis le joueur qui joue en premier.
*\details Choisir aléatoirement le joueur qui débutera la partie en premier.
*\param int tour Connaitre le joueur qui commence à jouer en premier.
*/

int DebutPartie(int tour){
	
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

	/*Vérification de l'égalité des deux joueurs*/
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
	}
	else if(de1 < de2)	/* Tour du joueur 2 */
	{
		printf("Joueur 2 commence !\n");
		tour = 0;
	}
	return (tour);
}
