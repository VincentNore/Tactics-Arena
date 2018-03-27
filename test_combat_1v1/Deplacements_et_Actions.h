#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 11

typedef struct type_sbires{
		char * nom;
		int attaque;
		int vie;
		int defense;
		int esquive; 
		int mana;
		int nbr_depl;
		int position[2];
} t_sbires;

int Detection_Cible (t_sbires sbire, int direction, int mat[N][N], int ennemi){
/*Fonction de détection de cible dans toutes les directions - Détection linéaire - Version Test*/
	int n;
	switch(direction){
		case 1 : for(n = 0 ; n <= (sbire.nbr_depl + 1) ; n++){
				if(mat[sbire.position[0]][sbire.position[1] - n] == 2){
					printf("Ennemi a %i cases à gauche de %s\n", n, sbire.nom);
					ennemi++;
				}
			}
			ennemi = Detection_Cible(sbire, (direction + 1), mat, ennemi);
			break;

		case 2 : for(n = 0 ; n <= (sbire.nbr_depl + 1) ; n++){
				if(mat[sbire.position[0]][sbire.position[1] + n] == 2){
					printf("Ennemi a %i cases à droite de %s\n", n, sbire.nom);
					ennemi++;
				}
			}
			ennemi = Detection_Cible(sbire, (direction + 1), mat, ennemi);
			break;

		case 3 : for(n = 0 ; n <= (sbire.nbr_depl + 1) ; n++){
				if(mat[sbire.position[0] - n][sbire.position[1]] == 2){
					printf("Ennemi a %i cases au-dessus de %s\n", n, sbire.nom);
					ennemi++;
				}
			}
			ennemi = Detection_Cible(sbire, (direction + 1), mat, ennemi);
			break;

		case 4 : for(n = 0 ; n <= (sbire.nbr_depl + 1) ; n++){
				if(mat[sbire.position[0] + n][sbire.position[1]] == 2){
					printf("Ennemi a %i cases en-dessous de %s\n", n, sbire.nom);
					ennemi++;
				}
			}
			break;
	}
	return ennemi;
}

t_sbires Deplacer_Pion(t_sbires sbires, int mat[N][N], int direction){
/*Fonction de déplacement d'un Sbire*/
/*Compte les cases à la verticale (haut et bas) et à l'horizontale (gauche et droite)
Laisse le choix de la direction tout en prenant les limites de déplacement et la taille de la matrice en compte*/

	int nbr_cases = 0;
	int nbr_cap = 0;
	char * dir;
	
	printf("Comptage des cases praticables :\n");
	printf("Direction = %i\n", direction);

	if (direction == 1) {

		printf("Aller à gauche ?\n(Y/N) : ");
		scanf("%s", dir);

		if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {
			printf("Horizontal gauche : ");

			for(int n = 1; (mat[sbires.position[0]][(sbires.position[1] - n)] == 0) && (nbr_cases < sbires.nbr_depl) ; n++){

				if( (sbires.position[1] - nbr_cases) > 0 ){
					nbr_cases++;
				}

			}

			printf("%i cases praticables\n", nbr_cases);

			printf("Déplacement de combien de cases ? (Rappel : Cases praticables = %i)\nNbr case(s) à parcourir : ", nbr_cases);
			scanf("%i", &nbr_cap);

			while(nbr_cap > nbr_cases){

				printf("Dépassement du nombre de cases praticables. Recommencez :\nNbr case(s) à parcourir : ");
				scanf("%i", &nbr_cap);

			}

			sbires.position[1] = sbires.position[1] - nbr_cap;
			nbr_cases = nbr_cases - nbr_cap;

			if( (sbires.nbr_depl - nbr_cases > 0) && (nbr_cases > 0) ){

				printf("Déplacements encore possibles, voulez-vous continuer ?\n(Y/N) : ");
				scanf("%s", dir);

				if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

					printf("Même direction (G ou D) ?\n(Y/N) : ");
					scanf("%s", dir);

					if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

						Deplacer_Pion(sbires, mat, direction);

					} else {

						Deplacer_Pion(sbires, mat, (direction + 1) );

					}

				}

			}

			return sbires;

		}

		printf("Aller à droite ?\n(Y/N) : ");
		scanf("%s", dir);

		if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

			printf("Horizontal droit : ");

			for(int n = 1 ; (mat[sbires.position[0]][(sbires.position[1] + n)] == 0) && (nbr_cases < sbires.nbr_depl) ; n++){

				if( (sbires.position[1] + nbr_cases) < N) {

					nbr_cases++;

				}

			}

			printf("%i cases praticables\n", nbr_cases);

			printf("Déplacement de combien de cases ? (Rappel : Cases praticables = %i)\nNbr case(s) à parcourir : ", nbr_cases);
			scanf("%i", &nbr_cap);

			while(nbr_cap > nbr_cases){

				printf("Dépassement du nombre de cases praticables. Recommencez :\nNbr case(s) à parcourir : ");
				scanf("%i", &nbr_cap);

			}

			sbires.position[1] = sbires.position[1] + nbr_cap;
			nbr_cases = nbr_cases - nbr_cap;

			if( (sbires.nbr_depl - nbr_cases > 0) && (nbr_cases > 0) ){

				printf("Déplacements encore possibles, voulez-vous continuer ?\n(Y/N) : ");
				scanf("%s", dir);

				if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

					printf("Même direction (G ou D) ?\n(Y/N) : ");
					scanf("%s", dir);

					if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

						Deplacer_Pion(sbires, mat, direction);

					} else {

						Deplacer_Pion( sbires, mat, (direction + 1) );

					}

				}

			}

			return sbires;

		}

	}
	if (direction == 2) {

		printf("Aller en haut ?\n(Y/N) : ");
		scanf("%s", dir);

		if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {
			printf("Vertical haut : ");

			for(int n = 1 ; (mat[(sbires.position[0] - n)][sbires.position[1]] == 0) && (nbr_cases < sbires.nbr_depl) ; n++){

				if( (sbires.position[0] - nbr_cases) > 0){

					nbr_cases++;

				}

			}

			printf("%i cases praticables\n", nbr_cases);


			printf("Déplacement de combien de cases ? (Rappel : Cases praticables = %i)\nNbr case(s) à parcourir : ", nbr_cases);
			scanf("%i", &nbr_cap);

			while(nbr_cap > nbr_cases){

				printf("Dépassement du nombre de cases praticables. Recommencez :\nNbr case(s) à parcourir : ");
				scanf("%i", &nbr_cap);

			}

			sbires.position[0] = sbires.position[0] - nbr_cap;
			nbr_cases = nbr_cases - nbr_cap;

			if( (sbires.nbr_depl - nbr_cases > 0) && (nbr_cases > 0) ){

				printf("Déplacements encore possibles, voulez-vous continuer ?\n(Y/N) : ");
				scanf("%s", dir);

				if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

					printf("Même direction (G ou D) ?\n(Y/N) : ");
					scanf("%s", dir);

					if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

						Deplacer_Pion(sbires, mat, direction);

					} else {

						Deplacer_Pion(sbires, mat, (direction - 1));

					}
				}
			}

			return sbires;

		}


		printf("Aller en bas ?\n(Y/N) : ");
		scanf("%s", dir);

		if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {	
			printf("Vertical bas : ");

			for(int n = 1 ; (mat[(sbires.position[0] + n)][sbires.position[1]] == 0) && (nbr_cases < sbires.nbr_depl) ; n++){

				if( (sbires.position[0] + nbr_cases) < N){

					nbr_cases++;

				}

			}

			printf("%i cases praticables\n", nbr_cases);

			printf("Déplacement de combien de cases ? (Rappel : Cases praticables = %i)\nNbr cases à parcourir : ", nbr_cases);
			scanf("%i", &nbr_cap);

			while(nbr_cap > nbr_cases){

				printf("Dépassement du nombre de cases praticables. Recommencez :\nNbr case à parcourir : ");
				scanf("%i", &nbr_cap);

			}

			sbires.position[0] = sbires.position[0] + nbr_cap;
			nbr_cases = nbr_cases - nbr_cap;

			if( (sbires.nbr_depl - nbr_cases > 0) && (nbr_cases > 0) ){

				printf("Déplacements encore possibles, voulez-vous continuer ?\n(Y/N) : ");
				scanf("%s", dir);

				if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

					printf("Même direction (G ou D) ?\n(Y/N) : ");
					scanf("%s", dir);

					if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

						Deplacer_Pion(sbires, mat, direction);

					} else {

						Deplacer_Pion(sbires, mat, (direction - 1));

					}

				}

			}

			return sbires;

		}
		
	}

}

t_sbires Combat_physique(t_sbires sbire, t_sbires cible){
/*Fonction de calcul des dégâts physiques infligés*/
	int degats;
	printf("%s attaque %s\n", sbire.nom, cible.nom);
	degats = ( sbire.attaque - (cible.defense)/3 )/10;
	if(degats < 0){
		degats = 0;
	}
	if( (rand()%(100 - 1) + 1) > cible.esquive ){ 
		cible.vie = cible.vie - degats;
		if(cible.vie < 0){
			cible.vie = 0;
		}
		printf("%s reçoit %i dégats\n", cible.nom, degats);
		printf("Il reste %i PVs à %s\n", cible.vie, cible.nom);
	} else printf("%s a esquivé !\n", cible.nom);
	return cible;
}

t_sbires Combat_magique(t_sbires sbires, t_sbires cible){
/*Fonction de calcul des dégâts magiques infligés*/
	int degats;
	printf("%s attaque %s\n", sbires.nom, cible.nom);
	degats = ( ( sbires.attaque*(sbires.mana/2) ) - cible.defense )/10;
	if(degats < 0){
		degats = 0;
	}
	if( (rand()%(100 - 1) + 1) > cible.esquive ){ 
		cible.vie = cible.vie - degats;
		printf("%s reçoit %i dégats magiques\n", cible.nom, degats);
		if(cible.vie < 0){
			cible.vie = 0;
		}
		printf("Il reste %i PVs à %s\n", cible.vie, cible.nom);
	} else {
		printf("%s a esquivé !\n", cible.nom);
	}
	return cible;
}

t_sbires Selection_Attaque(t_sbires sbire, t_sbires cible){
/*Fonction de sélection du type d'Attaque*/
	int choix = 0;
	printf("%s passe à l'attaque\n", sbire.nom);
	printf("Type d'attaque ?\n");
	printf("1 : Attaque normale\n");
	printf("2 : Attaque magique\n");
	printf("3 : Annuler attaque\n");
	scanf("%i", &choix);
	switch(choix){
		case 1 : printf("Attaque = %i\n", sbire.attaque);
			cible = Combat_physique(sbire, cible);
			break;
		case 2 : printf("Mana = %i\n", sbire.mana);
			cible = Combat_magique(sbire, cible);
			break;
		case 3 : printf("Attaque annulée\n");
			default : printf("Attaque annulée\n");
	}
	return cible;
}

t_sbires Selection_Deplacement(t_sbires sbires, int mat[N][N]){
/*Fonction de sélection de la direction de déplacement*/
	int choix = 0;
	printf("\nDistance maximale de déplacement de l'unité %s \n", sbires.nom);
	printf("%i cases maximum.\n", sbires.nbr_depl);
	printf("Position : x = %i y = %i\n", sbires.position[0], sbires.position[1]);
	printf("Déplacements vertical ou horizontal ?\n");
	printf("1 : Horizontal\n2 : Vertical\n3 : Annuler Déplacement\n");
	
	while( (choix <= 0) || (choix > 3) ){
		printf("Choix : ");
		scanf("%i", &choix);
	
		switch(choix){
			case 1 : printf("Déplacement horizontal\n");
				sbires = Deplacer_Pion(sbires, mat, choix);
				break;
			case 2 : printf("Déplacement vertical\n");
				sbires = Deplacer_Pion(sbires, mat, choix);
				break;
			case 3 : printf("Déplacement annulé\n");
				break;
			default : printf("Ce choix n'existe pas !\n");
		}
	}
	return sbires;
}

t_sbires Action(t_sbires sbires, int mat[N][N]){
/*Actions possibles de l'unité : Défense , Inventaire et Annulation de l'Action*/

	int choix_action = 0;
	int nbr_ennemi = 0;
	
	printf("\nChoississez l'action de votre unité :\n");
	printf("1 : Defense\n");
	printf("2 : Voir inventaire\n");
	printf("3 : Observer le terrain\n");
	printf("4 : Choisir une autre unité\n");
	
	while( (choix_action <= 0) || (choix_action > 4) ){
		printf("Choix : ");
		scanf("%i", &choix_action);
	
		switch(choix_action){
			
			case 1 : printf("Defense = %i\nA BOSSER\n", sbires.defense);
				break;
			case 2 : printf("Inventaire\n");
				printf("Non implémenté\n");
				break;
			case 3 : printf("%s observe les environs\n", sbires.nom);
				nbr_ennemi = Detection_Cible(sbires, 1, mat, nbr_ennemi);
				if(nbr_ennemi > 0){
					printf("Il y a %i ennemi(s) dans les environs\n", nbr_ennemi);
				} else {
					printf("Rien à signaler\n");
				}
				choix_action = 0;
				break;
			case 4 : printf("On va voir ailleurs\n");
				break;
			default : printf("ça va pas marcher comme ça...\n");
		}
	}
	return sbires;
}

/*t_sbires Selection_Action(t_sbires sbires, t_sbires cible, int mat[N][N]){
//Fonction de sélection : Déplacement ou Action de l'unité

	int choix = 0;
	printf("\nQue doit faire %s ?\n", sbires.nom);
		printf("1 : Se déplacer\n");
		printf("2 : Agir\n");
		printf("3 : Annuler\n"); //A défaut d'avoir une autre façon de tester le programme
	
		scanf("%i", &choix);
	
	switch (choix) {
		case 1 : printf("INCOMPLET\n");
			Deplacement(sbires, mat); // /!\Insérez matrice ci-contre/!\
			break;
		case 2 : cible = Action(sbires, cible);
			return cible;
		case 3 : printf("Action annulée\n");
			break;
		default : printf("Won't work\n");
			break;
	}
	return sbires;
}*/
