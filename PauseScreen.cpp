#include "PauseScreen.hpp"


//loading the image
void PauseScreen::Initialize(SDL_Renderer* ren)
{
	paused.CreateTexture("image/pause.png", ren);
}


//rendering 
void PauseScreen::Render(SDL_Renderer* ren)
{
	paused.Render(ren);
}

