#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"ChoixJoueur.h"


int main(){
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

	 

	
	int tour;
	int fin =0;
	char rep[10];
	
	tour = DebutPartie(tour);
	
	while(fin != 1)
	{
			
		
		 ChoixUnite(tour,sbire_rouge,sbire_bleu);
		 if(sbire_bleu->vie == 0){
			printf("Joueur 2 à gagné \n");
			fin = 1;
		 }
		 if(sbire_rouge->vie == 0){
			printf("Joueur 1 à gagné \n");
			fin = 1;
		 }
		if(tour == 1)
			tour = 0;
		else
			tour = 1;		
		 
		
		 
		 
	}
	
	
	return 0;

}