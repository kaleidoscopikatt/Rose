#pragma once
#include <SDL3/SDL.h>

#include <Engine/Screen.h>
#include <Engine/ScriptHandler.h>

class RoseEngine
{
public:
    Screen* screen;
    ScriptHandler* scriptHandler;
    
    bool Init();

    void HandleEvent(const SDL_Event& event);
    void Update();
    void Render();
    SDL_AppResult Shutdown(bool didSucceed);

private:
    bool running = true;
};
