

#include<stdio.h>
#include<stdlib.h>
#include"test.h"

sbires inventaire(sbires sbire_bleu){
	
	int inventaire;
	printf("\t choissisez un objet dans l'inventaire :\n"); 

	scanf("%d",&inventaire);

	switch(inventaire)

	 { 
		 case 0 :if (sbire_bleu.vie > 0)
			  { sbire_bleu.vie += 10;
			   if(sbire_bleu.vie > 10)sbire_bleu.vie = 10;
			   
			    printf("\t potion_de_soin à été utilisée\n");
				
			  }
			else printf("\t le sbire est mort, action impossible\n");break;

		 case 1 :if (sbire_bleu.vie > 0)
			  { sbire_bleu.mana += 10;
			   if(sbire_bleu.mana > 10)sbire_bleu.mana = 10; 
			
			    printf("\t gemme à été utilisée\n");
			  }
			else printf("\t le sbire est mort, action impossible\n");break;

		 default:printf("ERROR\n");
	}
	return(sbire_bleu); 
}

	sbires competences(sbires sbire_bleu){
		int competences;
		
		printf("\t choissisez une compétence à utiliser :\n"); 
		scanf("%d",&competences);
		
		switch(competences)

	 { 
		 case 0 : if (sbire_bleu.vie > 0)
			  { sbire_bleu.attaque = 3;
			   
			       printf("\t attaque auto utilisé\n");
				
			  }
			else printf("\t le sbire est mort, action impossible\n");break;
	
		 case 1 : if (sbire_bleu.vie > 0){
			  	if (sbire_bleu.mana > 4){
					{ sbire_bleu.attaque = 8;
			    		sbire_bleu.mana = sbire_bleu.mana -3;
			   
			      		 printf("\t dragon punch utilisé\n");
				 }
				}else printf("\t le sbire manque de mana, action impossible\n");break;
			  
			}else printf("\t le sbire est mort, action impossible\n");break;
		 default:printf("ERROR\n");
	}
	return(sbire_bleu); 
}

void structures(sbires sbire_bleu)
{
	printf("l'attaque du sbire bleu est donc de %d.\n",sbire_bleu.attaque);
	printf("la vie du sbire bleu est donc de %d.\n",sbire_bleu.vie);
	printf("la défense du sbire bleu est donc de %d.\n",sbire_bleu.defense);
	printf("l'esquive du sbire bleu est donc de %d.\n",sbire_bleu.esquive);
	printf("le nom du sbire bleu est donc %s.\n",sbire_bleu.nom);
	printf("la mana du sbire bleu est donc %d.\n",sbire_bleu.mana);
	
}


int main(){
	sbires sbire_bleu;
	
	sbire_bleu.nom = "lol";
	sbire_bleu.attaque = 1;
	sbire_bleu.vie= 1;
	sbire_bleu.defense= 1;
	sbire_bleu.esquive= 1;
	sbire_bleu.mana= 1;	

structures(sbire_bleu);
sbire_bleu = inventaire(sbire_bleu);
sbire_bleu =competences(sbire_bleu);
structures(sbire_bleu);
}

