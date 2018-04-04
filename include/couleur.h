#ifndef COULEURS

#define COULEURS


#include <stdio.h>

//Directive de préprocesseur pour effacer l'écran;
#define clrscr() printf("\033[H\033[2J")

#define couleur(param) printf("\033[%sm",param)

#endif
