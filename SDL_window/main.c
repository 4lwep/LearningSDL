#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdbool.h>

int main(int argc, char* args[]){
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL Test", 0, 0, 500, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (!window) printf("Error at window creation");

    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ) );
    SDL_UpdateWindowSurface( window );

    /*SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    //SDL_Event event;*/
    bool run = true;
    SDL_Event e;

    while(run){
        while( SDL_PollEvent( &e ) ){ 
            if( e.type == SDL_QUIT ) run = false; 
        }
    }

    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
}