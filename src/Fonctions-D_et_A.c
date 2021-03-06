#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "../include/Deplacements_et_Actions.h"
#include "../include/matrice_terminal.h"

#define N 11

/**
*\file Fonctions-D_et_A.c
*\author Jolliet Corentin
*\date 6 avril 2018
*\version 1.0
*\brief Menu pour choisir l'action du pion.
*
*\details Affichage d'un menu pour permettre au joueur de choisir l'action que devra effectuer le pion.
*
*/

/**
*\brief Choisis l'action du pion.
*\details Permet de choisir entre le déplacement, l'attaque, les stratégies du pion et annuler l'action.
*\param sbires_t sbire La structure du pion courant.
*\param armee_t armee_j1 Contient les pions du joueur 1.
*\param armee_t armee_j2 Contient les pions du joueur 2.
*\param sbires_t cible La structure de la cible.
*\param int mat[N][N] La matrice d'affichage.
*/
int menu(sbires_t sbire, armee_t armee_j1, armee_t armee_j2, sbires_t cible, int mat[N][N]){

	int deplace = 0;
	int choix = 0;
	int ennemi;

	while((choix != 3) && (choix != 4)){

		printf("\nQue doit faire %s ?\n", sbire.nom);
		printf("1 : Se déplacer\n");
		printf("2 : Stratégie de l'unité\n");
		printf("3 : Attaquer une unité\n");
		printf("4 : Choisir une autre unité\n");
	
		scanf("%i", &choix);
	
		switch (choix) {

			case 1 : if(deplace != 1){
					sbire = Selection_Deplacement(sbire, mat);
					afficher_matrice(mat, armee_j1, armee_j2);
					deplace = 1;
				} else {
					printf("%s s'est déjà déplacé ce tour-ci\n", sbire.nom);
				}
				break;

			case 2 : sbire = Action(sbire, mat);
				break;

			case 3 : ennemi = Detection_Portee(sbire, 1, mat, 0);
				if ( ennemi > 0 ) {
					sbire = Selection_Attaque(sbire, cible);
				} else {
					if(deplace != 1){
						printf("Pas d'ennemi à portée de %s\nEssayez de vous déplacer !\n", sbire.nom);
					} else {
						printf("Pas d'ennemi à portée de %s\nEt vous vous êtes déjà déplacé ce tour-ci\n", sbire.nom);
					}
					choix = 0;
				}
				break;

			case 4 : printf("Action annulée\n");
				menu(sbire, armee_j1, armee_j2, cible, mat);
				break;

			default : printf("Won't work\n");

		}
	}
}
