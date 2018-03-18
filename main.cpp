#include<stdlib.h>
#include<stdio.h>
#include<SDL/SDL.h>
#include<SDL_image.h>



int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;

    SDL_Event event;

    int continuer=1;

    if(SDL_Init(SDL_INIT_VIDEO) == -1)//Démarrage de systeme video de SDL
    {
            fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",SDL_GetError());
            exit(EXIT_FAILURE);
    }



    ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

    if(ecran == NULL)
    {
        fprintf(stderr,"Impossible de charger le mode video : %\n", SDL_GetError());
        exit(EXIT_FAILURE);

    }


    SDL_WM_SetCaption("Gestion events SDL",NULL);

    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.key.keysym.sym)
        {

            case SDLK_ESCAPE:
                continuer=0;
                break;
        }
    }



    SDL_Quit(); //Arrêt de la SDL

    return EXIT_SUCCESS;
}


