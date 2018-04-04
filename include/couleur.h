#ifndef COULEURS
#define COULEURS

#include <stdio.h>

/**
*\file couleur.h
*\author Nore Vincent
*\date 6 avril 2018
*\version 1.0
*\brief Directive de préprocesseur.
*
*\details Directive de préprocesseur pour effacer l'écran et colorer le terminal dans matrice_terminal.c.
*
*/



#define clrscr() printf("\033[H\033[2J")

#define couleur(param) printf("\033[%sm",param)

#endif
