#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL3/SDL.h>

#endif //GRAPHICS_H

void updateScale();
float getScale();
SDL_Window* getWindow();
SDL_Renderer* getRenderer();
bool initGraphics();
bool render();