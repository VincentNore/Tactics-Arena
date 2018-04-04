#include<stdio.h>
#include<stdlib.h>

/**
*\file structures.h
*\author Colin Kevin
*\date 6 avril 2018
*\version 1.0
*\brief Structures et prototypes.
*
*\details Définition de la structure sbires et armee ainsi que des prototypes des fonctions de structures.c.
*
*/

/**
*\brief Caractéristiques du pion.
\details La structure qui contient les caractéristiques du pion.
*/
typedef struct sbires{
	char * nom;			/*!< nom du pion */
	char * symbole;		/*!< symbole du pion */
	int attaque;		/*!< points d'attaque du pion */
	int vie;			/*!< points de vie du pion */
	int defense;		/*!< défense du pion */
	int esquive;		/*!< esquive du pion */
	int mana;			/*!< points de magie du pion */
	int nbr_depl;		/*!< nombre de déplacement possible du pion */
	int position[2];	/*!< position sur la matrice du pion */
}sbires_t; 

/**
*\brief Armées des joueurs.
\details La structure armée qui contient les pions des joueurs.
*/
typedef struct armee_s{
		sbires_t A;		/*!< Pion numéro 1 */
		sbires_t B;		/*!< Pion numéro 2 */
		sbires_t C;		/*!< Pion numéro 3 */
		sbires_t D;		/*!< Pion numéro 4 */
		sbires_t E;		/*!< Pion numéro 5 */
}armee_t;

sbires_t inventaire(sbires_t sbire);
sbires_t competences(sbires_t sbire, sbires_t cible);
sbires_t Combat_physique(sbires_t sbire, sbires_t cible);
sbires_t Combat_magique(sbires_t sbire, sbires_t cible);
int detection_mort(sbires_t sbire, armee_t armee_j1, armee_t armee_j2, int nb_pions_j1, int nb_pions_j2);
