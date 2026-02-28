#include "Engine.h"

// Bootstrapping, essentially...
bool RoseEngine::Init()
{
    if (!screen)
        screen = new Screen();

    screen->Init(600, 800, SDL_WINDOW_FULLSCREEN);

    return true;
}

// Handles connections to any events.
void RoseEngine::HandleEvent(const SDL_Event& event)
{
    
}

// Pre-Rendering Function for every frame!
void RoseEngine::Update()
{
    
}

// Function that handles actual rendering. RoseEngine::Update() comes first.
void RoseEngine::Render()
{
    
    screen->Blit();
}



