#include "EndWindow.hpp"

// responsible for initializing the end window, particularly loading the background texture
void EndWindow::Initialize(SDL_Renderer* ren)
{
	endBackground.CreateTexture("image/endscreen.png", ren);
}

// takes an SDL_Event reference and handles events, such as checking for a quit event or a mouse button 
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

// The Render method is responsible for rendering the end window, presumably using the background texture
void EndWindow::Render(SDL_Renderer* ren)
{
	endBackground.Render(ren);
}

// It is used to check whether a restart is requested
bool EndWindow::getRestart()
{
	return restart;
}

EndWindow::~EndWindow()
{
	//destructor sets the value of restart to false so that the game knows that it is not to restart and can call all relevant destroy functionalities
	restart = false;
}
