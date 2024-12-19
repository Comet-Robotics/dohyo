#include "graphics.h"

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

// https://stackoverflow.com/questions/38334081/how-to-draw-circles-arcs-and-vector-graphics-in-sdl
void drawCircle(SDL_Renderer* renderer, const float centerX, const float centerY, const float radius)
{
    const float diameter = radius * 2.0f;

    float x = (radius - 1);
    float y = 0;
    float tx = 1;
    float ty = 1;
    float error = (tx - diameter);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderPoint(renderer, centerX + x, centerY - y);
        SDL_RenderPoint(renderer, centerX + x, centerY + y);
        SDL_RenderPoint(renderer, centerX - x, centerY - y);
        SDL_RenderPoint(renderer, centerX - x, centerY + y);
        SDL_RenderPoint(renderer, centerX + y, centerY - x);
        SDL_RenderPoint(renderer, centerX + y, centerY + x);
        SDL_RenderPoint(renderer, centerX - y, centerY - x);
        SDL_RenderPoint(renderer, centerX - y, centerY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }
        else
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void drawCircleWidth(SDL_Renderer* renderer, const float centerX, const float centerY, const float radius, const float width)
{
    drawCircle(renderer, centerX, centerY, radius);
    for (int i = 0; (float)i < width-1; i++)
    {
        drawCircle(renderer, centerX, centerY, radius - (float)i);
    }
}

// https://stackoverflow.com/questions/65723827/sdl2-function-to-draw-a-filled-circle
void drawFilledCircle(SDL_Renderer *renderer, float centerX, float centerY, const float radius)
{
    for (int w = 0; (float)w < radius * 2; w++)
    {
        for (int h = 0; (float)h < radius * 2; h++)
        {
            const float dx = radius - (float)w;
            const float dy = radius - (float)h;
            if (dx*dx + dy*dy <= radius * radius)
            {
                SDL_RenderPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
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

    if (!SDL_CreateWindowAndRenderer("examples/renderer/clear", 800, 800, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return false;
    }

    SDL_SetWindowTitle(window, "Dohyo");
    SDL_SetWindowResizable(window, true);

    updateScale();

    return true;
}

bool render()
{
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
    SDL_RenderClear(renderer);

    // draw base of the dohyo
    SDL_SetRenderDrawColor(renderer, 55, 53, 53, 255);
    SDL_FPoint center = cartesianToScreen(0.0f, 0.0f);
    drawFilledCircle(renderer, center.x, center.y, 0.385f * scale);

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

    SDL_RenderPresent(renderer);

    return true;
}