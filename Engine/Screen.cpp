#include "Screen.h"

bool Screen::Init(int scrWidth, int scrHeight, SDL_WindowFlags windowType)
{
    if (!this->hasInit)
    {
        if (!SDL_CreateWindowAndRenderer("Rose Engine v1.0.0", scrWidth, scrHeight, windowType, &this->screenWindow, &this->screenRenderer))
        {
            SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Failed to create a window from Screen.Init()");
            return false;
        }
        
        this->hasInit = true;
        return true;
    }

    return this->hasInit;
}

void Screen::Blit()
{
    SDL_RenderPresent(screenRenderer);
}

void Screen::SetDrawColour(Colour* drawColour)
{
    this->currDrawColour = drawColour;
    SDL_SetRenderDrawColor(screenRenderer, drawColour->R, drawColour->G, drawColour->B, 255);
}

void Screen::SetBackgroundColour(Colour* backgroundColour)
{
    Colour oldDrawColour = *this->currDrawColour;
    
    this->SetDrawColour(backgroundColour);
    SDL_RenderClear(screenRenderer);

    this->SetDrawColour(&oldDrawColour);
}
