#include<stdio.h>
#include<stdlib.h>


	typedef struct sbires sbires; /*uniétés de base */
		struct sbires
		{
		char nom[20];
		int attaque;
		int vie;
		int defense;
		int esquive;
		int inventaire; 
		}; 
	typedef enum inventaire inventaire;
           enum inventaire
      	  { potion_de_soin ,gemme ,bandage ,antidote};

	/*struct heros unités avancées
		char nom[20];
		int attaque = 10;
		int vie = 10;
		int défense = 10;
		int esquive = 10;
		int inventaire = NULL;	 
		} heros_bleu,heros_rouge;
	
	struct esprits-héroiques unités très avancées
		char nom[20];
		int attaque = 20;
		int vie = 20;
		int défense = 20;
		int esquive = 20;
		int inventaire = NULL;	 
		} esprits-héroiques_bleu,esprits-héroiques_rouge;*/

int init_struct(void)
{
	 sbires sbire_bleu;
	 sbires sbire_rouge;
	
	/*printf("Entrez un nom pour le sbire des bleus: \n");
	scanf("%s",sbire_bleu.nom);  
	
	printf("Entrez un nom pour le sbire des rouges: \n");
	scanf("%s",sbire_rouge.nom);  */
		sbire_bleu.nom[20] = 'a';
		sbire_bleu.attaque = 2;
		sbire_bleu.vie = 10;
		sbire_bleu.defense = 10;
		sbire_bleu.esquive = 10;
		sbire_bleu.inventaire = NULL;	
	
	printf("l'attaque du sbire bleu est donc de %d.\n",sbire_bleu.attaque);
	printf("l'attaque du sbire bleu est donc de %d.\n",sbire_bleu.vie);
	printf("l'attaque du sbire bleu est donc de %d.\n",sbire_bleu.defense);
	printf("l'attaque du sbire bleu est donc de %d.\n",sbire_bleu.esquive);
	printf("l'attaque du sbire bleu est donc de %d.\n",sbire_bleu.inventaire);
	printf("le nom du sbire bleu est donc %s.\n",sbire_bleu.nom);
	

	return(0);
}
