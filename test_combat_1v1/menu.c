#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "Deplacements_et_Actions.h"


void init_mat(int mat[N][N]){
/*Fonction d'initialisation de matrice - Version Test*/
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			mat[i][j] = 0;
		}
	}
}

int aff_mat(int mat[N][N], t_sbires sbire, t_sbires dummy){
	for(int i = 0; i < N; i++){
		printf("\n");
		for(int j = 0; j < N; j++){
			printf("| ");
			if( (i == sbire.position[0]) && (j == sbire.position[1]) ){
				printf("X ");
				mat[i][j] = 1;
			} else if( (i == dummy.position[0]) && (j == dummy.position[1]) ){
				printf("D ");
				mat[i][j] = 2;
			} else {
				printf("  ");
				mat[i][j] = 0;
			}
		}
		printf("|");
	}
	printf("\n\n");
}

int positionner_sbire(t_sbires sbire, int mat[N][N]){
/*Fonction de positionnement d'unité - Version Test*/
	if(mat[sbire.position[0]][sbire.position[1]] == 0){
		return 1;
	} else {
		printf("La case %i - %i est déjà occupée\n", sbire.position[0], sbire.position[1]);
		return 0;
	}
}

t_sbires init_armee(t_sbires sbire, int mat[N][N]){
/*Fonction d'initialisation d'unités - Version Test*/
	int poser = 0;
	sbire.nom = malloc(sizeof(char)*128);
	printf("\nNom de l'unité : ");
	scanf("%s", sbire.nom);
	if( (strcmp(sbire.nom, "dummy") == 0) || (strcmp(sbire.nom, "Dummy") == 0) ){
		sbire.attaque = 0;
		sbire.defense = 10;
		sbire.vie = 50;
		sbire.mana = 0;
		sbire.esquive = 10;
		sbire.nbr_depl = 0;
		sbire.position[0] = 5;
		sbire.position[1] = 6;
		poser = positionner_sbire(sbire, mat);
		printf("\nThat's one good sturdy dummy !\n");
	} else {
		sbire.attaque = 30;
		sbire.defense = 20;
		sbire.vie = 50;
		sbire.mana = 20;
		sbire.esquive = 30;
		sbire.nbr_depl = 5;
		printf("Position de départ : \n");
		while(poser == 0){
			for(int n = 0; n < 2; n++){
				if(n == 0){
					printf("Ligne : ");
				} else {
					printf("Colonne : ");
				}
				scanf("%i", &sbire.position[n]);
			}
			poser = positionner_sbire(sbire, mat);
		}
	}
	printf("\nSbire %s créé : \n", sbire.nom);
	printf("Attaque : %i \nDefense : %i \nMana : %i \nVie : %i \nTaux d'esquive : %i pourcents\nNombre de pas possibles : %i \n", sbire.attaque, sbire.defense, sbire.mana, sbire.vie, sbire.esquive, sbire.nbr_depl);
	return sbire;
}



int menu (void) {
	int mat[N][N];
	init_mat(mat);
	t_sbires sbire;
	sbire = init_armee(sbire, mat);
	t_sbires dummy;
	dummy = init_armee(dummy, mat);
	aff_mat(mat, sbire, dummy);
	int choix = 0;

	printf("\nQue doit faire %s ?\n", sbire.nom);
		printf("1 : Se déplacer\n");
		printf("2 : Stratégie de l'unité\n");
		printf("3 : Attaquer une unité\n");
		printf("4 : Annuler\n"); /*A défaut d'avoir une autre façon de tester le programme*/
	
		scanf("%i", &choix);
	
	switch (choix) {
		case 1 : printf("En travaux\n");
			sbire = Selection_Deplacement(sbire, mat);
			aff_mat(mat, sbire, dummy);
			break;
		case 2 : sbire = Action(sbire, mat);
			break;
		case 3 : dummy = Selection_Attaque(sbire, dummy);
			break;
		case 4 : printf("Action annulée\n");
			break;
		default : printf("Won't work\n");
			break;
	}
	
}
