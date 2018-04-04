#include<stdio.h>
#include<stdlib.h>

/*unités de base */
typedef struct sbires{
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
}armee_t;

/*void structures(sbires * sbire_bleu, sbires * sbire_rouge);*/
sbires_t inventaire(sbires_t sbire);
sbires_t competences(sbires_t sbire, sbires_t cible);
sbires_t Combat_physique(sbires_t sbire, sbires_t cible);
sbires_t Combat_magique(sbires_t sbire, sbires_t cible);
int detection_mort(sbires_t sbire, armee_t armee_j1, armee_t armee_j2, int nb_pions_j1, int nb_pions_j2);
