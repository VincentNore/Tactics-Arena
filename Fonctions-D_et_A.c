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

				printf("D ");

			} else if( (i == dummy.position[0]) && (j == dummy.position[1]) ){

				printf("X ");

			} else {

				printf("  ");
				mat[i][j] = 0;

			}

		}

		printf("|");

	}

	printf("\n\nD for Dino !");

}

t_sbires positionner_sbire(t_sbires sbire, int mat[N][N]){
/*Fonction de positionnement d'unité - Version Test*/
	for(int n = 0; n < 2; n++){
		if(n == 0){
			printf("Ligne : ");
		} else {
			printf("Colonne : ");
		}
		
		scanf("%i", &sbire.position[n]);
		sbire.position[n] = sbire.position[n] - 1;
		while((sbire.position[n] < 0) || (sbire.position[n] >= N)){

			printf("\nLigne/Colonne visée n'existe pas, veuillez choisir un numéro de Ligne/Colonne entre 1 et 11 : ");
			scanf("%i", &sbire.position[n]);
			sbire.position[n] = sbire.position[n] - 1;

		}
	}

	if(mat[sbire.position[0]][sbire.position[1]] == 0){
			mat[sbire.position[0]][sbire.position[1]] = 1;
			return sbire;

	} else if(mat[sbire.position[0]][sbire.position[1]] != 0) {

		printf("La case %i - %i est déjà occupée\n", (sbire.position[0] + 1), (sbire.position[1] + 1));
		sbire = positionner_sbire(sbire, mat);
		return sbire;
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
		/*sbire.position[0] = 5;
		sbire.position[1] = 6;
		mat[sbire.position[0]][sbire.position[1]] = 1;*/
		sbire = positionner_sbire(sbire, mat);
		printf("\nThat's one good sturdy dummy !\n");

	} else {

		sbire.attaque = 30;
		sbire.defense = 20;
		sbire.vie = 50;
		sbire.mana = 20;
		sbire.esquive = 30;
		sbire.nbr_depl = 5;
		printf("Position de départ : \n");

		sbire = positionner_sbire(sbire, mat);

	}

	printf("\nSbire %s créé : \n", sbire.nom);
	printf("Attaque : %i \nDefense : %i \nMana : %i \nVie : %i \nTaux d'esquive : %i pourcents\nNombre de pas possibles : %i \n", sbire.attaque, sbire.defense, sbire.mana, sbire.vie, sbire.esquive, sbire.nbr_depl);
	return sbire;

}

t_sbires init_dino(t_sbires sbire, int mat[N][N]){
	int poser = 0;
	sbire.nom = malloc(sizeof(char)*128);
	sbire.nom = "Dino";
	sbire.attaque = 60;
	sbire.defense = 40;
	sbire.vie = 70;
	sbire.mana = 30;
	sbire.esquive = 50;
	sbire.nbr_depl = 10;
	printf("Position de départ : \n");

	sbire = positionner_sbire(sbire, mat);

	printf("\nSbire %s créé : \n", sbire.nom);
	printf("Attaque : %i \nDefense : %i \nMana : %i \nVie : %i \nTaux d'esquive : %i pourcents\nNombre de pas possibles : %i \n", sbire.attaque, sbire.defense, sbire.mana, sbire.vie, sbire.esquive, sbire.nbr_depl);
	return sbire;
}

int main (void) {

	int mat[N][N], deplace;

	init_mat(mat);

	t_sbires sbire;

	sbire = init_dino(sbire, mat);

	t_sbires dummy;

	dummy = init_armee(dummy, mat);

	aff_mat(mat, sbire, dummy);

	int choix = 0;
	int ennemi;

	while( (choix != 3) && (choix != 4) ) {

		printf("\nQue doit faire %s ?\n", sbire.nom);
		printf("1 : Se déplacer\n");
		printf("2 : Stratégie de l'unité\n");
		printf("3 : Attaquer une unité\n");
		printf("4 : Choisir une autre unité\n");
	
		scanf("%i", &choix);
	
		switch (choix) {

			case 1 : if(deplace != 1){
					sbire = Selection_Deplacement(sbire, mat);
					aff_mat(mat, sbire, dummy);
					deplace = 1;
				} else {
					printf("%s s'est déjà déplacé ce tour-ci\n", sbire.nom);
				}
				break;

			case 2 : sbire = Action(sbire, mat);
				break;

			case 3 : ennemi = Detection_Portee(sbire, 1, mat, 0);
				if ( ennemi > 0 ) {
					dummy = Selection_Attaque(sbire, dummy);
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
				break;

			default : printf("Won't work\n");

		}

	}
}
