#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"../include/structures.h"

/**
*\file structures.c
*\author Colin Kevin
*\date 6 avril 2018
*\version 1.0
*\brief Fonctions permettant certaines actions du joueur.
*
*\details Fonctions pour les actions du pion courant.
*
*/

/**
*\brief Détecter si un pion est vivant.
*\details Vérifier si un pion est toujours en vie sinon il est détruit et le joueur pert un pion.
*\param sbires_t sbire La structure du pion courant.
*\param armee_t armee_j1 Contient les pions du joueur 1.
*\param armee_t armee_j2 Contient les pions du joueur 2.
*\param int nb_pions_j1 Le nombre de pions du joueur 1.
*\param int nb_pions_j2 Le nombre de pions du joueur 2.
*/
int detection_mort(sbires_t sbire, armee_t armee_j1, armee_t armee_j2, int nb_pions_j1, int nb_pions_j2){
	if(armee_j1.A.vie == 0){
		printf("%s est mort\n", sbire.nom);
		sbire.symbole = "  ";
		nb_pions_j1--;
		return (nb_pions_j1);
			
	}
	else if(armee_j1.B.vie == 0){
		printf("%s est mort\n", sbire.nom);
		sbire.symbole = "  ";
		nb_pions_j1--;
		return (nb_pions_j1);
			
	}
	else if(armee_j1.C.vie == 0){
		printf("%s est mort\n", sbire.nom);
		sbire.symbole = "  ";
		nb_pions_j1--;
		return (nb_pions_j1);
			
	}
	else if(armee_j1.D.vie == 0){
		printf("%s est mort\n", sbire.nom);
		sbire.symbole = "  ";
		nb_pions_j1--;
		return (nb_pions_j1);
			
	}
	else if(armee_j1.E.vie == 0){
		printf("%s est mort\n", sbire.nom);
		sbire.symbole = "  ";
		nb_pions_j1--;
		return (nb_pions_j1);
			
	}
	else if(armee_j2.A.vie == 0){
		printf("%s est mort\n", sbire.nom);
		sbire.symbole = "  ";
		nb_pions_j2--;
		return (nb_pions_j2);
			
	}
	else if(armee_j2.B.vie == 0){
		printf("%s est mort\n", sbire.nom);
		sbire.symbole = "  ";
		nb_pions_j2--;
		return (nb_pions_j2);
			
	}
	else if(armee_j2.C.vie == 0){
		printf("%s est mort\n", sbire.nom);
		sbire.symbole = "  ";
		nb_pions_j2--;
		return (nb_pions_j2);
			
	}
	else if(armee_j2.D.vie == 0){
		printf("%s est mort\n", sbire.nom);
		sbire.symbole = "  ";
		nb_pions_j2--;
		return (nb_pions_j2);
			
	}
	else if(armee_j2.E.vie == 0){
		printf("%s est mort\n", sbire.nom);
		sbire.symbole = "  ";
		nb_pions_j2--;
		return (nb_pions_j2);
			
	}
	else{
		return 0;
	}
}

/**
*\brief Inventaire du joueur.
*\details Permettre aux joueurs d'utiliser des objets dans un inventaire pour soigner ou rajouter des points de magie aux pions.
*\param sbires_t sbire La structure du pion courant.
*/
sbires_t inventaire(sbires_t sbire){
	int potion_soins =5;
	int nb_gemme = 5;
	int inventaire;
	printf("\t choissisez un objet dans l'inventaire :\n"); 
	printf("\t 0:potion de soins | 1:gemme de mana :\n");
	scanf("%d",&inventaire);

	switch(inventaire)
	 { 
		 case 0 :if(potion_soins > 0){
						if (sbire.vie > 0){ 
							sbire.vie += 10;
				   			if(sbire.vie > 10){
				   				sbire.vie = 10;
				   				potion_soins = potion_soins -1;
				   				printf("\t potion_de_soin à été utilisée,il vous en reste %i\n",potion_soins);
							}
				  		}
						else {
							printf("\t Le sbire %s est mort, action impossible\n", sbire.nom);
							break;
						}
				}
				else {
					printf("\t Vous n'avez plus de potion de soins !\n");
					break;
				}
				
		 case 1 :if (nb_gemme > 0){
			   		if(sbire.mana > 0){ 
			    		sbire.mana += 10;
			   			if(sbire.mana > 10){
			   				sbire.mana = 10; 
			     			nb_gemme = nb_gemme -1;
			     			printf("\t Gemme à été utilisée, il vous en reste %i\n",nb_gemme);
			     		}
			 		}
					else {
						printf("\t le sbire est mort, action impossible\n");
						break;
					}
				}
				else {
				printf("\t Vous n'avez plus de gemme de mana !\n");
				break;
				}

		 default:printf("ERROR\n");
	}
	return(sbire); 
}

/**
*\brief Compétences spéciales des pions.
*\details Les pions peuvent utiliser des compétences spéciales pour effectuer plus de dégâts sur l'ennemi.
*\param sbires_t sbire La structure du pion courant.
*\param sbires_t cible La structure de la cible.
*/
sbires_t competences(sbires_t sbire, sbires_t cible){
		int competences;
		printf("\t Choissisez une compétence à utiliser :\n"); 
		printf("\t 0 - attaque automatique | 1 - dragon punch :\n");
		scanf("%d",&competences);
		switch(competences){ 
		
		 case 0 : if (sbire.vie > 0){ 
		 			sbire.attaque = sbire.attaque +3;
			   		cible = Combat_physique(sbire,cible);
			    	sbire.attaque = 1;
			    
			       printf("\t attaque automatique utilisé\n");
				
			  	  }
				  else{ 
					printf("\t le sbire est mort, action impossible\n");		
					break;
				  }
	
		 case 1 : if (sbire.vie > 0){
			  		if (sbire.mana > 4){
			  			sbire.attaque = sbire.attaque + 40;
						cible = Combat_magique(sbire,cible);		
						sbire.mana = sbire.mana -4;
			   			sbire.attaque = sbire.attaque - 40;
			      		printf("\t dragon punch utilisé\n");
				 	}
					else{ 
						printf("\t le sbire manque de mana, action impossible\n");
						break;
					}
				  }
				  else {
				  	printf("\t le sbire est mort, action impossible\n");
					break;
					}
		 default:printf("ERROR\n");
	}
	return(cible); 
}

