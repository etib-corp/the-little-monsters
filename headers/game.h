#pragma once

#include <SDL3/SDL.h>

#include "image.h"

#define GAME_WINDOW_TITLE "The Little Monsters"
#define GAME_WINDOW_WIDTH 160
#define GAME_WINDOW_HEIGHT 144
#define GAME_WINDOW_FLAGS SDL_WINDOW_FULLSCREEN

typedef struct game_s
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    image_t *background_image;
} game_t;

game_t *initialize_game(void);
void terminate_game(game_t *game);

bool game_routine(game_t *game);