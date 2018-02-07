
#include<stdio.h>
#include<stdlib.h>

	typedef struct sbires sbires; /*uniétés de base */
		struct sbires
		{
		char * nom;
		int attaque;
		int vie;
		int defense;
		int esquive; 
		int mana;
		}; 

int main(void)
{
	int inventaire;
	sbires sbire_bleu;
	sbires sbire_rouge;

		sbire_bleu.nom = "lul";
		sbire_bleu.attaque = 2;
		sbire_bleu.vie = 1;
		sbire_bleu.defense = 10;
		sbire_bleu.esquive = 10;
		sbire_bleu.mana = 1;	

	printf("l'attaque du sbire bleu est donc de %d.\n",sbire_bleu.attaque);
	printf("la vie du sbire bleu est donc de %d.\n",sbire_bleu.vie);
	printf("la défense du sbire bleu est donc de %d.\n",sbire_bleu.defense);
	printf("l'esquive du sbire bleu est donc de %d.\n",sbire_bleu.esquive);
	printf("le nom du sbire bleu est donc %s.\n",sbire_bleu.nom);
	
	printf("la mana du sbire bleu est donc %d.\n",sbire_bleu.mana);

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
	
	/*printf("Entrez un nom pour le sbire des bleus: \n");
	scanf("%s",sbire_bleu.nom);  
	
	printf("Entrez un nom pour le sbire des rouges: \n");
	scanf("%s",sbire_rouge.nom);  */	
	
	/*printf("dans l'inventaire du sbire bleu il y a %s\n",gemme);
	printf("dans l'inventaire du sbire bleu il y a %d\n",potion_de_soin);*/

	printf("l'attaque du sbire bleu est donc de %d.\n",sbire_bleu.attaque);
	printf("la vie du sbire bleu est donc de %d.\n",sbire_bleu.vie);
	printf("la défense du sbire bleu est donc de %d.\n",sbire_bleu.defense);
	printf("l'esquivedu sbire bleu est donc de %d.\n",sbire_bleu.esquive);
	printf("le nom du sbire bleu est donc %s.\n",sbire_bleu.nom);
	printf("la mana du sbire bleu est donc %d.\n",sbire_bleu.mana);
	
	return(0);
}
