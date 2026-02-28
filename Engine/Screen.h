#pragma once
#include <SDL3/SDL.h>
#include <Engine/Colour.h>

class Screen
{
public:
    bool Init(int scrWidth, int scrHeight, SDL_WindowFlags windowType);

    void Blit();
    
    void SetDrawColour(Colour* drawColour);
    void SetBackgroundColour(Colour* backgroundColour);

private:
    SDL_Window *screenWindow = nullptr;
    SDL_Renderer *screenRenderer = nullptr;

    Colour* currDrawColour = new Colour(255, 255, 255, 255);
    bool hasInit = false;
};
