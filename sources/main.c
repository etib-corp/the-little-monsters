#include <SDL3/SDL_main.h>

#include "game.h"

SDL_AppResult SDL_AppInit(void **state_pointer, int argc, char *argv[])
{
    game_t *game = NULL;

    game = initialize_game();
    if (!game)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize game: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    *state_pointer = game;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *state, SDL_Event *event)
{
    game_t *game = (game_t *)state;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *state)
{
    game_t *game = (game_t *)state;

    if (!game_routine(game))
    {
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *state, SDL_AppResult result)
{
    game_t *game = (game_t *)state;

    terminate_game(game);
}