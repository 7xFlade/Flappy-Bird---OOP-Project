#include "PauseScreen.hpp"



void PauseScreen::Initialize(SDL_Renderer* ren)
{
	paused.CreateTexture("image/pause.png", ren);
}



void PauseScreen::Render(SDL_Renderer* ren)
{
	paused.Render(ren);
}

