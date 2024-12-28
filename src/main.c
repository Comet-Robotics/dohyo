#define SDL_MAIN_USE_CALLBACKS 1
#define NK_SDL_IMPLEMENTATION

#include <SDL3/SDL_main.h>

#include "graphics/graphics.h"
#include "physics/physics.h"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    initGraphics();
    initPhysics();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT)
        return SDL_APP_SUCCESS;
    if (event->type == SDL_EVENT_WINDOW_RESIZED)
        updateScale();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    if (!render())
        return SDL_APP_FAILURE;
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    destroyPhysics();
}