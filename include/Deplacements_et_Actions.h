#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/structures.h"

#define N 11

/**
*\file Deplacements_et_Actions.h
*\author Jolliet Corentin
*\date 6 avril 2018
*\version 1.0
*\brief Prototypes.
*
*\details Définition des prototypes des fonctions de Deplacements_et_Actions.c.
*
*/

int Detection_Cible (sbires_t sbire, int direction, int mat[N][N], int ennemi);

int Detection_Portee (sbires_t sbire, int direction, int mat[N][N], int ennemi);

sbires_t Deplacer_Pion(sbires_t sbires, int mat[N][N], int direction, int nb_dep);

sbires_t Combat_physique(sbires_t sbire, sbires_t cible);

sbires_t Combat_magique(sbires_t sbire, sbires_t cible);

int Portee (sbires_t sbire, sbires_t cible);

sbires_t Selection_Attaque(sbires_t sbire, sbires_t cible);

sbires_t Selection_Deplacement(sbires_t sbires, int mat[N][N]);

sbires_t Action(sbires_t sbires, int mat[N][N]);

int menu(sbires_t sbire, armee_t armee_j1, armee_t armee_j2, sbires_t cible, int mat[N][N]);
