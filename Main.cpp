#define SDL_MAIN_USE_CALLBACKS 1 

#include <Engine/Engine.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static RoseEngine* gameEngine = nullptr;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    gameEngine = new RoseEngine();

    if (!gameEngine->Init()) {
        SDL_Log("RoseEngine.Init() failed");
        return gameEngine->Shutdown(false);
    }
    
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (gameEngine)
        gameEngine->HandleEvent(*event);

    if (event->type == SDL_EVENT_QUIT)
        return gameEngine->Shutdown(true);
    
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    if (gameEngine)
    {
        gameEngine->Update();
        gameEngine->Render();
    }
    
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    delete gameEngine;
    gameEngine = nullptr;
}