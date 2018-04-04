#include<stdio.h>
#include<stdlib.h>

#define N 11

void init_matrice();

int afficher_matrice(int mat[N][N], armee_t armee_j1, armee_t armee_j2);

sbires_t positionner_sbire(sbires_t sbire, int mat[N][N]);

armee_t init_armee_j1(armee_t armee_j1, sbires_t sbire, int mat[N][N]);

armee_t init_armee_j2(armee_t armee_j2, sbires_t sbire, int mat[N][N]);

sbires_t init_sbire(sbires_t sbire, int mat[N][N]);
