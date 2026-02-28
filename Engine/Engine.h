#pragma once
#include <SDL3/SDL.h>
#include <Engine/Screen.h>

class RoseEngine
{
public:
    Screen* screen;
    bool Init();

    void HandleEvent(const SDL_Event& event);
    void Update();
    void Render();

private:
    bool running = true;
};
