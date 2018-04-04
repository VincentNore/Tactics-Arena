#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/structures.h"

#define N 11

/**
*\file Deplacements_et_Actions.c
*\author Jolliet Corentin
*\author Colin Kevin
*\date 6 avril 2018
*\version 1.0
*\brief Permettre aux joueurs d'effectuer une action
*
*\details Ces fonctions permettent de déplacer et d'attaquer un pion adverse, mais aussi de détecter si un ennemi est à porter et de calculer la distance d'attaque du pion.
*
*/

/**
*\brief Détecter si une cible est présente.
*\details Vérifier, grâce à des calculs, si des ennemis sont présents autour du pion courant.
*\param sbires_t sbire La structure du pion courant.
*\param int direction La direction, en entier, à vérifier.
*\param int mat[N][N] La matrice d'affichage.
*\param int ennemi La variable pour compter le nombre d'ennemis détecter.
*/
int Detection_Cible (sbires_t sbire, int direction, int mat[N][N], int ennemi){
/*Fonction de détection de cible dans toutes les directions - Détection linéaire*/
	int n;
	switch(direction){
		case 1 : for(n = 1 ; (n <= (sbire.nbr_depl + 1)) && ((sbire.position[1] - n) >= 0) ; n++){
				if( (mat[sbire.position[0]][sbire.position[1] - n] == 1) && (sbire.position[1] > 0) ){
					printf("Ennemi a %i case(s) à gauche de %s\n", n, sbire.nom);
					ennemi++;
				}
			}
			ennemi = Detection_Cible(sbire, (direction + 1), mat, ennemi);
			break;

		case 2 : for(n = 1 ; (n <= (sbire.nbr_depl + 1)) && ((sbire.position[1] - n) < N) ; n++){
				if( (mat[sbire.position[0]][sbire.position[1] + n] == 1) && (sbire.position[1] < N) ){
					printf("Ennemi a %i case(s) à droite de %s\n", n, sbire.nom);
					ennemi++;
				}
			}
			ennemi = Detection_Cible(sbire, (direction + 1), mat, ennemi);
			break;

		case 3 : for(n = 1 ; (n <= (sbire.nbr_depl + 1)) && ((sbire.position[0] - n) >= 0) ; n++){
				if( (mat[sbire.position[0] - n][sbire.position[1]] == 1) && (sbire.position[0] > 0) ){
				
					printf("Ennemi a %i case(s) au-dessus de %s\n", n, sbire.nom);
					ennemi++;
				}
			}
			ennemi = Detection_Cible(sbire, (direction + 1), mat, ennemi);
			break;

		case 4 : for(n = 1 ; (n <= (sbire.nbr_depl + 1)) && ((sbire.position[0] + n) < N) ; n++){
				if( (mat[sbire.position[0] + n][sbire.position[1]] == 1) && (sbire.position[0] < N) ){
					printf("Ennemi a %i case(s) en-dessous de %s\n", n, sbire.nom);
					ennemi++;
				}
			}
			break;
	}
	return ennemi;
}

/**
*\brief Détecter si une cible est à porter.
*\details Vérifier, grâce à des calculs, si des ennemis sont à porter d'attaque du pion.
*\param sbires_t sbire La structure du pion courant.
*\param int direction La direction, en entier, à vérifier.
*\param int mat[N][N] La matrice d'affichage.
*\param int ennemi La variable pour compter le nombre d'ennemis détecter.
*/
int Detection_Portee (sbires_t sbire, int direction, int mat[N][N], int ennemi){
/*Fonction de détection de cible dans les 4 directions - Direction Linéaire -*/
	int n;
	switch(direction){
		case 1 : for(n = 1 ; (n <= (sbire.nbr_depl + 1)) && ((sbire.position[1] - n) >= 0) ; n++){
				if( (mat[sbire.position[0]][sbire.position[1] - n] == 1) && (sbire.position[1] > 0) ){
					
					ennemi++;
				}
			}
			ennemi = Detection_Portee(sbire, (direction + 1), mat, ennemi);
			break;

		case 2 : for(n = 1 ; (n <= (sbire.nbr_depl + 1)) && ((sbire.position[1] - n) < N) ; n++){
				if( (mat[sbire.position[0] + n][sbire.position[1]] == 1) && (sbire.position[1] < N) ){
					
					ennemi++;
				}
			}
			ennemi = Detection_Portee(sbire, (direction + 1), mat, ennemi);
			break;

		case 3 : for(n = 1 ; (n <= (sbire.nbr_depl + 1)) && ((sbire.position[0] - n) >= 0) ; n++){
				if( (mat[sbire.position[0] - n][sbire.position[1]] == 1) && (sbire.position[0] > 0) ){
					
					ennemi++;
				}
			}
			ennemi = Detection_Portee(sbire, (direction + 1), mat, ennemi);
			break;

		case 4 : for(n = 1 ; (n <= (sbire.nbr_depl + 1)) && ((sbire.position[0] + n) < N) ; n++){
				if( (mat[sbire.position[0] + n][sbire.position[1]] == 1) && (sbire.position[0] < N) ){
					
					ennemi++;
				}
			}
			break;
	}
	return ennemi;
}

/**
*\brief Déplacer un pion dans la direction choisis.
*\details Donner la possibilité au joueur de déplacer son pion dans une des quatre directions proposé.
*\param sbires_t sbire La structure du pion courant.
*\param int mat[N][N] La matrice d'affichage.
*\param int direction La direction, en entier, à vérifier.
*\param int nb_dep Le nombre de déplacement pour ce pion.
*/
sbires_t Deplacer_Pion(sbires_t sbires, int mat[N][N], int direction, int nb_dep){
/*Fonction de déplacement d'un Sbire*/
/*Compte les cases à la verticale (haut et bas) et à l'horizontale (gauche et droite)
Laisse le choix de la direction tout en prenant les limites de déplacement et la taille de la matrice en compte*/

	int nbr_cases = 0;
	int nbr_cap = 0;
	int n;
	char * dir;
	
	printf("Comptage des cases praticables :\n");

	if (direction == 1) { /*Directions Horizontales : Gauche, puis Droite*/

		printf("Aller à gauche ?\n(Y/N) : "); /*Déroulement pour la direction horizontale gauche*/
		scanf("%s", dir);

		/*Comptage des cases praticables à droite du sbire*/
		if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {
			printf("Horizontal gauche : ");

			for(n = 1; (mat[sbires.position[0]][(sbires.position[1] - n)] == 0) && (nbr_cases < nb_dep) ; n++){

				if( ((sbires.position[1] - nbr_cases) > 0) && (sbires.position[1] > 0) ){ /*Prise en compte des bords de la matrice*/
					nbr_cases++;
				}

			}

			printf("%i cases praticables\n", nbr_cases);

			/*Prise en compte de l'impossibilité du déplacement dans la direction souhaitée*/
			if( nbr_cases == 0 ) {

				printf("Tu vas droit dans le mur ^^\n");
				sbires = Deplacer_Pion(sbires, mat, direction, nb_dep); /*Repéte la fonction avec la même direction*/

			} else {

				printf("%i déplacement possibles\nNbr case(s) à parcourir : ", nbr_cases);
				scanf("%i", &nbr_cap);

				while(nbr_cap > nbr_cases){ /*Prise en compte du dépassement des déplacments autorisés*/

					printf("Dépassement du nombre de cases praticables. Recommencez :\nNbr case(s) à parcourir : ");
					scanf("%i", &nbr_cap);

				}

				/*Mise à jour de la matrice et de la position du sbire*/
				mat[sbires.position[0]][sbires.position[1]] = 0;
				sbires.position[1] = sbires.position[1] - nbr_cap;
				mat[sbires.position[0]][sbires.position[1]] = 1;
				nbr_cases = nbr_cases - nbr_cap;

				/*Prise en compte des déplacements restants ci-dessous*/
				if( (nb_dep - nbr_cases > 0) && (nbr_cases > 0) ){

					printf("%i déplacements encore possibles, voulez-vous continuer ?\n\t(Retour en arrière IMPOSSIBLE)\n(Y/N) : ", (nb_dep - nbr_cases));
					scanf("%s", dir);

					if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

						printf("Même direction (G ou D) ?\n(Y/N) : "); /*Possibilité de continuer à l'horizontale ou d'aller à la verticale*/
						scanf("%s", dir);

						if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

							sbires = Deplacer_Pion(sbires, mat, direction, (nb_dep - nbr_cap) ); /*Repéte la fonction avec la même direction*/

						} else {

							sbires = Deplacer_Pion(sbires, mat, (direction + 1), (nb_dep - nbr_cap) ); /*Repéte la fonction avec un changement de direction (Verticale)*/

						}

					}

				}
			}

			return sbires; /*Renvoi de la structure dont on a modifié la position*/

		}

		printf("Aller à droite ?\n(Y/N) : "); /*Déroulement pour la direction horizontale droite*/
		scanf("%s", dir);

		/*Comptage des cases praticables à droite du sbire*/
		if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "o") == 0) || (strcmp(dir, "O") == 0) ) {

			printf("Horizontal droit : ");

			for(n = 1 ; (mat[sbires.position[0]][(sbires.position[1] + n)] == 0) && (nbr_cases < nb_dep) ; n++){

				if( ((sbires.position[1] + nbr_cases) < N) && (sbires.position[1] < N)) { /*Prise en compte des bords de la matrice*/

					nbr_cases++;

				}

			}

			printf("%i cases praticables\n", nbr_cases);

			/*Prise en compte de l'impossibilité du déplacement dans la direction souhaitée*/
			if( nbr_cases == 0 ) {

				printf("Tu vas droit dans le mur ^^\n");
				sbires = Deplacer_Pion(sbires, mat, direction, nb_dep); /*Repéte la fonction avec la même direction*/

			} else {

				printf("Nbr case(s) à parcourir : ");
				scanf("%i", &nbr_cap);

				while(nbr_cap > nbr_cases){/*Prise en compte du dépassement des déplacments autorisés*/

					printf("Dépassement du nombre de cases praticables. Recommencez :\nNbr case(s) à parcourir : ");
					scanf("%i", &nbr_cap);

				}

				/*Mise à jour de la matrice et de la position du sbire*/
				mat[sbires.position[0]][sbires.position[1]] = 0;
				sbires.position[1] = sbires.position[1] + nbr_cap;
				mat[sbires.position[0]][sbires.position[1]] = 1;
				nbr_cases = nbr_cases - nbr_cap;

				/*Prise en compte des déplacements restants ci-dessous*/
				if( (nb_dep - nbr_cases > 0) && (nbr_cases > 0) ){

					printf("%i déplacements encore possibles, voulez-vous continuer ?\n\t(Retour en arrière IMPOSSIBLE)\n(Y/N) : ", (nb_dep - nbr_cases));
					scanf("%s", dir);

					if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "n") == 0) || (strcmp(dir, "N") == 0) ) {

						printf("Même direction (G ou D) ?\n(Y/N) : "); /*Possibilité de continuer à l'horizontale ou d'aller à la verticale*/
						scanf("%s", dir);

						if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "n") == 0) || (strcmp(dir, "N") == 0) ) {

							sbires = Deplacer_Pion(sbires, mat, direction, (nb_dep - nbr_cap) ); /*Repéte la fonction avec la même direction*/

						} else {

							sbires = Deplacer_Pion( sbires, mat, (direction + 1), (nb_dep - nbr_cap) ); /*Repéte la fonction avec un changement de direction (Verticale)*/

						}

					}

				}
			}

			return sbires; /*Renvoi de la structure dont on a modifié la position*/

		}

		printf("Changer de direction ?\n(Y/N) : "); /*Si il y a eu erreur de frappe ou changement d'avis, plus haut, on donne la possibilitée au joueur de changer sa direction de déplacement*/
		scanf("%s", dir);

		if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "n") == 0) || (strcmp(dir, "N") == 0) ) {

			sbires = Deplacer_Pion(sbires, mat, (direction + 1), nb_dep ); /*Repéte la fonction avec un changement de direction (Verticale)*/
			return sbires; /*Renvoi de la structure dont on a modifié la position*/

		} else {

			sbires = Deplacer_Pion(sbires, mat, direction, nb_dep); /*Repéte la fonction avec la même direction*/
			return sbires; /*Renvoi de la structure dont on a modifié la position*/

		}
	}
	if (direction == 2) { /*Directions Verticales : Haut, puis Bas)*/

		printf("Aller en haut ?\n(Y/N) : "); /*Déroulement pour la direction verticale haute*/
		scanf("%s", dir);

		/*Comptage des cases praticables en haut du sbire*/
		if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "n") == 0) || (strcmp(dir, "N") == 0) ) {
			printf("Vertical haut : ");

			for(n = 1 ; (mat[(sbires.position[0] - n)][sbires.position[1]] == 0) && (nbr_cases < nb_dep) ; n++){

				if( ((sbires.position[0] - nbr_cases) > 0) && (sbires.position[0] > 0)){ /*Prise en compte des bords de la matrice*/

					nbr_cases++;

				}

			}

			printf("%i cases praticables\n", nbr_cases);

			/*Prise en compte de l'impossibilité du déplacement dans la direction souhaitée*/
			if( nbr_cases == 0 ) {

				printf("Tu vas droit dans le mur ^^\n");
				sbires = Deplacer_Pion(sbires, mat, direction, nb_dep); /*Repéte la fonction avec la même direction*/

			} else {

				printf("Nbr case(s) à parcourir : ");
				scanf("%i", &nbr_cap);

				while(nbr_cap > nbr_cases){/*Prise en compte du dépassement des déplacments autorisés*/

					printf("Dépassement du nombre de cases praticables. Recommencez :\nNbr case(s) à parcourir : ");
					scanf("%i", &nbr_cap);

				}

				/*Mise à jour de la matrice et de la position du sbire*/
				mat[sbires.position[0]][sbires.position[1]] = 0;
				sbires.position[0] = sbires.position[0] - nbr_cap;
				mat[sbires.position[0]][sbires.position[1]] = 1;
				nbr_cases = nbr_cases - nbr_cap;

				/*Prise en compte des déplacements restants ci-dessous*/
				if( (nb_dep - nbr_cases > 0) && (nbr_cases > 0) ){

					printf("%i déplacements encore possibles, voulez-vous continuer ?\n\t(Retour en arrière IMPOSSIBLE)\n(Y/N) : ", (nb_dep - nbr_cases));
					scanf("%s", dir);

					if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "n") == 0) || (strcmp(dir, "N") == 0) ) {

						printf("Même direction (H ou B) ?\n(Y/N) : "); /*Possibilité de continuer à l'horizontale ou d'aller à la verticale*/
						scanf("%s", dir);

						if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "n") == 0) || (strcmp(dir, "N") == 0) ) {

							sbires = Deplacer_Pion(sbires, mat, direction, (nb_dep - nbr_cap) ); /*Repéte la fonction avec la même direction*/

						} else {

							sbires = Deplacer_Pion(sbires, mat, (direction - 1), (nb_dep -nbr_cap) ); /*Repéte la fonction avec un changement de direction (Horizontale)*/

						}
					}
				}

			}

			return sbires; /*Renvoi de la structure dont on a modifié la position*/

		}


		printf("Aller en bas ?\n(Y/N) : "); /*Déroulement pour la direction verticale basse*/
		scanf("%s", dir);

		/*Comptage des cases praticables en haut du sbire*/
		if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "n") == 0) || (strcmp(dir, "N") == 0) ) {	
			printf("Vertical bas : ");

			for(n = 1 ; (mat[(sbires.position[0] + n)][sbires.position[1]] == 0) && (nbr_cases < nb_dep) ; n++){

				if( ((sbires.position[0] + nbr_cases) < N) && (sbires.position[0] < N)){ /*Prise en compte des bords de la matrice*/

					nbr_cases++;

				}

			}

			printf("%i cases praticables\n", nbr_cases);

			/*Prise en compte de l'impossibilité du déplacement dans la direction souhaitée*/
			if( nbr_cases == 0 ) {

				printf("Tu vas droit dans le mur ^^\n");
				sbires = Deplacer_Pion(sbires, mat, direction, nb_dep); /*Repéte la fonction avec la même direction*/

			} else {

				printf("Nbr cases à parcourir : ");
				scanf("%i", &nbr_cap);

				while(nbr_cap > nbr_cases){/*Prise en compte du dépassement des déplacments autorisés*/

					printf("Dépassement du nombre de cases praticables. Recommencez :\nNbr case à parcourir : ");
					scanf("%i", &nbr_cap);

				}

				/*Mise à jour de la matrice et de la position du sbire*/
				mat[sbires.position[0]][sbires.position[1]] = 0;
				sbires.position[0] = sbires.position[0] + nbr_cap;
				mat[sbires.position[0]][sbires.position[1]] = 1;
				nbr_cases = nbr_cases - nbr_cap;

				/*Prise en compte des déplacements restants ci-dessous*/
				if( (nb_dep - nbr_cases > 0) && (nbr_cases > 0) ){

					printf("%i déplacements encore possibles, voulez-vous continuer ?\n\t(Retour en arrière IMPOSSIBLE)\n(Y/N) : ", (nb_dep - nbr_cases));
					scanf("%s", dir);

					if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "n") == 0) || (strcmp(dir, "N") == 0) ) {

						printf("Même direction (H ou B) ?\n(Y/N) : "); /*Possibilité de continuer à l'horizontale ou d'aller à la verticale*/
						scanf("%s", dir);

						if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "n") == 0) || (strcmp(dir, "N") == 0) ) {

							sbires = Deplacer_Pion(sbires, mat, direction, (nb_dep - nbr_cap) ); /*Repéte la fonction avec la même direction*/

						} else {

							sbires = Deplacer_Pion(sbires, mat, (direction - 1), (nb_dep - nbr_cap) ); /*Repéte la fonction avec un changement de direction (Horizontale)*/

						}

					}

				}

			}

			return sbires; /*Renvoi de la structure dont on a modifié la position*/

		}

		printf("Changer de direction ?\n(Y/N) : "); /*Si il y a eu erreur de frappe ou changement d'avis, plus haut, on donne la possibilitée au joueur de changer sa direction de déplacement*/
		scanf("%s", dir);

		if( (strcmp(dir, "Y") == 0) || (strcmp(dir, "y") == 0) || (strcmp(dir, "n") == 0) || (strcmp(dir, "N") == 0) ) {

			sbires = Deplacer_Pion(sbires, mat, (direction - 1), nb_dep ); /*Repéte la fonction avec un changement de direction (Horizontale)*/
			return sbires;

		} else {
			
			sbires = Deplacer_Pion(sbires, mat, direction, nb_dep); /*Repéte la fonction avec la même direction*/
			return sbires;
		}
	}

}

/**
*\brief Attaquer une cible avec une attaque automatique.
*\details Calculer les dégâts qu'emmétra le pion en fonction de la défense et de l'esquive de la cible.
*\param sbires_t sbire La structure du pion courant.
*\param sbires_t cible La structure de la cible.
*/
sbires_t Combat_physique(sbires_t sbire, sbires_t cible){
/*Fonction de calcul des dégâts physiques infligés*/

	int degats;
	printf("%s attaque %s\n", sbire.nom, cible.nom);
	degats = ( sbire.attaque - (cible.defense));
	if(degats < 0){
		degats = 0;
	}
	if( (rand()%(10 - 1) + 1) > cible.defense ){ 
		if( (rand()%(10 - 1) + 1) > cible.esquive ){ 
			cible.vie = cible.vie - degats;
			if(cible.vie < 0){
				cible.vie = 0;
			}
			printf("%s reçoit %i dégats\n", cible.nom, degats);
			printf("Il reste %i PVs à %s\n", cible.vie, cible.nom);
		} else printf("%s a esquivé !\n", cible.nom); 
	} else printf("%s a bloqué  !\n", cible.nom);
		
	
	return cible; /*Renvoi de la structure modifiée par la fonction*/
}

/**
*\brief Attaquer une cible avec une attaque magique.
*\details Calculer les dégâts qu'emmétra le pion en fonction de la défense et de l'esquive de la cible.
*\param sbires_t sbire La structure du pion courant.
*\param sbires_t cible La structure de la cible.
*/
sbires_t Combat_magique(sbires_t sbire, sbires_t cible){
/*Fonction de calcul des dégâts magiques infligés*/

	int degats;
	printf("%s attaque %s\n", sbire.nom, cible.nom);
	degats = ( ( sbire.attaque*(sbire.mana/2) ) )/10;
	if(degats < 0){
		degats = 0;
	}
	if( (rand()%(10 - 1) + 1) > cible.esquive ){ 
		cible.vie = cible.vie - degats;
		printf("%s reçoit %i dégats magiques\n", cible.nom, degats);
		if(cible.vie < 0){
			cible.vie = 0;
		}
		printf("Il reste %i PVs à %s\n", cible.vie, cible.nom);
	} else {
		printf("%s a esquivé !\n", cible.nom);
	}
	return cible; /*Renvoi de la structure modifiée par la fonction*/
}

/**
*\brief Calculer si une cible est à porter du pion.
*\details Fonction pour calculer si une cible est à porter d'attaque du pion courant.
*\param sbires_t sbire La structure du pion courant.
*\param sbires_t cible La structure de la cible.
*/
int Portee (sbires_t sbire, sbires_t cible){
/*Fonction indiquant si un ennemi est à portée du sbire*/

	if( ( (sbire.position[0] - 1) >= 0 ) && ( (sbire.position[0] + 1) < N ) ) { /*Prise en compte des bords de la matrice - Vérification verticale*/

		if ( ((sbire.position[0] + 1) != cible.position[0]) && ((sbire.position[0] - 1) != cible.position[0]) ){/*Vérification que la cible est à côté du sbire*/

			if( ((sbire.position[1] - 1) >= 0) && ((sbire.position[1] + 1) < N) ) { /*Prise en compte des bords de la matrice - Vérification horizontale*/

				if( ( (sbire.position[1] + 1) == cible.position[1] ) || ( (sbire.position[1] - 1) == cible.position[1] ) ){/*Vérification que la cible est à côté du sbire*/

					return 1; /*Renvoi une valeur VRAI*/

				} else {

					return 0; /*Renvoi une valeur FAUX*/

				}

			} else {

				return 0; /*Renvoi une valeur FAUX*/

			}

		} else {

			return 1; /*Renvoi une valeur VRAI*/
		}

	} else if( ((sbire.position[1] - 1) >= 0) && ((sbire.position[1] + 1) < N) ) { /*Prise en compte des bords de la matrice - Vérification horizontale*/

		if( ( (sbire.position[1] + 1) == cible.position[1] ) || ( (sbire.position[1] - 1) == cible.position[1] ) ){/*Vérification que la cible est à côté du sbire*/

			return 1; /*Renvoi une valeur VRAI*/

		} else {

			return 0; /*Renvoi une valeur FAUX*/

		}

	}

}

/**
*\brief Séléctionner l'attaque.
*\details Sélectionner l'attaque qu'effectuera le pion courant sur sa cible.
*\param sbires_t sbire La structure du pion courant.
*\param sbires_t cible La structure de la cible.
*/
sbires_t Selection_Attaque(sbires_t sbire, sbires_t cible){
/*Fonction de sélection du type d'Attaque*/

	int choix = 0;
	int flag_P;

	printf("%s passe à l'attaque\n", sbire.nom);
	printf("Type d'attaque ?\n");
	printf("1 : Attaque normale\n");
	printf("2 : Attaque magique\n");
	printf("3 : Annuler attaque\n");

	while ( choix == 0 ){
		scanf("%i", &choix);
		switch(choix){

		case 1 : printf("Attaque = %i\n", sbire.attaque);
			flag_P = Portee(sbire, cible); /*Vérifie que la cible est à portée de l'attaque*/
			if(flag_P == 1){
				cible = Combat_physique(sbire, cible); /*Inflige des dégâts en utilisant sa statistique d'attaque*/
			} else {
			printf("La cible est trop loin !\nEssayez une attaque à distance plutôt...\n");
			choix = 0;
			}			
			break;

		case 2 : printf("Mana = %i\n", sbire.mana);
			cible = Combat_magique(sbire, cible); /*Inflige des dégâts en utilisant sa statistique de mana*/
			break;

		case 3 : printf("Attaque annulée\n");
			break;
		default : printf("Cette commande n'existe pas\n");
			choix = 0;
			break;
		}
	}
	return cible; /*Renvoi la structure modifiée par l'attaque*/

}

/**
*\brief Séléctionner la direction pour ce déplacer.
*\details Sélectionner a direction pour permettre au pion de se d"placer.
*\param sbires_t sbire La structure du pion courant.
*\param int mat[N][N] La matrice d'affichage.
*/
sbires_t Selection_Deplacement(sbires_t sbires, int mat[N][N]){
/*Fonction de sélection de la direction de déplacement*/

	int choix = 0;
	printf("\nDistance maximale de déplacement de l'unité %s \n", sbires.nom);
	printf("%i cases maximum.\n", sbires.nbr_depl);
	printf("Position : Case %i | %i\n", (sbires.position[0] + 1), (sbires.position[1] + 1));
	printf("\nDéplacements vertical ou horizontal ?\n");
	printf("1 : Horizontal\n2 : Vertical\n3 : Annuler Déplacement\n");
	
	while( (choix <= 0) || (choix > 3) ){ /*Boucle tant que l'on choisi ni de se déplacer, ni de revenir en arrière*/

		printf("Choix : ");
		scanf("%i", &choix);
	
		switch(choix){

			case 1 : 
				printf("Déplacement horizontal\n");
				sbires = Deplacer_Pion(sbires, mat, choix, sbires.nbr_depl); /*Cause un déplacement horizontal - Voir plus haut*/
				break;

			case 2 : 
				printf("Déplacement vertical\n");
				sbires = Deplacer_Pion(sbires, mat, choix, sbires.nbr_depl); /*Cause un déplacement vertical - Voir plus haut*/
				break;

			case 3 : 
				printf("Déplacement annulé\n");
				break;

			default : 
				printf("Ce choix n'existe pas !\n");

		}

	}

	return sbires;

}

/**
*\brief Séléctionner l'action du pion.
*\details Sélectionner l'action que le pion devra effectuer en fonction des choix possibles.
*\param sbires_t sbire La structure du pion courant.
*\param int mat[N][N] La matrice d'affichage.
*/
sbires_t Action(sbires_t sbires, int mat[N][N]){
/*Actions possibles de l'unité : Défense , Inventaire et Annulation de l'Action*/

	int choix_action = 0;
	int nbr_ennemi = 0;
	
	printf("\nChoississez l'action de votre unité :\n");
	printf("1 : Voir inventaire\n");
	printf("2 : Observer le terrain\n");
	printf("3 : Annuler\n");
	
	while( (choix_action != 4) && (choix_action != 1) && (choix_action != 2) ){ /*Boucle tant que l'on ne choisi pas de se défendre, utiliser son inventaire ou de revenir aux choix précédents*/
		printf("Choix : ");
		scanf("%i", &choix_action);
	
		switch(choix_action){

			case 1 : printf("Inventaire\n");
				inventaire(sbires);
				break;

			case 2 : printf("%s observe les environs\n", sbires.nom);
				nbr_ennemi = Detection_Cible(sbires, 1, mat, nbr_ennemi); /*Compte le nombre total d'ennemis aux alentours*/

				if(nbr_ennemi > 0){

					printf("Il y a %i ennemi(s) dans les environs\n", nbr_ennemi);

				} else {

					printf("Rien à signaler\n");

				}
				break;

			case 3 : break; /*Cas de sortie par annulation*/

			default : printf("ça va pas marcher comme ça...\n");

		}

	}

	return sbires;

}
