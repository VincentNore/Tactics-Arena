#include<stdlib.h>
#include<stdio.h>
#include<SDL/SDL.h>
#include<SDL_image.h>



int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *zozor = NULL;

    SDL_Event event;

    SDL_Rect positionZozor;



    int continuer=1;

    if(SDL_Init(SDL_INIT_VIDEO) == -1)//D�marrage de systeme video de SDL
    {
            fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",SDL_GetError());
            exit(EXIT_FAILURE);
    }



    ecran = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

    if(ecran == NULL)
    {
        fprintf(stderr,"Impossible de charger le mode video : %\n", SDL_GetError());
        exit(EXIT_FAILURE);

    }

    zozor= SDL_LoadBMP("zozor.bmp");
    SDL_SetColorKey(zozor,SDL_SRCCOLORKEY,SDL_MapRGB(zozor->format,0,0,255));
    SDL_WM_SetCaption("Gestion events SDL",NULL);

    positionZozor.x= ecran->w /2 - zozor->w /2;
    positionZozor.y= ecran->h /2 - zozor->h /2;
    SDL_EnableKeyRepeat(10,10);
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer=0;
                break;

            case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_RIGHT)

                    continuer = 0;
                break;

            case SDL_MOUSEMOTION:
                positionZozor.x = event.motion.x;
                positionZozor.y = event.motion.y;

        }

        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
        SDL_BlitSurface(zozor,NULL,ecran,&positionZozor);
        SDL_Flip(ecran);

    }


    SDL_FreeSurface(zozor);
    SDL_Quit(); //Arr�t de la SDL

    return EXIT_SUCCESS;
}


