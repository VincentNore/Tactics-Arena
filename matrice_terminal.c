#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 11
#define MAX 2
#define MIN 0

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

/*void placer_decors(){
	int i, j;
	srand(time(NULL));
    nb_objet = (rand() % (MAX - MIN + 1)) + MIN;
    for(i=0; i<nb; i++){
    	for(j=0; j<nb
			matrice[nb][nb] = eau;
	}
}*/

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
