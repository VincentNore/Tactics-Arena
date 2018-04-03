#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include "constantes.h"

void deplacerCaisse(int *premiereCase, int *secondeCase)

{

    if (*premiereCase == CAISSE || *premiereCase == CAISSE_OK)

    {

        if (*secondeCase == OBJECTIF)

            *secondeCase = CAISSE_OK;

        else

            *secondeCase = CAISSE;


        if (*premiereCase == CAISSE_OK)

            *premiereCase = OBJECTIF;

        else

            *premiereCase = VIDE;

    }

}

void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos, int direction)
{
    switch(direction)
    {
        case HAUT:
            if(pos->y-1 <0)
                break;
            if (carte[pos->x][pos->y - 1] == MUR)
                break;
            if ((carte[pos->x][pos->y - 1] == CAISSE || carte[pos->x][pos->y - 1] == CAISSE_OK) && (pos->y - 2 < 0 || carte[pos->x][pos->y - 2] == MUR || carte[pos->x][pos->y - 2] == CAISSE || carte[pos->x][pos->y - 2] == CAISSE_OK))
                break;
            deplacerCaisse(&carte[pos->x][pos->y - 1], &carte[pos->x][pos->y - 2]);
            pos->y--;
            break;

        case BAS:
            if(pos->y+1 > NB_BLOCS_HAUTEUR)
                break;
            if (carte[pos->x][pos->y + 1] == MUR)
                break;
            if ((carte[pos->x][pos->y + 1] == CAISSE || carte[pos->x][pos->y + 1] == CAISSE_OK) && (pos->y + 2 < 0 || carte[pos->x][pos->y + 2] == MUR || carte[pos->x][pos->y + 2] == CAISSE || carte[pos->x][pos->y + 2] == CAISSE_OK))
                break;
            deplacerCaisse(&carte[pos->x][pos->y + 1], &carte[pos->x][pos->y + 2]);
            pos->y++;
            break;

        case GAUCHE:
            if(pos->x-1 <0)
                break;
            if (carte[pos->x-1][pos->y] == MUR)
                break;
            if ((carte[pos->x-1][pos->y] == CAISSE || carte[pos->x-1][pos->y] == CAISSE_OK) && (pos->x - 2 < 0 || carte[pos->x-2][pos->y] == MUR || carte[pos->x-2][pos->y] == CAISSE || carte[pos->x-2][pos->y] == CAISSE_OK))
                break;
            deplacerCaisse(&carte[pos->x][pos->x - 1], &carte[pos->x][pos->x - 2]);
            pos->x--;
            break;

        case DROITE:
            if(pos->x+1 <0)
                break;
            if (carte[pos->x+1][pos->y] == MUR)
                break;
            if ((carte[pos->x+1][pos->y] == CAISSE || carte[pos->x+1][pos->y] == CAISSE_OK) && (pos->x + 2 < 0 || carte[pos->x+2][pos->y] == MUR || carte[pos->x+2][pos->y] == CAISSE || carte[pos->x+2][pos->y] == CAISSE_OK))
                break;
            deplacerCaisse(&carte[pos->x][pos->x + 1], &carte[pos->x][pos->x + 2]);
            pos->x++;
            break;






    }

}


void jouer(SDL_Surface* ecran)
{
    SDL_Surface *mario[4] = {NULL};
    SDL_Surface *mur = NULL, *caisse=NULL, *caisseOK=NULL, *objectif=NULL, *marioActuel=NULL;
    SDL_Rect position, positionJoueur;
    SDL_Event event;

    int continuer=1, objectifsRestants=0, i=0,j=0;
    int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR]={0};

    mur = IMG_Load("mur.jpg");
    caisse = IMG_Load("caisse.jpg");
    caisseOK = IMG_Load("caisse_ok.jpg");
    objectif = IMG_Load("objectif.jpg");
    mario[BAS] = IMG_Load("mario_bas.jpg");
    mario[GAUCHE] = IMG_Load("mario_gauche.jpg");
    mario[HAUT] = IMG_Load("mario_haut.jpg");
    mario[DROITE] = IMG_Load("mario_droite.jpg");
    marioActuel= mario[BAS];

    if(!chargerNiveau(carte))
        exit(EXIT_FAILURE);

    for(i=0;i<NB_BLOCS_LARGEUR;i++)
    {
        for(j=0;j<NB_BLOCS_HAUTEUR;j++)
        {
            if(carte[i][j]==MARIO)
            {
                positionJoueur.x=i;
                positionJoueur.y=j;
                carte[i][j]=VIDE;

            }

        }


    }

    SDL_EnableKeyRepeat(100,100);

    while(continuer)
    {
        switch(event.type)
        {
            case SDL_QUIT:
                continuer=0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer=0;
                        break;
                    case SDLK_UP:
                        marioActuel=mario[HAUT];
                        deplacerJoueur(carte, &positionJoueur, HAUT);
                        break;
                    case SDLK_DOWN:
                        marioActuel=mario[BAS];
                        deplacerJoueur(carte, &positionJoueur, BAS);
                        break;
                    case SDLK_RIGHT:
                        marioActuel=mario[DROITE];
                        deplacerJoueur(carte, &positionJoueur, DROITE);
                        break;
                    case SDLK_LEFT:
                        marioActuel=mario[GAUCHE];
                        deplacerJoueur(carte, &positionJoueur, GAUCHE);
                        break;
                }
                break;

        }
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));

        objectifsRestants=0;

        for(i=0;i<NB_BLOCS_LARGEUR;i++)
        {
            for(j=0;j<NB_BLOCS_HAUTEUR;j++)
            {
                position.x=i*TAILLE_BLOC;
                position.y=j*TAILLE_BLOC;

                switch(carte[i][j])
                {
                    case MUR:
                        SDL_BlitSurface(mur,NULL,ecran,&position);
                        break;
                    case CAISSE:
                        SDL_BlitSurface(caisse,NULL,ecran,&position);
                        break;
                    case CAISSE_OK:
                        SDL_BlitSurface(caisseOK,NULL,ecran,&position);
                        break;
                    case OBJECTIF:
                        SDL_BlitSurface(objectif,NULL,ecran,&position);
                        objectifsRestants=1;
                        break;

                }
            }
        }

        if(!objectifsRestants)
            continuer =0;

        position.x= positionJoueur.x * TAILLE_BLOC;
        position.y= positionJoueur.y * TAILLE_BLOC;
        SDL_BlitSurface(marioActuel,NULL,ecran,&position);

        SDL_Flip(ecran);
    }
    //D�sactivation r�p�tition des touches
    SDL_EnableKeyRepeat(0,0);

    SDL_FreeSurface(mur);
    SDL_FreeSurface(objectif);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(caisseOK);
    for(i=0;i<4;i++)
    {
        SDL_FreeSurface(mario[i]);
    }




}




