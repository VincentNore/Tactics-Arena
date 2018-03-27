
Tactics: main.o structures_kevin.o ChoixJoueur.o 
	gcc -o Tactics main.o structures_kevin.o ChoixJoueur.o

ChoixJoueur.o: ChoixJoueur.c structures_kevin.h
	gcc -o ChoixJoueur.o -c ChoixJoueur.c -W -Wall -ansi -pedantic

structures_kevin.o:structures_kevin.c structures_kevin.h
	gcc -o structures_kevin.o -c structures_kevin.c -W -Wall -ansi -pedantic



main.o: main.c ChoixJoueur.h 
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic