#include "game.h"

game_t *initialize_game(void)
{
    game_t *game = NULL;

    game = SDL_calloc(1, sizeof(game_t));
    if (!game)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to allocate game structure: %s", SDL_GetError());
        return NULL;
    }

    game->window = SDL_CreateWindow(GAME_WINDOW_TITLE, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, GAME_WINDOW_FLAGS);
    if (!game->window)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create game window: %s", SDL_GetError());
        return NULL;
    }

    game->renderer = SDL_CreateRenderer(game->window, NULL);
    if (!game->renderer)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create game renderer: %s", SDL_GetError());
        return NULL;
    }

    game->background_image = initialize_image(game->renderer, "assets/images/miscellaneous/battle_interface.png");
    if (!game->background_image)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize background image: %s", SDL_GetError());
        return NULL;
    }

    return game;
}

void terminate_game(game_t *game)
{
    terminate_image(game->background_image);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_free(game);
}

bool game_routine(game_t *game)
{
    SDL_FRect destination_rect = {0.0f, 0.0f, (float)GAME_WINDOW_WIDTH, (float)GAME_WINDOW_HEIGHT};

    if (!image_draw(game->background_image, game->renderer, NULL, &destination_rect))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to draw background image: %s", SDL_GetError());
        return false;
    }

    SDL_RenderPresent(game->renderer);

    return true;
}