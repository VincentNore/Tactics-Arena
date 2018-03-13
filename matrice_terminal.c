#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"matrice_terminal.h"

#define N 11

#define MAX 11
#define MIN 0

#define MAX_pierre 3
#define MIN_pierre 0

#define MAX_eau 3
#define MIN_eau 0


/*Fonction pour initialiser la matrice à vide*/
void init_matrice(char matrice_affichage[N][N], int matrice_indice[N][N]){
	char libre = '.';
	int i, j;
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			matrice_affichage[i][j] = libre;
			matrice_indice[i][j] = 0;	
		}
	}	
}


/*Fonction pour placer les décors*/
void placer_decors(char matrice_affichage[N][N], int matrice_indice[N][N], decors_t decors){
	int i, j, nb_ligne, nb_colonne ,nb_pierre, qts_eau;
	
	srand(time(NULL));
	nb_pierre = (rand() % (MAX_pierre - MIN_pierre + 1)) + MIN; /*Génération d'un nombre aléatoire pour les pierres*/
	
	for(i=0; i<nb_pierre; i++){
		nb_colonne = (rand() % (MAX - MIN + 1)) + MIN; /*Génération d'un nombre aléatoire pour les colonne*/
		nb_ligne = (rand() % (MAX - MIN + 1)) + MIN; /*Génération d'un nombre aléatoire pour les lignes*/
		matrice_affichage[nb_ligne][nb_colonne] = decors.pierre;
		matrice_indice[nb_ligne][nb_colonne] = 2;
	}
	
	qts_eau = (rand() % (MAX_eau - MIN_eau + 1)) + MIN; /*Génération d'un nombre aléatoire pour l'eau*/
	
	for(j=0; j<qts_eau; j++){
		nb_colonne = (rand() % (MAX - MIN + 1)) + MIN;
		nb_ligne = (rand() % (MAX - MIN + 1)) + MIN;
		matrice_affichage[nb_ligne][nb_colonne] = decors.eau;
		matrice_indice[nb_ligne][nb_colonne] = 3;
		
		matrice_affichage[nb_ligne+1][nb_colonne] = decors.eau;
		matrice_indice[nb_ligne+1][nb_colonne] = 3;
		
		matrice_affichage[nb_ligne][nb_colonne+1] = decors.eau;
		matrice_indice[nb_ligne][nb_colonne+1] = 3;
		
		matrice_affichage[nb_ligne+1][nb_colonne+1] = decors.eau;
		matrice_indice[nb_ligne+1][nb_colonne+1] = 3;
		
		matrice_affichage[nb_ligne-1][nb_colonne] = decors.eau;
		matrice_indice[nb_ligne-1][nb_colonne] = 3;
		
		matrice_affichage[nb_ligne][nb_colonne-1] = decors.eau;
		matrice_indice[nb_ligne][nb_colonne-1] = 3;
		
		matrice_affichage[nb_ligne-1][nb_colonne-1] = decors.eau;
		matrice_indice[nb_ligne-1][nb_colonne-1] = 3;
		     
		matrice_affichage[nb_ligne+1][nb_colonne-1] = decors.eau;
		matrice_indice[nb_ligne+1][nb_colonne-1] = 3;
		
		matrice_affichage[nb_ligne-1][nb_colonne+1] = decors.eau;
		matrice_indice[nb_ligne-1][nb_colonne+1] = 3;
		
	}
}

/*Fonction pour placer les pions des deux joueurs*/
void placer_pions(char matrice_affichage[N][N], int matrice_indice[N][N], sbires sbire_bleu, sbires sbire_rouge){

	int i, j;
	for(i=0; i<1; i++){
		for(j=0; j<2; j++){
			matrice_affichage[i][j] = sbire_bleu.symbole;
			matrice_indice[i][j] = 1;
			sbire_bleu.position[0] = i;
			sbire_bleu.position[1] = j;
			printf("\n%i\n", sbire_bleu.position[0]);
			printf("%i\n\n", sbire_bleu.position[1]);
		}
	}
	
	for(i=0; i<N; i++){
		for(j=0; j<2; j++){
			if(i == 10){
				matrice_affichage[i][j] = sbire_rouge.symbole;
				matrice_indice[i][j] = 1;
				sbire_rouge.position[0] = i;
				sbire_rouge.position[1] = j;
				printf("\n%i\n", sbire_rouge.position[0]);
				printf("%i\n\n", sbire_rouge.position[1]);
			}
		}
	}	
}

/*Fonction afficher la matrice*/
void afficher_matrice(char matrice_affichage[N][N]){
	int i, j;
	for (i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%c", matrice_affichage[i][j]);
		}
		printf("\n");
	}
}

/*Fonction afficher la matrice*/
void afficher_matrice_indice(int matrice_indice[N][N]){
	int i, j;
	for (i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%i", matrice_indice[i][j]);
		}
		printf("\n");
	}
}
