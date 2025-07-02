#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdbool.h>
#include<SDL2/SDL_image.h>

#include<main.h>

int main(int argc, char *argv[]){
    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));

    initSDL();

    player.x = 100;
    player.y = 100;
    player.texture = loadTexture("../assets/personaje.png");

    while(!windowShouldClose)
    {
        prepareScene();

        doInput();

        blit(player.texture, player.x, player.y);

        presentScene();

        SDL_Delay(16);
    }

    return 0;
}