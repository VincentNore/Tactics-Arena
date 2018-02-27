matrice: matrice_terminal.o deplacements_actions.o main.o
	gcc -o matrice matrice_terminal.o deplacements_actions.o main.o

matrice_terminal.o: matrice_terminal.c
	gcc -o matrice_terminal.o -c matrice_terminal.c

deplacements_actions.o: deplacements_actions.c
	gcc -c deplacements_actions.c

main.o: main.c matrice_terminal.h
	gcc -o main.o -c main.c
