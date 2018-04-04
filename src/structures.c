
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"structures.h"


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
}

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


/*void structures(sbires * sbire_bleu, sbires * sbire_rouge)
{
	printf("\n");
	printf("l'attaque du sbire bleu est donc de %d.\n",sbire_bleu->attaque);
	printf("la vie du sbire bleu est donc de %d.\n",sbire_bleu->vie);
	printf("la défense du sbire bleu est donc de %d.\n",sbire_bleu->defense);
	printf("l'esquive du sbire bleu est donc de %d.\n",sbire_bleu->esquive);
	printf("le nom du sbire bleu est donc %s.\n",sbire_bleu->nom);
	printf("la mana du sbire bleu est donc %d.\n",sbire_bleu->mana);
	
	printf("--------------------------------------------------------------\n");
	
	printf("\n");
	printf("l'attaque du sbire rouge est donc de %d.\n",sbire_rouge->attaque);
	printf("la vie du sbire rouge est donc de %d.\n",sbire_rouge->vie);
	printf("la défense du sbire rouge  est donc de %d.\n",sbire_rouge->defense);
	printf("l'esquive du sbire rouge est donc de %d.\n",sbire_rouge->esquive);
	printf("le nom du sbire rouge est donc %s.\n",sbire_rouge->nom);
	printf("la mana du sbire rouge est donc %d.\n",sbire_rouge->mana);
}/

/*A FAIRE : Lier la detection_mort à la selection des unitées pour pouvoir liberer les structures morts et gagner de la mémoire.
*/

/*
int main(){
srand(time(NULL));
	sbires * sbire_bleu;
	sbire_bleu = malloc(sizeof(sbires));
	
	sbire_bleu->nom = "lol_bleu";
	sbire_bleu->attaque = 5;
	sbire_bleu->vie= 5;
	sbire_bleu->defense= 4;
	sbire_bleu->esquive= 2;
	sbire_bleu->mana= 5;

	sbires * sbire_rouge;
	sbire_rouge = malloc(sizeof(sbires));

	sbire_rouge->nom = "lol_rouge";
	sbire_rouge->attaque = 1;
	sbire_rouge->vie= 8;
	sbire_rouge->defense= 2;
	sbire_rouge->esquive= 1;
	sbire_rouge->mana= 8;	

structures(sbire_bleu,sbire_rouge);
sbire_bleu = inventaire(sbire_bleu);
/*detection_mort(sbire_bleu,sbire_rouge);*/
/*
sbire_bleu,sbire_rouge = competences(sbire_bleu,sbire_rouge);
structures(sbire_bleu,sbire_rouge); 
} 
*/
