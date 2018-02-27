#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Compte_Cases(t_sbires sbires, char mat[][], int direction){ /*Fonction de comptage des cases*/
/*Compte les cases à la verticale (haut et bas) et à l'horizontale (gauche et droite)*/
// /!\A TESTER/!\

	int nbr_cases;
	
	switch (direction){
		case 1 : printf("Vertical haut : ");
			for(nbr_cases = 1 ; (mat[sbires.position[0]][sbires.position[1] + nbr_cases] == NULL) || (nbr_cases < sbires.nbr_depl); nbr_cases++);
			printf("%i cases praticables\n", nbr_cases);
	
			printf("Vertical bas : ")
			for(nbr_cases = 1 ; (mat[sbires.position[0]][sbires.position[1] - nbr_cases] == NULL) || (nbr_cases < sbires.nbr_depl); nbr_cases++);
			printf("%i cases praticables\n", nbr_cases);
			break;
		case 2 : printf("Horizontal gauche : ");
			for(nbr_cases = 1 ; (mat[sbires.position[0] - nbr_cases][sbires.position[1]] == NULL) || (nbr_cases < sbires.nbr_depl); nbr_cases++);
			printf("%i cases praticables\n", nbr_cases);
	
			printf("Horizontal droite : ")
			for(nbr_cases = 1 ; (mat[sbires.position[0] + nbr_cases][sbires.position[1]] == NULL) || (nbr_cases < sbires.nbr_depl); nbr_cases++);
			printf("%i cases praticables\n", nbr_cases);
			break;
		default : printf("Erreur de direction\n");
			break;
	}
	
	return nbr_cases;
}

t_sbires Combat_physique(t_sbires sbires1, t_sbires sbires2){
	int degats;
	printf("%s attaque %s\n", sbires1.nom, sbires2.nom);
	degats = ( sbires1.attaque - (sbires2.defense)/2 )/10;
	if(degats < 0){
		degats = 0;
	}
	if( (rand()%(100 - 1) + 1) > sbires2.esquive ){ 
		sbires2.vie = sbires2.vie - degats;
		if(sbires2.vie < 0){
			sbires2.vie = 0;
		}
		printf("%s reçoit %i dégats\n", sbires2.nom, degats);
		printf("Il reste %i PVs à %s\n", sbires2.vie, sbires2.nom);
	} else printf("%s a esquivé !\n", sbires2.nom);
	return sbires2;
}

t_sbires Combat_magique(t_sbires sbires1, t_sbires sbires2){
	int degats;
	printf("%s attaque %s\n", sbires1.nom, sbires2.nom);
	degats = ( ( sbires1.attaque*(sbires1.mana/2) ) - sbires2.defense )/10;
	if(degats < 0){
		degats = 0;
	}
	if( (rand()%(100 - 1) + 1) > sbires2.esquive ){ 
		sbires2.vie = sbires2.vie - degats;
		printf("%s reçoit %i dégats magiques\n", sbires2.nom, degats);
		if(sbires2.vie < 0){
			sbires2.vie = 0;
		}
		printf("Il reste %i PVs à %s\n", sbires2.vie, sbires2.nom);
	} else {
		printf("%s a esquivé !\n", sbires2.nom);
	}
	return sbires2;
}

void Deplacement(t_sbires sbires, char mat[][]){
/*Fonction de déplacement de l'unité : /!\ A COMPLETER /!\ */
	int choix = 0;
	int nbr_cases = 0;
	printf("\nDistance maximale de déplacement de l'unité %s \n", sbires.nom);
	printf("%i cases maximum.\n", sbires.nbr_depl);
	printf("Position : %i %i\n", *sbires.position[0], *sbires.position[1]);
	printf("Déplacements vertical ou horizontal ?\n");
	printf("1 : Vertical\n2 : Horizontal\n3 : Annuler Déplacement\nChoix : ");
	
	scanf("%i", &choix);
	
	switch(choix){
		case 1 : printf("Déplacement vertical\n");
			//nbr_cases = Compte_Cases(sbires, mat, choix);
			break;
		case 2 : printf("Déplacement horizontal\n");
			//nbr_cases = Compte_Cases(sbires, mat, choix);
			break;
		case 3 : printf("Déplacement annulé\n");
			break;
		default : printf("Déplacement annulé\n");
			break;
	}
	
}

t_sbires Action(t_sbires sbires, t_sbires cible){
/*Actions possibles de l'unité : Attaque (Normale ou Magique)
Défense , Inventaire et Annulation de l'Action*/

	int choix_action = 0;
	int choix_attaque = 0;
	
	while(choix_action != 4){
	
		printf("\nChoississez l'action de votre unité :\n");
		printf("1 : Attaque\n");
		printf("2 : Defense\n");
		printf("3 : Voir inventaire\n");
		printf("4 : Choisir une autre unité\n");
	
		scanf("%i", &choix_action);
	
		switch(choix_action){
			case 1 :
				printf("Quelle attaque ?\n");
				printf("1 : Attaque normale\n");
				printf("2 : Attaque magique\n");
				printf("3 : Annuler attaque\n");
				scanf("%i", &choix_attaque);
				switch(choix_attaque){
					case 1 : printf("Attaque = %i\n", sbires.attaque);
						cible = Combat_physique(sbires, cible);
						return cible;
				case 2 : printf("Mana = %i\n", sbires.mana);
					cible = Combat_magique(sbires, cible);
					return cible;
				case 3 : printf("Attaque annulée\n");
				default : printf("Attaque annulée\n");
				}
				if ( (choix_attaque != 1) && (choix_attaque != 2) ){
					choix_attaque = 0;
				}
			break;
			case 2 : printf("Defense = %i\nA BOSSER\n", sbires.defense);
				break;
			case 3 : printf("Inventaire\n");
				break;
			case 4 : printf("On va voir ailleurs\n");
				return cible;
			default : printf("ça va pas marcher comme ça...\n");
				break;
		}
	}
	return cible;
}

t_sbires Selection_Action(t_sbires sbires, t_sbires cible/*, char mat[][]*/){
/*Fonction de sélection : Déplacement ou Action de l'unité*/

	int choix = 0;
	printf("\nQue doit faire %s ?\n", sbires.nom);
		printf("1 : Se déplacer\n");
		printf("2 : Agir\n");
		printf("3 : Annuler\n"); /*A défaut d'avoir une autre façon de tester le programme*/
	
		scanf("%i", &choix);
	
	switch (choix) {
		case 1 : //Deplacement(sbires, mat[][]); /* /!\Insérez matrice ci-contre/!\ */
			printf("INCOMPLET\n");
			break;
		case 2 : cible = Action(sbires, cible);
			return cible;
		case 3 : printf("Action annulée\n");
			break;
		default : printf("Won't work\n");
			break;
	}
	return cible;
}