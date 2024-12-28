#include "geometry.h"

#include <SDL3/SDL.h>

#include "graphics.h"

// https://stackoverflow.com/questions/38334081/how-to-draw-circles-arcs-and-vector-graphics-in-sdl
void drawCircle(const SDL_FColor color, const float centerX, const float centerY, const float radius)
{
    SDL_Renderer* renderer = getRenderer();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

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

void drawCircleWidth(const SDL_FColor color, const float centerX, const float centerY, const float radius, const float width)
{
    SDL_Renderer* renderer = getRenderer();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    drawCircle(color, centerX, centerY, radius);
    for (int i = 0; (float)i < width-1; i++)
    {
        drawCircle(color, centerX, centerY, radius - (float)i);
    }
}

// https://stackoverflow.com/questions/65723827/sdl2-function-to-draw-a-filled-circle
void drawSolidCircle(const SDL_FColor color, const float centerX, const float centerY, const float radius)
{
    SDL_Renderer* renderer = getRenderer();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

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

void drawSolidRect(const SDL_FColor color, const float x, const float y, const float width, const float height)
{
    SDL_Renderer* renderer = getRenderer();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    const SDL_FRect rect = {x, y, width, height};

    SDL_RenderFillRect(renderer, &rect);
}

void drawLine(const SDL_FColor color, const float x0, const float y0, const float x1, const float y1)
{
    SDL_Renderer* renderer = getRenderer();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderLine(renderer, x0, y0, x1, y1);
}

void drawPolygon( const SDL_FColor color, const SDL_FPoint vertices[], const int vertexCount)
{
    SDL_Renderer* renderer = getRenderer();
    for (int i = 0; i < vertexCount; i++)
    {
        const SDL_FPoint v0 = vertices[i];
        SDL_FPoint v1;
        if (i != vertexCount-1)
            v1 = vertices[i + 1];
        else
            v1 = vertices[0];

        drawLine(color, v0.x, v0.y, v1.x, v1.y);
    }
}

void drawSolidPolygon( const SDL_FColor color, const SDL_FPoint vertices[], const int vertexCount)
{
    SDL_Renderer* renderer = getRenderer();

    // TODO: Draw solid polygons (this is hard)
}