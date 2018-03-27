#include<stdio.h>
#include<stdlib.h>

#define N 11
typedef struct sbires_s{
		char * nom;
		char * symbole;
		int attaque;
		int vie;
		int defense;
		int esquive;
		int mana;
		int nbr_depl;
		int position[2];
		}sbires_t;
		
typedef struct armee_s{
		sbires_t A;
		sbires_t B;
		sbires_t C;
		sbires_t D;
		sbires_t E;
		
		sbires_t V;
		sbires_t W;
		sbires_t X;
		sbires_t Y;
		sbires_t Z;
		}armee_t;

typedef struct decors_s{
		char eau; 
		char pierre;
		}decors_t;
	
typedef struct joueurs_s{
		char pion; 
		int position_ligne;
		int position_colonne;
		}joueurs_t;
	
void init_matrice();

armee_t init_armee(armee_t armee, sbires_t sbire, int mat[N][N]);
sbires_t init_sbire(sbires_t sbire, int mat[N][N]);

void placer_decors();

int afficher_matrice(int mat[N][N], armee_t armee, decors_t decors);

int positionner_sbire(sbires_t sbire, int mat[N][N]);
