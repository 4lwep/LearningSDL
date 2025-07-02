#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdbool.h>
#include<SDL2/SDL_image.h>
#include<defs.h>
#include<input.c>
#include<init.c>
#include<draw.h>

int main(int argc, char *argv[]){
    memset(&app, 0, sizeof(App));

    initSDL();

    while(!windowShouldClose)
    {
        prepareScene();

        doInput();

        presentScene();

        SDL_Delay(16);
    }

    return 0;
}