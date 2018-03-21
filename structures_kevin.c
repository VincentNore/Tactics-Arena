
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"structures_kevin.h"

sbires * inventaire(sbires * sbire_bleu){
	int potion_soins =5;
	int nb_gemme = 5;
	int inventaire;
	printf("\t choissisez un objet dans l'inventaire :\n"); 
	printf("\t 0:potion de soins | 1:gemme de mana :\n");
	scanf("%d",&inventaire);

	switch(inventaire)

	 { 
		 case 0 :if(potion_soins >0){
				if (sbire_bleu->vie > 0)
				  { sbire_bleu->vie += 10;
				   if(sbire_bleu->vie > 10)sbire_bleu->vie = 10;
				   	potion_soins = potion_soins -1;
				   	printf("\t potion_de_soin à été utilisée,il vous en reste %i\n",potion_soins);
				
				  }
				else printf("\t le sbire est mort, action impossible\n");break;
			}else printf("\t Vous n'avez plus de potion de soins !\n");break;
		 case 1 :if (potion_soins >0){
			   if(sbire_bleu->vie > 0){ 
			    sbire_bleu->mana += 10;
			   if(sbire_bleu->mana > 10)sbire_bleu->mana = 10; 
			     nb_gemme = nb_gemme -1;
			     printf("\t gemme à été utilisée, il vous en reste %i\n",nb_gemme);
			  }
			else printf("\t le sbire est mort, action impossible\n");break;
		}else printf("\t Vous n'avez plus de gemme de mana !\n");break;

		 default:printf("ERROR\n");
	}
	return(sbire_bleu); 
}

	sbires * competences(sbires * sbire_bleu,sbires * sbire_rouge){
		int competences;
		printf("\t choissisez une compétence à utiliser :\n"); 
		printf("\t 0:attaque automatique | 1:dragon punch :\n");
		scanf("%d",&competences);
		switch(competences)

	 { 
		 case 0 : if (sbire_bleu->vie > 0)
			  { sbire_bleu->attaque = sbire_bleu->attaque +3;
			   sbire_rouge = Combat_physique(sbire_bleu,sbire_rouge);
			    sbire_bleu->attaque = 1;
			    return(sbire_rouge);
			       printf("\t attaque automatique utilisé\n");
				
			  }
			else printf("\t le sbire est mort, action impossible\n");break;
	
		 case 1 : if (sbire_bleu->vie > 0){
			  	if (sbire_bleu->mana > 4){
					{ sbire_bleu->attaque = sbire_bleu->attaque + 40;
			    		
					sbire_rouge = Combat_magique(sbire_bleu,sbire_rouge);		
					sbire_bleu->mana = sbire_bleu->mana -4;
			   		sbire_bleu->attaque = sbire_bleu->attaque - 40;
					
			      		 printf("\t dragon punch utilisé\n");
				 }
				}else printf("\t le sbire manque de mana, action impossible\n");break;
			  
			}else printf("\t le sbire est mort, action impossible\n");break;
		 default:printf("ERROR\n");
	}
	return(sbire_bleu,sbire_rouge); 
}


sbires * Combat_physique(sbires * sbire_bleu, sbires *sbire_rouge){
	int degats;
	printf("%s attaque %s\n", sbire_bleu->nom, sbire_rouge->nom);
	degats = ( sbire_bleu->attaque - (sbire_rouge->defense));
	if(degats < 0){
		degats = 0;
	}
	if( (rand()%(10 - 1) + 1) > sbire_rouge->defense ){ 
		if( (rand()%(10 - 1) + 1) > sbire_rouge->esquive ){ 
			sbire_rouge->vie = sbire_rouge->vie - degats;
			if(sbire_rouge->vie < 0){
				sbire_rouge->vie = 0;
			}
			printf("%s reçoit %i dégats\n", sbire_rouge->nom, degats);
			printf("Il reste %i PVs à %s\n", sbire_rouge->vie, sbire_rouge->nom);
		} else printf("%s a esquivé !\n", sbire_rouge->nom); 
	} else printf("%s a bloqué  !\n", sbire_rouge->nom);
		
	
	return sbire_rouge;
}



sbires * Combat_magique(sbires * sbire_bleu, sbires * sbire_rouge){
	int degats;
	printf("%s attaque %s\n", sbire_bleu->nom, sbire_rouge->nom);
	degats = ( ( sbire_bleu->attaque*(sbire_bleu->mana/2) ) )/10;
	if(degats < 0){
		degats = 0;
	}
	if( (rand()%(10 - 1) + 1) > sbire_rouge->esquive ){ 
		sbire_rouge->vie = sbire_rouge->vie - degats;
		printf("%s reçoit %i dégats magiques\n", sbire_rouge->nom, degats);
		if(sbire_rouge->vie < 0){
			sbire_rouge->vie = 0;
		}
		printf("Il reste %i PVs à %s\n", sbire_rouge->vie, sbire_rouge->nom);
	} else {
		printf("%s a esquivé !\n", sbire_rouge->nom);
	}
	return sbire_rouge;
}



void structures(sbires * sbire_bleu, sbires * sbire_rouge)
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
}

/* A FAIRE : Lier la detection_mort à la selection des unitées pour pouvoir liberer les structures morts et gagner de la mémoire.
sbires * detection_mort(sbires * sbire_bleu, sbires * sbire_rouge){
	if(sbire_rouge->vie == 0){
		printf("%s est mort\n", sbire_rouge->nom);
		free(sbire_rouge);
		sbire_rouge = NULL;
		
	}
}
*/

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
sbire_bleu,sbire_rouge = competences(sbire_bleu,sbire_rouge);
structures(sbire_bleu,sbire_rouge);
}
