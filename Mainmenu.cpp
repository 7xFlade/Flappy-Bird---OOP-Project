#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	isClicked = false;
}

//loading the image of background
void MainMenu::Initialize(SDL_Renderer* ren)
{
	menuBackground.CreateTexture("image/Main.png", ren);
}


//checking whether start game option is selected or not
int MainMenu::EventHandling(SDL_Event& e)
{
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
	{
		return -1;
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 285 && e.motion.x < 510 && e.motion.y > 430 && e.motion.y < 505)
	{
		isClicked = true;
        
	}
	return 0;
}

void MainMenu::Render(SDL_Renderer* ren)
{
	menuBackground.Render(ren);
}

bool MainMenu::getClicked()
{
	return isClicked;
}

MainMenu::~MainMenu()
{
	isClicked = false;
}