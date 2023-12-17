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

//Rendering the end window
void EndWindow::Render(SDL_Renderer* ren)
{
	endBackground.Render(ren);
}


//accessor of whether restart clicked or not
bool EndWindow::getRestart() const
{
	return restart;
}

//mutator to change restart to another bool value
void EndWindow::setRestart(const bool s){
	restart=s;
}

EndWindow::~EndWindow()
{
	restart = false;

}