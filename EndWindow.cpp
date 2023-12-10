#include "EndWindow.hpp"

//initializing restart as false, so that when restart is clicked it becomes true
EndWindow::EndWindow():restart{false}{}

//Loading Game over window
void EndWindow::Initialize(SDL_Renderer* ren)
{
	endBackground.CreateTexture("image/EndGame.png", ren);
}


//Checking whether restart is pressed or not, by tracing its coordinates
int EndWindow::EventHandling(SDL_Event& w)
{
	SDL_PollEvent(&w);
	if (w.type == SDL_QUIT)
	{
		return -1;
	}
	//if restart clicked
	else if (w.type == SDL_MOUSEBUTTONDOWN && w.motion.x > 250 && w.motion.x < 550 && w.motion.y > 450 && w.motion.y < 530)
	{
		restart = true;
        
	}

	return 0;
}

void EndWindow::Render(SDL_Renderer* ren)
{
	endBackground.Render(ren);
}

bool EndWindow::getRestart() const
{
	return restart;
}

void EndWindow::setRestart(const bool s){
	restart=s;
}

EndWindow::~EndWindow()
{
	restart = false;

}