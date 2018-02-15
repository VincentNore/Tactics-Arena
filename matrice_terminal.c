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

void init_matrice(){
	int i, j;
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			matrice[i][j] = libre;
			
		}
	}	
}

void placer_decors(){
	int i, j, nb_ligne, nb_colonne ,nb_pierre, qts_eau;
	srand(time(NULL));
	nb_pierre = (rand() % (MAX_pierre - MIN_pierre + 1)) + MIN;
	for(i=0; i<nb_pierre; i++){
		nb_colonne = (rand() % (MAX - MIN + 1)) + MIN;
		nb_ligne = (rand() % (MAX - MIN + 1)) + MIN;
		matrice[nb_ligne][nb_colonne] = pierre;
	}
	
	qts_eau = (rand() % (MAX_eau - MIN_eau + 1)) + MIN;
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


void afficher_matrice(){
	int i, j;
	for (i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%c", matrice[i][j]);
		}
		printf("\n");
	}	
}

int main(){
	init_matrice();
	placer_decors();
	afficher_matrice();
}
