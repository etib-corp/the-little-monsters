#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

typedef struct image_s
{
    SDL_Texture *texture;
} image_t;

image_t *initialize_image(SDL_Renderer *renderer, char *file_path);
void terminate_image(image_t *image);

bool image_draw(image_t *image, SDL_Renderer *renderer, SDL_FRect *source_rect, SDL_FRect *destination_rect);