#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"matrice_terminal.h"

#define N 11

#define MAX 10
#define MIN 0

#define MAX_pion 10
#define MIN_pion 0

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
	int i, j, nb_ligne=0, nb_colonne=0, nb_pierre=0, qts_eau=0;
	
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
sbires placer_pions(char matrice_affichage[N][N], int matrice_indice[N][N], sbires sbire_bleu, sbires sbire_rouge){

	const int a = 0, i = 10;
	int b = 0, j = 0;
	
	b = (rand() % (MAX_pion - MIN_pion + 1)) + MIN;
			
	matrice_affichage[a][b] = sbire_bleu.symbole;
	matrice_indice[a][b] = 1;
	sbire_bleu.position[0] = a;
	sbire_bleu.position[1] = b;

	j = (rand() % (MAX_pion - MIN_pion + 1)) + MIN;

	matrice_affichage[i][j] = sbire_rouge.symbole;
	matrice_indice[i][j] = 1;
	sbire_rouge.position[0] = i;
	sbire_rouge.position[1] = j;
	
	return(sbire_rouge);
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
