#include "graphics.h"
#include "geometry.h"
#include "debugDraw.h"
#include "math.h"

#include <stdio.h>
#include <SDL3/SDL.h>
#include <box2d/box2d.h>

static float scale;

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

SDL_Window* getWindow()
{
    return window;
}

float getScale()
{
    return scale;
}

void updateScale()
{
    int width, height;
    SDL_GetWindowSize(window, &width, &height);

    float m = (float)width;
    if (height < width)
        m = (float)height;

    scale = m * 0.75f;
}

SDL_Renderer* getRenderer()
{
    return renderer;
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

    initDebugDraw();

    return true;
}

void renderDohyo()
{
    // draw base of the dohyo
    float x = 0.0f;
    float y = 0.0f;
    cartesianToScreen(&x, &y);
    SDL_FColor color = {55, 53, 53, 255};
    drawSolidCircle(color, x, y, 0.36f * scale);

    // draw the white border
    color = (SDL_FColor){255, 255, 255, 255};
    drawCircleWidth(color, x, y, 0.385f * scale, 0.025f * scale);

    // draw the shikiri lines
    color = (SDL_FColor){220, 149, 65, 255};

    const float width = 0.01f * scale;
    const float height = 0.1f * scale;
    x -= 0.05f * scale + width / 2;
    y -= height / 2;

    drawSolidRect(color, x, y, width, height);

    x += 0.1f * scale;

    drawSolidRect(color, x, y, width, height);
}

bool render()
{
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
    SDL_RenderClear(renderer);

    renderDohyo();
    debugDraw();

    SDL_RenderPresent(renderer);

    return true;
}