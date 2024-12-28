#include "graphics.h"
#include "math.h"

#include <SDL3/SDL.h>
#include <box2d/box2d.h>

void cartesianToScreen(float* x, float* y)
{
    int width, height;
    SDL_GetWindowSize(getWindow(), &width, &height);

    const float scaledWidth = (float)width / getScale();
    const float scaledHeight = (float)height / getScale();

    *x = (scaledWidth / 2.0f + *x) * getScale();
    *y = (scaledHeight / 2.0f + *y) * getScale();
}

void hexColorToRGB(const b2HexColor hexColor, SDL_FColor* color)
{
    color->r = hexColor >> 16 & 0xff;
    color->g = hexColor >> 8 & 0xff;
    color->b = hexColor;
    color->a = 255;
}