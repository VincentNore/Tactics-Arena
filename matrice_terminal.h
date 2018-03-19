#include<stdio.h>
#include<stdlib.h>

#define N 11

typedef struct sbires_s{
		char * nom;
		char symbole;
		int attaque;
		int vie;
		int defense;
		int esquive; 
		int mana;
		int nbr_depl;
		int position[2];
		} sbires_t; 

typedef struct decors_s{
		char eau; 
		char pierre;
	} decors_t;
	
typedef struct joueurs_s{
		char pion; 
		int position_ligne;
		int position_colonne;
	} joueurs_t;
	
void init_matrice();

sbires_t init_armee(sbires_t sbire, int mat[N][N]);

void placer_decors();

int afficher_matrice(int mat[N][N], sbires_t sbire, sbires_t dummy, decors_t decors);

int positionner_sbire(sbires_t sbire, int mat[N][N]);
