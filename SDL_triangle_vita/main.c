#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdbool.h>
//#include<SDL_image.h>
#include<SDL2/SDL_image.h>
//#include<include/SDL2/SDL.h>

int main(int argc, char* args[]){
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL Test", 0, 0, 960, 544, SDL_WINDOW_SHOWN);
    if (!window) printf("Error at window creation");

    /*SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ) );
    SDL_UpdateWindowSurface(window);*/

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        printf("Error SDL2_image Initialization");
        return 2;
    }

    SDL_Surface *sprite = IMG_Load("app0:/personaje.png");
    if (!sprite) {
        printf("Error cargando sprite: %s\n", IMG_GetError());
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(sprite);

    SDL_Rect dest;
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    dest.w /= 6;
    dest.h /= 6;

    dest.x = (1000 - dest.w) / 2;
    dest.y = (1000 - dest.h) / 2;

    bool run = true;
    SDL_Event e;

    while(run){
        while( SDL_PollEvent( &e ) ){ 
            if( e.type == SDL_QUIT ) run = false; 
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, tex, NULL, &dest);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
}