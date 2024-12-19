/**
 * @page main main
 * All the sample code for the template is in this file. For the sake of simplicity, everything is in the same file
 * and certain best practices are ignored.
 */
#define SDL_MAIN_USE_CALLBACKS 1                ///< use the callbacks instead of main()
#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <box2d/box2d.h>

const static float WINDOW_WIDTH = 1000.0f;      ///< Width in pixels of the SDL window
const static float WINDOW_HEIGHT = 1000.0f;     ///< Height in pixels of the SDL window

const static float SCALE = 1.0f;                ///< Scale to render Box2D objects at
const static float TIME_STEP = 1.0f / 60.0f;    ///< Timestep for Box2D simulation
const static int SUB_STEPS = 4;                 ///< Box2D simulation substeps

const static float SCALED_WIDTH = WINDOW_WIDTH * SCALE;
const static float SCALED_HEIGHT = WINDOW_HEIGHT * SCALE;

static SDL_Window *window = NULL;               ///< The main SDL window
static SDL_Renderer *renderer = NULL;           ///< The main SDL renderer

static b2WorldId worldId;                       ///< The Box2D world to use for simulation
static b2BodyId groundId;                       ///< The static ground body
static b2BodyId bodyId;                         ///< Dynamic body

/**
 * Convert the given box2D body's coordinates from box2D to SDL screen-space. For the sake of simplicity, this function
 * assumes that the body has a rectangular collision shape.
 * @param bodyId The ID of the Box2D body to convert.
 * @return The new SDL rectangle.
 */
SDL_FRect box2DtoSDL(b2BodyId bodyId)
{
    b2Vec2 position = b2Body_GetPosition(bodyId);

    // get the body's collision polygon
    b2ShapeId shapes[1];
    b2Body_GetShapes(bodyId, shapes, 1);
    const b2Polygon polygon = b2Shape_GetPolygon(shapes[0]);

    // create the SDL rectangle
    SDL_FRect rect;

    // calculate the object's width and height
    rect.w = fabsf(polygon.vertices[0].x - polygon.vertices[1].x) * SCALE;
    rect.h = fabsf(polygon.vertices[1].y - polygon.vertices[2].y) * SCALE;

    printf("%f\n", rect.h);

    // calculate the object's X and Y positions in screen space
    rect.x = (SCALED_WIDTH / 2.0f + position.x) * SCALE - rect.w / 2;
    rect.y = (SCALED_HEIGHT / 2.0f - position.y) * SCALE - rect.h / 2;

    return rect;
}

/**
 * Runs once at startup.
 * @param appstate
 * @param argc
 * @param argv
 * @return
 */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    SDL_SetAppMetadata("Example Renderer Clear", "1.0", "com.example.renderer-clear");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("examples/renderer/clear", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
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

    // create the falling box
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = (b2Vec2){0.0f, 100.0f};
    bodyId = b2CreateBody(worldId, &bodyDef);
    b2Polygon dynamicBox = b2MakeBox(10.0f, 10.0f);
    b2ShapeDef shapeDef = b2DefaultShapeDef();
    shapeDef.density = 1.0f;
    shapeDef.friction = 0.3f;
    b2CreatePolygonShape(bodyId, &shapeDef, &dynamicBox);

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/**
 * Runs once when an event (keyboard, mouse, etc.) occurs.
 * @param appstate
 * @param event
 * @return
 */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/**
 * Runs once per frame.
 * @param appstate
 * @return
 */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    // run the simulation
    b2World_Step(worldId, TIME_STEP, SUB_STEPS);

    // clear screen
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // render the ground
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_FRect rect = box2DtoSDL(groundId);
    SDL_RenderFillRect(renderer, &rect);

    // render the falling cube
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    rect = box2DtoSDL(bodyId);
    SDL_RenderFillRect(renderer, &rect);

    // present the render
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/**
 * Runs once at shutdown.
 * @param appstate
 * @param result
 */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    b2DestroyWorld(worldId);
}