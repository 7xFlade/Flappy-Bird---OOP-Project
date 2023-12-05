#include "MainMenu.hpp"

// Initializes the isClicked member variable to false
MainMenu::MainMenu()
{
	isClicked = false;
}

// Initializes the main menu by creating a texture for the menu background using the CreateTexture function
void MainMenu::Initialize(SDL_Renderer* ren)
{
	menuBackground.CreateTexture("image/Mainmenu.png", ren);
}

// Handles SDL events, particularly checking for quit events and mouse button clicks within a specific region on the screen.
// If the user clicks within the defined region (rectangle defined by coordinates), it sets the isClicked flag to true.
// Returns -1 if the quit event is detected
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

// Renders the main menu by rendering the background texture using the Render function.
void MainMenu::Render(SDL_Renderer* ren)
{
	menuBackground.Render(ren);
}

// Getter function to retrieve the value of the isClicked flag.
bool MainMenu::getClicked()
{
	return isClicked;
}

// Resets the isClicked flag to false when the object is destroyed
MainMenu::~MainMenu()
{
	isClicked = false;
}
