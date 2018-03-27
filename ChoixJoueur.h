#ifndef CHOIX_JOUEUR
#define CHOIX_JOUEUR

typedef struct sbires sbires;
		struct sbires  /*uniétés de base */
		{
		char * nom;
		int  attaque;
		int  vie;
		int  defense;
		int  esquive; 
		int  mana;
}; 


sbires * ChoixUnite(int tour, sbires * sbire_rouge, sbires * sbire_bleu); /*Fonction de selection unité par tour */

int DebutPartie(int tour); /*Fonction de lancement Partie */


#endif