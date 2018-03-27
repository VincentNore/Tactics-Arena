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
int afficher_matrice(int mat[N][N], armee_t armee, decors_t decors){

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
			
			if((i == armee.A.position[0]) && (j == armee.A.position[1])){
				printf("%s", armee.A.symbole);
				mat[i][j] = 1;
			} 
			else if((i == armee.B.position[0]) && (j == armee.B.position[1])){
				printf("%s", armee.B.symbole);
				mat[i][j] = 1;
			}
			else if((i == armee.C.position[0]) && (j == armee.C.position[1])){
				printf("%s", armee.C.symbole);
				mat[i][j] = 1;
			}
			else if((i == armee.D.position[0]) && (j == armee.D.position[1])){
				printf("%s", armee.D.symbole);
				mat[i][j] = 1;
			}
			else if((i == armee.E.position[0]) && (j == armee.E.position[1])){
				printf("%s", armee.E.symbole);
				mat[i][j] = 1;
			}
			else {
				printf("  ");
				mat[i][j] = 0;
			}
			
			 if((i == armee.V.position[0]) && (j == armee.V.position[1])){
				printf("%s", armee.V.symbole);
				mat[i][j] = 1;
			}
			else if((i == armee.W.position[0]) && (j == armee.W.position[1])){
				printf("%s", armee.W.symbole);
				mat[i][j] = 1;
			}
			else if((i == armee.X.position[0]) && (j == armee.X.position[1])){
				printf("%s", armee.X.symbole);
				mat[i][j] = 1;
			}
			else if((i == armee.Y.position[0]) && (j == armee.Y.position[1])){
				printf("%s", armee.Y.symbole);
				mat[i][j] = 1;
			}
			else if((i == armee.Z.position[0]) && (j == armee.Z.position[1])){
				printf("%s", armee.Z.symbole);
				mat[i][j] = 1;
			}
			else {
				printf("  ");
				mat[i][j] = 0;
			}
		}
		printf("|");
	}
	printf("\n\n");
}

int positionner_sbire(sbires_t sbire, int mat[N][N]){
/*Fonction de positionnement d'unité - Version Test*/
	if(mat[sbire.position[0]][sbire.position[1]] == 0){
		return 1;
	} else {
		printf("La case %i - %i est déjà occupée\n", sbire.position[0], sbire.position[1]);
		return 0;
	}
}

armee_t init_armee(armee_t armee, sbires_t sbire, int mat[N][N]){
	
	printf("--- Joueur 1 - unité 1 ---\n");
	armee.A = init_sbire(sbire, mat);
	printf("--- Joueur 1 - unité 2 ---\n");
	armee.B = init_sbire(sbire, mat);
	printf("--- Joueur 1 - unité 3 ---\n");
	armee.C = init_sbire(sbire, mat);
	printf("--- Joueur 1 - unité 4 ---\n");
	armee.D = init_sbire(sbire, mat);
	printf("--- Joueur 1 - unité 5 ---\n");
	armee.E = init_sbire(sbire, mat);
	
	printf("--- Joueur 2 - unité 1 ---\n");
	armee.V = init_sbire(sbire, mat);
	printf("--- Joueur 2 - unité 2 ---\n");
	armee.W = init_sbire(sbire, mat);
	printf("--- Joueur 2 - unité 3 ---\n");
	armee.X = init_sbire(sbire, mat);
	printf("--- Joueur 2 - unité 4 ---\n");
	armee.Y = init_sbire(sbire, mat);
	printf("--- Joueur 2 - unité 5 ---\n");
	armee.Z = init_sbire(sbire, mat);
	
	return armee;
}

sbires_t init_sbire(sbires_t sbire, int mat[N][N]){
/*Fonction d'initialisation d'unités*/
	int poser = 0;
	sbire.nom = malloc(sizeof(char)*128);
	sbire.symbole = malloc(sizeof(char)*128);
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
	printf("\nSbire %s créé : \n", sbire.nom);
	printf("Attaque : %i \nDefense : %i \nMana : %i \nVie : %i \nTaux d'esquive : %i pourcents\nNombre de pas possibles : %i \n", sbire.attaque, sbire.defense, sbire.mana, sbire.vie, sbire.esquive, sbire.nbr_depl);
	return sbire;
}

