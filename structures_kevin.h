
#include<stdio.h>
#include<stdlib.h>


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

void structures(sbires * sbire_bleu, sbires * sbire_rouge);
sbires * inventaire(sbires * sbire_bleu);
sbires * competences(sbires * sbire_bleu,sbires * sbire_rouge);
sbires * Combat_physique(sbires * sbire_bleu, sbires * sbire_rouge);
sbires * Combat_magique(sbires * sbire_bleu, sbires * sbire_rouge);
sbires * competences2(sbires * sbire_bleu,sbires * sbire_rouge);
sbires * Combat_physique2(sbires * sbire_bleu, sbires * sbire_rouge);
sbires * Combat_magique2(sbires * sbire_bleu, sbires * sbire_rouge);
sbires * detection_mort(sbires * sbire_bleu, sbires * sbire_rouge);