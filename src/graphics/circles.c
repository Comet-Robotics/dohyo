#include "circles.h"

#include <SDL3/SDL.h>

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
void drawFilledCircle(SDL_Renderer *renderer, const float centerX, const float centerY, const float radius)
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