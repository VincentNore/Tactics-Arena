#include<stdio.h>
#include<stdlib.h>

typedef struct sbires sbires; /*unités de base */
		struct sbires
		{
		char * nom;
		char symbole;
		int attaque;
		int vie;
		int defense;
		int esquive; 
		int mana;
		int nbr_depl;
		int position[2];
		}; 

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
void placer_decors();
void placer_pions();
void afficher_matrice();
int Compte_Cases(sbires, char matrice_affichage, int direction);
void Deplacement(sbires, char matrice_affichage);
void Action(sbires);
sbires Selection_Action(sbires, char matrice_affichage);
