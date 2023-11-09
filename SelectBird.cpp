#include "SelectBird.hpp"

SelectBird::SelectBird(){
    isChosenB=false;
}

void SelectBird::Initialize(SDL_Renderer* ren){
    
    m.CreateTexture("image/sb.png", ren);
}

int SelectBird::EventHandling(SDL_Event& b)
{
	SDL_PollEvent(&b);
	if (b.type == SDL_QUIT)
	{
		return -1;
	}
	else if (b.type == SDL_MOUSEBUTTONDOWN && b.motion.x > 100 && b.motion.x < 300 && b.motion.y > 280 && b.motion.y < 350)
	{
		isChosenB = true;
	}
	return 0;
}

void SelectBird::Render(SDL_Renderer* ren)
{
	m.Render(ren);
}

bool SelectBird::getChosenB()
{
	return isChosenB;
}
