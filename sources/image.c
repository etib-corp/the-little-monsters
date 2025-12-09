#include "image.h"

image_t *initialize_image(SDL_Renderer *renderer, char *file_path)
{
    image_t *image = NULL;

    image = SDL_calloc(1, sizeof(image_t));
    if (!image)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to allocate image structure: %s", SDL_GetError());
        return NULL;
    }

    image->texture = IMG_LoadTexture(renderer, file_path);
    if (!image->texture)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load image texture from file '%s': %s", file_path, SDL_GetError());
        return NULL;
    }

    return image;
}

void terminate_image(image_t *image)
{
    SDL_DestroyTexture(image->texture);
    SDL_free(image);
}

bool image_draw(image_t *image, SDL_Renderer *renderer, SDL_FRect *source_rect, SDL_FRect *destination_rect)
{
    if (!SDL_RenderTexture(renderer, image->texture, source_rect, destination_rect))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to draw image: %s", SDL_GetError());
        return false;
    }

    return true;
}
