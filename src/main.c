#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include"../include/Deplacements_et_Actions.h"
#include"../include/ChoixJoueur.h"
#include"../include/matrice_terminal.h"

#define N 11

/**
*\file main.c
*\author Nore Vincent
*\date 6 avril 2018
*\version 1.0
*\brief Fonction principal.
*
*\details Fonction principale qui appelle les différentes fonctions du programme.
*
*/

int main(){

	armee_t armee_j1;
	armee_t armee_j2;
	
	sbires_t sbire;
	sbires_t cible;
	
	int mat[N][N];
	
	int nb_pions_j1 = 5;
	int nb_pions_j2 = 5;
	
	int tour = 0;
	
	int fin = 0;
	
	init_matrice(mat);
	
	armee_j1 = init_armee_j1(armee_j1, sbire, mat);
	
	armee_j2 = init_armee_j2(armee_j2, sbire, mat);
	
	afficher_matrice(mat, armee_j1, armee_j2);
	
	tour = DebutPartie(tour);
	
	while(fin != 1){
 		sbire = ChoixUnite(tour, armee_j1, armee_j2);
		menu(sbire, armee_j1, armee_j2, cible, mat);
		afficher_matrice(mat, armee_j1, armee_j2);
		
		if(tour == 1){
			nb_pions_j1 = detection_mort(sbire, armee_j1, armee_j2, nb_pions_j1, nb_pions_j2);
		}
		else{
			nb_pions_j2 = detection_mort(sbire, armee_j1, armee_j2, nb_pions_j1, nb_pions_j2);
		}
		
		if(nb_pions_j1 == 0){
			printf("Victoire du joueur 1 !!!");
			fin = 1;
		}
		else if(nb_pions_j2 == 0){
			printf("Victoire du joueur 2 !!!");
			fin = 1;
		}
	}
	return 0;
}
