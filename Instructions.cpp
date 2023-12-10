#include "Instruction.hpp"

Instructions::Instructions()
{
	next = false;
}

//loading the image of background
void Instructions::Initialize(SDL_Renderer* ren)
{
	inst.CreateTexture("image/Instructions.png", ren);
}


//checking whether next arrow clicked or not
int Instructions::EventHandling(SDL_Event& e)
{
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
	{
		return -1;
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 690 && e.motion.x < 730 && e.motion.y > 470 && e.motion.y < 490)
	{
		next = true;
        
	}
	return 0;
}

void Instructions::Render(SDL_Renderer* ren)
{
	inst.Render(ren);
}

bool Instructions::getNext() const
{
	return next;
}

Instructions::~Instructions()
{
	next = false;
}