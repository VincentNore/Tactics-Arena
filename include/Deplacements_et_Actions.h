#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"structures.h"

#define N 11

int Detection_Cible (sbires_t sbire, int direction, int mat[N][N], int ennemi);

int Detection_Portee (sbires_t sbire, int direction, int mat[N][N], int ennemi);

sbires_t Deplacer_Pion(sbires_t sbires, int mat[N][N], int direction, int nb_dep);

sbires_t Combat_physique(sbires_t sbire, sbires_t cible);

sbires_t Combat_magique(sbires_t sbire, sbires_t cible);

int Portee (sbires_t sbire, sbires_t cible);

sbires_t Selection_Attaque(sbires_t sbire, sbires_t cible);

sbires_t Selection_Deplacement(sbires_t sbires, int mat[N][N]);

sbires_t Action(sbires_t sbires, int mat[N][N]);

int menu(sbires_t sbire);
