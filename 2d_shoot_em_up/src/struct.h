#include<SDL2/SDL.h>

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int up;
    int down;
    int left;
    int right;
    int fire;
} App;

App app;

typedef struct {
    int x;
    int y;
    int dx;
    int dy;
    int health;
    SDL_Texture *texture;
} Entity;

Entity player;

Entity bullet;