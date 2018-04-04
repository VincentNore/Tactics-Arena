
Tactics: main.o structures.o ChoixJoueur.o matrice.o 
	gcc -o Tactics main.o structures.o ChoixJoueur.o

ChoixJoueur.o: ChoixJoueur.c 
	gcc -o ChoixJoueur.o -c ChoixJoueur.c -W -Wall -ansi -pedantic

structures.o:structures.c 
	gcc -o structures.o -c structures.c -W -Wall -ansi -pedantic

main.o: main.c couleur.h structures.h ChoixJoueur.h Deplacements_et_Actions.h matrice_terminal.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic
	
matrice.o: matrice_terminal.c 
	gcc -o matrice.o matrice_terminal.c
	
Deplacements_et_Actions.o: Deplacements_et_Actions.c
	gcc -o Deplacements_et_Actions.o -c Deplacements_et_Actions.c
	
Fonctions-D_et_A.o: Fonctions-D_et_A.c
	gcc -o Fonctions-D_et_A.o -c Fonctions-D_et_A.c

