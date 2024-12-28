#include "debugDraw.h"

#include "math.h"

#include <box2d/box2d.h>

#include "geometry.h"
#include "graphics.h"
#include "../physics/physics.h"

static b2DebugDraw debugDrawStruct;

void drawSolidDebugCircle(b2Transform transform, float radius, b2HexColor color, void *context)
{
    const float scale = getScale();

    float x = transform.p.x;
    float y = transform.p.y;

    cartesianToScreen(&x, &y);
    radius *= scale;

    SDL_FColor RGB;
    hexColorToRGB(color, &RGB);

    drawSolidCircle(RGB, x, y, radius);
}

void drawDebugCircle(b2Vec2 center, float radius, b2HexColor color, void* context)
{
    const float scale = getScale();

    float x = center.x;
    float y = center.y;

    cartesianToScreen(&x, &y);
    radius *= scale;

    SDL_FColor RGB;
    hexColorToRGB(color, &RGB);

    drawCircle(RGB, x, y, radius);
}

void drawDebugPolygon(const b2Vec2* vertices, const int vertexCount, const b2HexColor color, void* context)
{
    SDL_FColor RGB;
    hexColorToRGB(color, &RGB);

    SDL_FPoint v[vertexCount];
    for (int i = 0; i < vertexCount; i++)
    {
        v[i].x = vertices[i].x;
        v[i].y = vertices[i].y;

        cartesianToScreen(&v[i].x, &v[i].y);
    }

    drawPolygon(RGB, v, vertexCount);
}

void drawDebugSolidPolygon(b2Transform transform, const b2Vec2* vertices, int vertexCount, float radius, b2HexColor color, void* context)
{
    SDL_FColor RGB;
    hexColorToRGB(color, &RGB);

    SDL_FPoint v[vertexCount];
    for (int i = 0; i < vertexCount; i++)
    {
        v[i].x = vertices[i].x;
        v[i].y = vertices[i].y;

        cartesianToScreen(&v[i].x, &v[i].y);
    }

    drawPolygon(RGB, v, vertexCount);
}

void initDebugDraw()
{
    debugDrawStruct = b2DefaultDebugDraw();

    debugDrawStruct.drawShapes = true;
    debugDrawStruct.drawAABBs = true;

    debugDrawStruct.DrawSolidCircle = drawSolidDebugCircle;
    debugDrawStruct.DrawCircle = drawDebugCircle;
    debugDrawStruct.DrawPolygon = drawDebugPolygon;
    debugDrawStruct.DrawSolidPolygon = drawDebugSolidPolygon;
}

void debugDraw()
{
    b2World_Draw(getWorldId(), &debugDrawStruct);
}