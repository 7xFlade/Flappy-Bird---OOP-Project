#include "PauseScreen.hpp"

// Function to initialize the pause screen, loads background texture
// Parameters:
//   ren: The SDL_Renderer used for rendering
void PauseScreen::Initialize(SDL_Renderer* ren)
{
    paused.CreateTexture("image/pause.png", ren);
}

// Function to render the pause screen on the provided renderer
// Parameters:
//   ren: The SDL_Renderer used for rendering
void PauseScreen::Render(SDL_Renderer* ren)
{
    paused.Render(ren);
}
