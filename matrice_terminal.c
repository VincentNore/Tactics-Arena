#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include"matrice_terminal.h"
#include"couleur.h"

#define N 11


/*Fonction d'initialisation de la matrice à vide*/
void init_matrice(int mat[N][N]){
	int i, j;
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			mat[i][j] = 0;	
		}
	}	
}

/*Fonction d'affichage de la matrice*/
int afficher_matrice(int mat[N][N], armee_t armee){

	clrscr();
	for(int i = 0; i < N; i++){
		
		printf("\n");
		for(int j = 0; j < N; j++){
			printf("| ");
			
			if((i == armee.A.position[0]) && (j == armee.A.position[1])){
				couleur("31");
				printf("%s", armee.A.symbole);
				couleur("0");
			} 
			else if((i == armee.B.position[0]) && (j == armee.B.position[1])){
				couleur("31");
				printf("%s", armee.B.symbole);
				couleur("0");
			}
			else if((i == armee.C.position[0]) && (j == armee.C.position[1])){
				couleur("31");
				printf("%s", armee.C.symbole);
				couleur("0");
			}
			else if((i == armee.D.position[0]) && (j == armee.D.position[1])){
				couleur("31");
				printf("%s", armee.D.symbole);
				couleur("0");
			}
			else if((i == armee.E.position[0]) && (j == armee.E.position[1])){
				couleur("31");
				printf("%s", armee.E.symbole);
				couleur("0");
			}
			else {
				printf("  ");
				mat[i][j] = 0;
			}
			
			 if((i == armee.V.position[0]) && (j == armee.V.position[1])){
			 	couleur("32");
				printf("%s", armee.V.symbole);
				couleur("0");
			}
			else if((i == armee.W.position[0]) && (j == armee.W.position[1])){
				couleur("32");
				printf("%s", armee.W.symbole);
				couleur("0");
			}
			else if((i == armee.X.position[0]) && (j == armee.X.position[1])){
				couleur("32");
				printf("%s", armee.X.symbole);
				couleur("0");
			}
			else if((i == armee.Y.position[0]) && (j == armee.Y.position[1])){
				couleur("32");
				printf("%s", armee.Y.symbole);
				couleur("0");
			}
			else if((i == armee.Z.position[0]) && (j == armee.Z.position[1])){
				couleur("32");
				printf("%s", armee.Z.symbole);
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

sbires_t positionner_sbire(sbires_t sbire, int mat[N][N]){
/*Fonction de verification de position d'unite*/
	for(int n = 0; n < 2; n++){
		if(n == 0){
			printf("Ligne : ");
		} 
		else {
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
			return(sbire);

	} 
	else if(mat[sbire.position[0]][sbire.position[1]] != 0) {

		printf("La case %i - %i est déjà occupée\n", (sbire.position[0] + 1), (sbire.position[1] + 1));
		sbire = positionner_sbire(sbire, mat);
		return sbire;
	}
}

armee_t init_armee(armee_t armee, sbires_t sbire, int mat[N][N]){

	int j;	
	
	clrscr();
	
	j = 1;
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
	
	clrscr();
	j = 2;
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
/*Fonction d'initialisation d'unites*/
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
	sbire.position[0] = 11;
	sbire.position[1] = 11;
		
	sbire = positionner_sbire(sbire, mat);
	mat[sbire.position[0]][sbire.position[1]] = 1;

	printf("\nSbire %s créé : \n", sbire.nom);
	printf("Attaque : %i \nDefense : %i \nMana : %i \nVie : %i \nTaux d'esquive : %i pourcents\nNombre de pas possibles : %i \n", sbire.attaque, sbire.defense, sbire.mana, sbire.vie, sbire.esquive, sbire.nbr_depl);
	return(sbire);
}

