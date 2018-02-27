
#include<stdio.h>
#include<stdlib.h>

	typedef struct sbires sbires; /*uniétés de base */
		struct sbires
		{
		char * nom;
		int  attaque;
		int  vie;
		int  defense;
		int  esquive; 
		int  mana;
		}; 

void structures(sbires sbires_bleux);
sbires inventaire(sbires sbires_bleux);

