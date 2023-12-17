#include "SelectBird.hpp"

SelectBird::SelectBird(){
    isChosenB=false;
}

//loading the background
void SelectBird::Initialize(SDL_Renderer* ren){
    
    m.CreateTexture("image/SelectBird.png", ren);
}

//determing which bird is selected by comparing the click x and y coordibate with the one in the background
int SelectBird::EventHandling(SDL_Event& b)
{
	SDL_PollEvent(&b);
	if (b.type == SDL_QUIT)
	{
		return -1;
	}
	//blue bird coordinates
	else if (b.type == SDL_MOUSEBUTTONDOWN && b.motion.x > 100 && b.motion.x < 250 && b.motion.y > 280 && b.motion.y < 350)
	{
		bird=1;
		isChosenB = true;
	}
	//yellow bird coordinates
	else if (b.type == SDL_MOUSEBUTTONDOWN && b.motion.x > 350 && b.motion.x < 500 && b.motion.y > 280 && b.motion.y < 350)
	{
		bird=2;
		isChosenB = true;
	}
	//owl coordinates
	else if (b.type == SDL_MOUSEBUTTONDOWN && b.motion.x > 550 && b.motion.x < 730 && b.motion.y > 280 && b.motion.y < 350)
	{
		bird=3;
		isChosenB = true;
	}
	return 0;
}

void SelectBird::Render(SDL_Renderer* ren)
{
	m.Render(ren);
}

//Accessors
bool SelectBird::getChosenB()
{
	return isChosenB;
}

int SelectBird::getBird(){
	return bird;
}
