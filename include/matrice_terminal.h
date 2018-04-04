#include<stdio.h>
#include<stdlib.h>

#define N 11

/**
*\file matrice_terminal.h
*\author Nore Vincent
*\date 6 avril 2018
*\version 1.0
*\brief Prototypes.
*
*\details Définition des prototypes des fonctions de matrice_terminal.c.
*
*/

void init_matrice(int mat[N][N]);

int afficher_matrice(int mat[N][N], armee_t armee_j1, armee_t armee_j2);

sbires_t positionner_sbire(sbires_t sbire, int mat[N][N]);

armee_t init_armee_j1(armee_t armee_j1, sbires_t sbire, int mat[N][N]);

armee_t init_armee_j2(armee_t armee_j2, sbires_t sbire, int mat[N][N]);

sbires_t init_sbire(sbires_t sbire, int mat[N][N]);
