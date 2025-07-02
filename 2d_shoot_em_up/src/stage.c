#include<input.c>

SDL_Texture *bulletTexture;

static void drawPlayer(void)
{
    blit(player->texture, player->x, player->y);
}

static void drawBullets(void)
{
    Entity *b;

    for (b = stage.bulletHead.next ; b != NULL ; b = b->next)
    {
        blit(b->texture, b->x, b->y);
    }
}

static void draw(void)
{
    drawPlayer();

    drawBullets();
}

static void doBullets(void)
{
    Entity *b, *prev;

    prev = &stage.bulletHead;

    for (b = stage.bulletHead.next ; b != NULL ; b = b->next)
    {
        b->x += b->dx;
        b->y += b->dy;

        if (b->x > SCREEN_WIDTH)
        {
            if (b == stage.bulletTail)
            {
                stage.bulletTail = prev;
            }

            prev->next = b->next;
            free(b);
            b = prev;
        }

        prev = b;
    }
}

static void fireBullet(void)
{
    Entity *bullet;

    bullet = malloc(sizeof(Entity));
    memset(bullet, 0, sizeof(Entity));
    stage.bulletTail->next = bullet;
    stage.bulletTail = bullet;

    bullet->x = player->x + 35;
    bullet->y = player->y;
    bullet->dx = PLAYER_BULLET_SPEED;
    bullet->health = 1;
    bullet->texture = bulletTexture;
    SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);

    bullet->y += (player->h / 2) - (bullet->h / 2);

    player->reload = 8;
}

static void doPlayer(void)
{
    player->dx = player->dy = 0;

    if (player->reload > 0)
    {
        player->reload--;
    }

    if (app.keyboard[SDL_SCANCODE_UP] && player->y > 0)
    {
        player->dy = -PLAYER_SPEED;
    }

    if (app.keyboard[SDL_SCANCODE_DOWN] && player->y < SCREEN_HEIGHT - 70)
    {
        player->dy = PLAYER_SPEED;
    }

    if (app.keyboard[SDL_SCANCODE_LEFT] && player->x > 0)
    {
        player->dx = -PLAYER_SPEED;
    }

    if (app.keyboard[SDL_SCANCODE_RIGHT] && player->x < SCREEN_WIDTH - 70)
    {
        player->dx = PLAYER_SPEED;
    }

    if (app.keyboard[SDL_SCANCODE_LCTRL] && player->reload == 0)
    {
        fireBullet();
    }

    player->x += player->dx;
    player->y += player->dy;
}

static void logic(void)
{
    doPlayer();

    doBullets();
}

static void initPlayer()
{
    player = malloc(sizeof(Entity));
    memset(player, 0, sizeof(Entity));
    stage.fighterTail->next = player;
    stage.fighterTail = player;

    player->x = 100;
    player->y = 100;
    player->texture = loadTexture("../assets/personaje.png");
    SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
}

void initStage(void){
    app.delegate.logic = logic;
    app.delegate.draw = draw;

    memset(&stage, 0, sizeof(Stage));
    stage.fighterTail = &stage.fighterHead;
    stage.bulletTail = &stage.bulletHead;

    initPlayer();

    bulletTexture = loadTexture("../assets/bala.png");
}