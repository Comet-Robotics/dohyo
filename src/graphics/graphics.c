#include "graphics.h"
#include "circles.h"

#include <math.h>
#include <SDL3/SDL.h>

static float scale;

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

void updateScale()
{
    int width, height;
    SDL_GetWindowSize(window, &width, &height);

    float m = (float)width;
    if (height < width)
        m = (float)height;

    scale = m * 0.75f;
}

float getScale()
{
    return scale;
}

SDL_Window* getWindow()
{
    return window;
}

SDL_Renderer* getRenderer()
{
    return renderer;
}

SDL_FPoint cartesianToScreen(float x, float y)
{
    int width, height;
    SDL_GetWindowSize(window, &width, &height);

    const float scaledWidth = (float)width / scale;
    const float scaledHeight = (float)height / scale;

    x = (scaledWidth / 2.0f + x) * scale;
    y = (scaledHeight / 2.0f + y) * scale;

    return (SDL_FPoint){x, y};
}

bool initGraphics()
{
    SDL_SetAppMetadata("Dohyo", "1.0", "org.cometrobotics.dohyo");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return false;
    }

    if (!SDL_CreateWindowAndRenderer("Dohyo", 800, 800, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return false;
    }

    SDL_SetWindowResizable(window, true);

    updateScale();

    return true;
}

void renderDohyo()
{
    // draw base of the dohyo
    SDL_SetRenderDrawColor(renderer, 55, 53, 53, 255);
    SDL_FPoint center = cartesianToScreen(0.0f, 0.0f);
    drawFilledCircle(renderer, center.x, center.y, 0.36f * scale);

    // draw the white border
    SDL_SetRenderDrawColor(renderer, 225, 225, 225, 255);
    drawCircleWidth(renderer, center.x, center.y, 0.385f * scale, 0.025f * scale);

    // draw the shikiri lines
    SDL_SetRenderDrawColor(renderer, 220, 149, 65, 255);

    const float width = 0.01f * scale;
    const float height = 0.1f * scale;
    center.x -= 0.05f * scale;

    SDL_FRect rect = (SDL_FRect){center.x - width/2, center.y - height/2, width, height};
    SDL_RenderFillRect(renderer, &rect);

    rect.x += 0.1f * scale;
    SDL_RenderFillRect(renderer, &rect);
}

bool render()
{
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
    SDL_RenderClear(renderer);

    renderDohyo();

    SDL_RenderPresent(renderer);

    return true;
}