
Tactics_Arena: main.o structures.o ChoixJoueur.o matrice_terminal.o Deplacements_et_Actions.o Fonctions-D_et_A.o
	gcc -o Tactics_arena main.o structures.o ChoixJoueur.o matrice_terminal.o Deplacements_et_Actions.o Fonctions-D_et_A.o

ChoixJoueur.o: src/ChoixJoueur.c 
	gcc -c src/ChoixJoueur.c

structures.o: src/structures.c 
	gcc -c src/structures.c

main.o: src/main.c include/couleur.h include/structures.h include/ChoixJoueur.h include/Deplacements_et_Actions.h include/matrice_terminal.h
	gcc -c src/main.c 
	
matrice_terminal.o: src/matrice_terminal.c
	gcc -c src/matrice_terminal.c
	
Deplacements_et_Actions.o: src/Deplacements_et_Actions.c
	gcc -c src/Deplacements_et_Actions.c
	
Fonctions-D_et_A.o: src/Fonctions-D_et_A.c
	gcc -c src/Fonctions-D_et_A.c

clean:
	rm -rf *.o
