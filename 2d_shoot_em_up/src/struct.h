#include<SDL2/SDL.h>

typedef struct{
    void (*logic)(void);
    void (*draw)(void);
} Delegate;

Delegate delegate;

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    Delegate delegate;
    int keyboard[MAX_KEYBOARD_KEYS];
} App;

App app;

typedef struct Entity{
    float x;
    float y;
    int w;
    int h;
    float dx;
    float dy;
    int health;
    int reload;
    SDL_Texture *texture;
    struct Entity *next;
}Entity;

Entity *player;

//Entity *bullet;

typedef struct {
    Entity fighterHead, *fighterTail;
    Entity bulletHead, *bulletTail;
} Stage;

Stage stage;