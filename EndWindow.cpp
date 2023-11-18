#include "EndWindow.hpp"



void EndWindow::Initialize(SDL_Renderer* ren)
{
	endBackground.CreateTexture("image/endscreen.png", ren);
}

int EndWindow::EventHandling(SDL_Event& w)
{
	SDL_PollEvent(&w);
	if (w.type == SDL_QUIT)
	{
		return -1;
	}
	else if (w.type == SDL_MOUSEBUTTONDOWN && w.motion.x > 250 && w.motion.x < 550 && w.motion.y > 480 && w.motion.y < 560)
	{
		restart = true;
        
	}
	return 0;
}

void EndWindow::Render(SDL_Renderer* ren)
{
	endBackground.Render(ren);
}

bool EndWindow::getRestart()
{
	return restart;
}

EndWindow::~EndWindow()
{
	restart = false;
}