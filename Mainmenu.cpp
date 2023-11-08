#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	isClicked = false;
}

void MainMenu::Initialize(SDL_Renderer* ren)
{
	menuBackground.CreateTexture("image/Mainmenu.png", ren);
}

int MainMenu::EventHandling(SDL_Event& e)
{
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
	{
		return -1;
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 285 && e.motion.x < 510 && e.motion.y > 450 && e.motion.y < 535)
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