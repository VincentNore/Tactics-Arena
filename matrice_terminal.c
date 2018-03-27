#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
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
void init_matrice(int mat[N][N]){
	int i, j;
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			mat[i][j] = 0;	
		}
	}	
}


/*Fonction pour placer les décors*/
void placer_decors(int mat[N][N], decors_t decors){
	int i, j, nb_ligne=0, nb_colonne=0, nb_pierre=0, qts_eau=0;
	
	srand(time(NULL));
	nb_pierre = (rand() % (MAX_pierre - MIN_pierre + 1)) + MIN; /*Génération d'un nombre aléatoire pour les pierres*/
	
	for(i=0; i<nb_pierre; i++){
		nb_colonne = (rand() % (MAX - MIN + 1)) + MIN; /*Génération d'un nombre aléatoire pour les colonne*/
		nb_ligne = (rand() % (MAX - MIN + 1)) + MIN; /*Génération d'un nombre aléatoire pour les lignes*/
		mat[nb_ligne][nb_colonne] = 1;
		printf("p ");

	}
	
	qts_eau = (rand() % (MAX_eau - MIN_eau + 1)) + MIN; /*Génération d'un nombre aléatoire pour l'eau*/
	
	for(j=0; j<qts_eau; j++){
		nb_colonne = (rand() % (MAX - MIN + 1)) + MIN;
		nb_ligne = (rand() % (MAX - MIN + 1)) + MIN;
		mat[nb_ligne][nb_colonne] = 2;
		printf("o ");
		/*mat[nb_ligne+1][nb_colonne] = 2;
		printf("o ");
		mat[nb_ligne][nb_colonne+1] = 2;
		printf("o ");
		mat[nb_ligne+1][nb_colonne+1] = 2;
		printf("o ");		
		mat[nb_ligne-1][nb_colonne] = 2;
		printf("o ");
		mat[nb_ligne][nb_colonne-1] = 2;
		printf("o ");
		mat[nb_ligne-1][nb_colonne-1] = 2;
		printf("o ");
		mat[nb_ligne+1][nb_colonne-1] = 2;
		printf("o ");
		mat[nb_ligne-1][nb_colonne+1] = 2;
		printf("o ");*/
	}
}

/*Fonction afficher la matrice*/
int afficher_matrice(int mat[N][N], sbires_t sbire_10, sbires_t dummy, decors_t decors){

	int nb_colonne = (rand() % (MAX - MIN + 1)) + MIN;
	int nb_ligne = (rand() % (MAX - MIN + 1)) + MIN;
	int qts_eau = (rand() % (MAX_eau - MIN_eau + 1)) + MIN;
		
	for(int i = 0; i < N; i++){
		printf("\n");
		for(int j = 0; j < N; j++){
			printf("| ");
			/*if((i == nb_ligne) && (j == nb_colonne)){
				for(int a = 0; a<qts_eau; a++){
					printf("~");
					mat[i][j] = 2;
				}
			}*/
			
			if((i == sbire_10.position[0]) && (j == sbire_10.position[1])){
				printf("X ");
				mat[i][j] = 10;
			} else if((i == dummy.position[0]) && (j == dummy.position[1])){
				printf("D ");
				mat[i][j] = 20;
			} else {
				printf("  ");
				mat[i][j] = 0;
			}
		}
		printf("|");
	}
	printf("\n\n");
}

int positionner_sbire(sbires_t sbire_10, int mat[N][N]){
/*Fonction de positionnement d'unité - Version Test*/
	if(mat[sbire_10.position[0]][sbire_10.position[1]] == 0){
		return 1;
	} else {
		printf("La case %i - %i est déjà occupée\n", sbire_10.position[0], sbire_10.position[1]);
		return 0;
	}
}

sbires_t init_armee(sbires_t sbire_10, int mat[N][N]){
/*Fonction d'initialisation d'unités - Version Test*/
	int poser = 0;
	sbire_10.nom = malloc(sizeof(char)*128);
	printf("\nNom de l'unité : ");
	scanf("%s", sbire_10.nom);
	/*if( (strcmp(sbire.nom, "dummy") == 0) || (strcmp(sbire.nom, "Dummy") == 0) ){
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
	} else {*/
	for(int i = 0; i < 5; i++){
		sbire_10.attaque = 30;
		sbire_10.defense = 20;
		sbire_10.vie = 50;
		sbire_10.mana = 20;
		sbire_10.esquive = 30;
		sbire_10.nbr_depl = 5;
		printf("Position de départ : \n");
		while(poser == 0){
			for(int n = 0; n < 2; n++){
				if(n == 0){
					printf("Ligne : ");
				} else {
					printf("Colonne : ");
				}
				scanf("%i", &sbire_10.position[n]);
			}
			poser = positionner_sbire(sbire_10, mat);
		}
	}
	printf("\nSbire %s créé : \n", sbire_10.nom);
	printf("Attaque : %i \nDefense : %i \nMana : %i \nVie : %i \nTaux d'esquive : %i pourcents\nNombre de pas possibles : %i \n", sbire_10.attaque, sbire_10.defense, sbire_10.mana, sbire_10.vie, sbire_10.esquive, sbire_10.nbr_depl);
	return sbire_10;
}

