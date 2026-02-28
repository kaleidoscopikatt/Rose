#include "Engine.h"

#include <iostream>

// Bootstrapping, essentially...
bool RoseEngine::Init()
{
    if (!screen)
        screen = new Screen();

    if (!scriptHandler)
        scriptHandler = new ScriptHandler();

    screen->Init(800, 600, SDL_WINDOW_RESIZABLE);
    scriptHandler->Init();
    
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

// Runs whenever the window ends up closing!
SDL_AppResult RoseEngine::Shutdown(bool didSucceed)
{
    if (scriptHandler)
    {
        scriptHandler->Liquidate();
        
        delete scriptHandler;
        scriptHandler = nullptr;
    }
    return didSucceed ? SDL_APP_SUCCESS : SDL_APP_FAILURE;
}

