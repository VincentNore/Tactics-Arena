#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 11

#define MAX 11
#define MIN 0

#define MAX_pierre 3
#define MIN_pierre 0

#define MAX_eau 3
#define MIN_eau 0

char matrice[N][N];
char joueur1 = 'o';
char joueur2 = 'x';
char libre = '.';
char eau = 'e';
char pierre = 'p';

/*Fonction pour initialiser la matrice à vide*/
void init_matrice(){
	int i, j;
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			matrice[i][j] = libre;
			
		}
	}	
}


/*Fonction pour placer les décors*/
void placer_decors(){
	int i, j, nb_ligne, nb_colonne ,nb_pierre, qts_eau;
	srand(time(NULL));
	nb_pierre = (rand() % (MAX_pierre - MIN_pierre + 1)) + MIN; /*Génération d'un nombre aléatoire pour les pierres*/
	for(i=0; i<nb_pierre; i++){
		nb_colonne = (rand() % (MAX - MIN + 1)) + MIN; /*Génération d'un nombre aléatoire pour les colonne*/
		nb_ligne = (rand() % (MAX - MIN + 1)) + MIN; /*Génération d'un nombre aléatoire pour les lignes*/
		matrice[nb_ligne][nb_colonne] = pierre;
	}
	
	qts_eau = (rand() % (MAX_eau - MIN_eau + 1)) + MIN; /*Génération d'un nombre aléatoire pour l'eau*/
	for(j=0; j<qts_eau; j++){
		nb_colonne = (rand() % (MAX - MIN + 1)) + MIN;
		nb_ligne = (rand() % (MAX - MIN + 1)) + MIN;
		matrice[nb_ligne][nb_colonne] = eau;
		matrice[nb_ligne+1][nb_colonne] = eau;
		matrice[nb_ligne][nb_colonne+1] = eau;
		matrice[nb_ligne+1][nb_colonne+1] = eau;
		matrice[nb_ligne-1][nb_colonne] = eau;
		matrice[nb_ligne][nb_colonne-1] = eau;
		matrice[nb_ligne-1][nb_colonne-1] = eau;
		matrice[nb_ligne+1][nb_colonne-1] = eau;
		matrice[nb_ligne-1][nb_colonne+1] = eau;
		
	}
}


/*Fonction pour placer les pions des deux joueurs*/
void placer_pions(){
	int i, j;
	for(i=0; i<1; i++){
		for(j=0; j<N; j++){
			matrice[i][j] = joueur1;
		}
	}
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i == 10){
				matrice[i][j] = joueur2;
			}
		}
	}	
}

/*Fonction afficher la matrice*/
void afficher_matrice(){
	int i, j;
	for (i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%c", matrice[i][j]);
		}
		printf("\n");
	}	
}
