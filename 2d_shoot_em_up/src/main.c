#include<main.h>

static void capFrameRate(long *then, float *remainder)
{
    long wait, frameTime;

    wait = 16 + *remainder;

    *remainder -= (int)*remainder;

    frameTime = SDL_GetTicks() - *then;

    wait -= frameTime;

    if (wait < 1)
    {
        wait = 1;
    }

    SDL_Delay(wait);

    *remainder += 0.667;

    *then = SDL_GetTicks();
}

int main(int argc, char *argv[])
{
    long then;
    float remainder;

    memset(&app, 0, sizeof(App));

    initSDL();

    initStage();

    then = SDL_GetTicks();

    remainder = 0;

    while (!windowShouldClose){
        prepareScene();

        doInput();

        app.delegate.logic();

        app.delegate.draw();

        presentScene();

        capFrameRate(&then, &remainder);
    }

    return 0;
}