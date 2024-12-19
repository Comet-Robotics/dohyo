
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <box2d/box2d.h>

const static float WINDOW_WIDTH = 1000.0f;  ///< Width in pixels of the SDL window
const static float WINDOW_HEIGHT = 1000.0f; ///< Height in pixels of the SDL window

const static float SCALE = 1.0f;             ///< Scale to render Box2D objects at
const static float TIME_STEP = 1.0f / 60.0f; ///< Timestep for Box2D simulation
const static int SUB_STEPS = 4;              ///< Box2D simulation substeps

const static float SCALED_WIDTH = WINDOW_WIDTH * SCALE;
const static float SCALED_HEIGHT = WINDOW_HEIGHT * SCALE;

static SDL_Window *window = NULL;     ///< The main SDL window
static SDL_Renderer *renderer = NULL; ///< The main SDL renderer

static b2WorldId worldId; ///< The Box2D world to use for simulation
static b2BodyId groundId; ///< The static ground body
static b2BodyId bodyId;   ///< Dynamic body

int main(int argc, char *argv[])
{

    SDL_SetAppMetadata("Example Renderer Clear", "1.0", "com.example.renderer-clear");

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (!SDL_CreateWindowAndRenderer("examples/renderer/clear", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer))
    {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // initialize Box2D world
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = (b2Vec2){0.0f, -10.0f};
    worldId = b2CreateWorld(&worldDef);

    // create the ground
    b2BodyDef groundBodyDef = b2DefaultBodyDef();
    groundBodyDef.position = (b2Vec2){0.0f, -350.0f};
    groundId = b2CreateBody(worldId, &groundBodyDef);
    const b2Polygon groundBox = b2MakeBox(1000.0f, 25.0f);
    const b2ShapeDef groundShapeDef = b2DefaultShapeDef();
    b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);

    bool isRunning = true;
    // Main loop where rendering happens
    while (isRunning)
    {

        SDL_Event windowEvent;
        if (SDL_WaitEvent(&windowEvent) != 0)
        {
            switch (windowEvent.type)
            {
            case SDL_EVENT_QUIT:
            {
                isRunning = false;
                printf("Quitting Program.\n");
                break;
            }
            default:
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    b2DestroyWorld(worldId);

    return 0;
}