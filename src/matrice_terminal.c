#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include"../include/couleur.h"
#include"../include/structures.h"

#define N 11

/**
*\file matrice_terminal.c
*\author Nore Vincent
*\date 6 avril 2018
*\version 1.0
*\brief Initialisation et affichage de la matrice.
*
*\details Initialisation de la matrice, création des armées des joueurs et affichage de la matrice.
*
*/

/**
*\brief Initialisation de la matrice.
*\details Initialisation de la matrice à vide.
*\param int mat[N][N] La matrice d'affichage.
*/
void init_matrice(int mat[N][N]){
	int i, j;
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			mat[i][j] = 0;	
		}
	}	
}

/**
*\brief Afficher la matrice.
*\details Afficher la matrice avec ses limites et les pions des joueurs.
*\param int mat[N][N] La matrice d'affichage.
*\param armee_t armee_j1 Contient les pions du joueur 1.
*\param armee_t armee_j2 Contient les pions du joueur 2.
*/
int afficher_matrice(int mat[N][N], armee_t armee_j1, armee_t armee_j2){

	clrscr();
	int i, j;
	for(i = 0; i < N; i++){
		
		printf("\n");
		for(j = 0; j < N; j++){ 
			printf("| ");
			
			if((i == armee_j1.A.position[0]) && (j == armee_j1.A.position[1]) && armee_j1.A.vie > 0){
				couleur("31");
				printf("%s ", armee_j1.A.symbole);
				couleur("0");
			} 
			else if((i == armee_j1.B.position[0]) && (j == armee_j1.B.position[1]) && armee_j1.B.vie > 0){
				couleur("31");
				printf("%s ", armee_j1.B.symbole);
				couleur("0");
			}
			else if((i == armee_j1.C.position[0]) && (j == armee_j1.C.position[1]) && armee_j1.C.vie > 0){
				couleur("31 ");
				printf("%s", armee_j1.C.symbole);
				couleur("0");
			}
			else if((i == armee_j1.D.position[0]) && (j == armee_j1.D.position[1]) && armee_j1.D.vie > 0){
				couleur("31 ");
				printf("%s", armee_j1.D.symbole);
				couleur("0");
			}
			else if((i == armee_j1.E.position[0]) && (j == armee_j1.E.position[1]) && armee_j1.E.vie > 0){
				couleur("31 ");
				printf("%s", armee_j1.E.symbole);
				couleur("0");
			}
			else {
				printf("  ");
				mat[i][j] = 0;
			}
			
			 if((i == armee_j2.A.position[0]) && (j == armee_j2.A.position[1]) && armee_j2.A.vie > 0){
			 	couleur("32 ");
				printf("%s", armee_j2.A.symbole);
				couleur("0");
			}
			else if((i == armee_j2.B.position[0]) && (j == armee_j2.B.position[1]) && armee_j2.B.vie > 0){
				couleur("32 ");
				printf("%s", armee_j2.B.symbole);
				couleur("0");
			}
			else if((i == armee_j2.C.position[0]) && (j == armee_j2.C.position[1]) && armee_j2.C.vie > 0){
				couleur("32 ");
				printf("%s", armee_j2.C.symbole);
				couleur("0");
			}
			else if((i == armee_j2.D.position[0]) && (j == armee_j2.D.position[1]) && armee_j2.D.vie > 0){
				couleur("32 ");
				printf("%s", armee_j2.D.symbole);
				couleur("0");
			}
			else if((i == armee_j2.E.position[0]) && (j == armee_j2.E.position[1]) && armee_j2.E.vie > 0){
				couleur("32 ");
				printf("%s", armee_j2.E.symbole);
				couleur("0");
			}
			else {
				printf(" ");
				mat[i][j] = 0;
			}
		}
		printf(" |");
	}
	printf("\n\n");
}

/**
*\brief Choisir où placer les pions.
*\details Permet de choisir où placer les pions sur la matrice.
*\param sbires_t sbire La structure du pion courant.
*\param int mat[N][N] La matrice d'affichage.
*/
sbires_t positionner_sbire(sbires_t sbire, int mat[N][N]){
	/*Fonction de verification de position d'unite*/
	int n;
	for (n = 0; n < 2; n++){
		if (n == 0){
			printf("Ligne : ");
		}
		else {
			printf("Colonne : ");
		}

		scanf("%i", &sbire.position[n]);
		sbire.position[n] = sbire.position[n] - 1;
		while ((sbire.position[n] < 0) || (sbire.position[n] >= N)){

			printf("\nLigne/Colonne visée n'existe pas, veuillez choisir un numéro de Ligne/Colonne entre 1 et 11 : ");
			scanf("%i", &sbire.position[n]);
			sbire.position[n] = sbire.position[n] - 1;
		}
	}

	if (mat[sbire.position[0]][sbire.position[1]] == 0){
		mat[sbire.position[0]][sbire.position[1]] = 1;
		return(sbire);

	}
	else if (mat[sbire.position[0]][sbire.position[1]] != 0) {

		printf("La case %i - %i est déjà occupée\n", (sbire.position[0] + 1), (sbire.position[1] + 1));
		sbire = positionner_sbire(sbire, mat);
		return sbire;
	}
}

/**
*\brief Créer les pions des joueurs.
*\details Fonction de création des pions des joueurs avec pour choix le nom du pion ainsi que sont symbole qui permettra de l'identifier sur la matrice.
*\param sbires_t sbire La structure du pion courant.
*\param int mat[N][N] La matrice d'affichage.
*/
sbires_t init_sbire(sbires_t sbire, int mat[N][N]){
	/*Fonction d'initialisation d'unites*/
	sbire.nom = malloc(sizeof(char)* 128);
	sbire.symbole = malloc(sizeof(char)* 128);
	printf("\nNom de l'unité : ");
	scanf("%s", sbire.nom);

	printf("\nSymbole de l'unité : ");
	scanf("%s", sbire.symbole);

	sbire.attaque = 30;
	sbire.defense = 20;
	sbire.vie = 50;
	sbire.mana = 20;
	sbire.esquive = 30;
	sbire.nbr_depl = 5;
	printf("Position de départ : \n");

	sbire = positionner_sbire(sbire, mat);
	mat[sbire.position[0]][sbire.position[1]] = 1;

	printf("\nSbire %s créé : \n", sbire.nom);
	printf("Attaque : %i \nDefense : %i \nMana : %i \nVie : %i \nTaux d'esquive : %i pourcents\nNombre de pas possibles : %i \n", sbire.attaque, sbire.defense, sbire.mana, sbire.vie, sbire.esquive, sbire.nbr_depl);
	return(sbire);
}

/**
*\brief Créer de l'armée du joueur 1.
*\details Fonction de création de l'armée du joueur 1 qui contient ses pions.
*\param armee_t armee_j1 Contient les pions du joueur 1.
*\param armee_t armee_j2 Contient les pions du joueur 2.
*\param sbires_t sbire La structure du pion courant.
*\param int mat[N][N] La matrice d'affichage.
*/
armee_t init_armee_j1(armee_t armee_j1, sbires_t sbire, int mat[N][N]){
	
	clrscr();
	
	printf("--- Joueur 1 - unité 1 ---\n");
	armee_j1.A = init_sbire(sbire, mat);
	printf("--- Joueur 1 - unité 2 ---\n");
	armee_j1.B = init_sbire(sbire, mat);
	printf("--- Joueur 1 - unité 3 ---\n");
	armee_j1.C = init_sbire(sbire, mat);
	printf("--- Joueur 1 - unité 4 ---\n");
	armee_j1.D = init_sbire(sbire, mat);
	printf("--- Joueur 1 - unité 5 ---\n");
	armee_j1.E = init_sbire(sbire, mat);
	
	return(armee_j1);
}

/**
*\brief Créer de l'armée du joueur 2.
*\details Fonction de création de l'armée du joueur 2 qui contient ses pions.
*\param armee_t armee_j1 Contient les pions du joueur 1.
*\param armee_t armee_j2 Contient les pions du joueur 2.
*\param sbires_t sbire La structure du pion courant.
*\param int mat[N][N] La matrice d'affichage.
*/
armee_t init_armee_j2(armee_t armee_j2, sbires_t sbire, int mat[N][N]){
	
	clrscr();
	
	printf("--- Joueur 2 - unité 1 ---\n");
	armee_j2.A = init_sbire(sbire, mat);
	printf("--- Joueur 2 - unité 2 ---\n");
	armee_j2.B = init_sbire(sbire, mat);
	printf("--- Joueur 2 - unité 3 ---\n");
	armee_j2.C = init_sbire(sbire, mat);
	printf("--- Joueur 2 - unité 4 ---\n");
	armee_j2.D = init_sbire(sbire, mat);
	printf("--- Joueur 2 - unité 5 ---\n");
	armee_j2.E = init_sbire(sbire, mat);
	
	return(armee_j2);
}

