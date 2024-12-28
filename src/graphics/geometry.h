#ifndef CIRCLES_H
#define CIRCLES_H
#include <SDL3/SDL.h>

#endif //CIRCLES_H

void drawCircle(SDL_FColor color, float centerX, float centerY, float radius);
void drawCircleWidth(SDL_FColor color, float centerX, float centerY, float radius, float width);
void drawSolidCircle(SDL_FColor color, float centerX, float centerY, float radius);
void drawSolidRect(SDL_FColor color, float x, float y, float width, float height);
void drawLine(SDL_FColor color, float x0, float y0, float x1, float y1);
void drawPolygon(SDL_FColor color, const SDL_FPoint vertices[], int vertexCount);
void drawSolidPolygon(SDL_FColor color, const SDL_FPoint vertices[], int vertexCount);