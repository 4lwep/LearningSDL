#include<SDL2/SDL.h>

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int up;
    int down;
    int left;
    int right;
} App;

App app;

typedef struct {
    int x;
    int y;
    SDL_Texture *texture;
} Entity;

Entity player;
Entity player1;
Entity player2;
Entity player3;
Entity player4;
Entity player5;
Entity player6;
Entity player7;
Entity player8;
Entity player9;
Entity player10;
Entity player11;
Entity player12;
