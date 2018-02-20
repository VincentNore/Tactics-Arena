#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct decors_s{
		char eau; 
		char pierre;
	} decors_t;
	
typedef struct joueurs_s{
		char joueur1; 
		char joueur2;
	} joueurs_t;

void init_matrice();
void placer_decors();
void placer_pions();
void afficher_matrice();