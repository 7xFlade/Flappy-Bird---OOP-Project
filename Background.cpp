
#include "Background.hpp"
#include<cstdlib>

void Background::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}



void Background::GroundRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}



void Background::GroundUpdate1()
{
	if (distance1 <= -800)
	{
		distance1 = 805;
	}
	else
	{
		distance1-=3;
		setSource(0, 0, 112, 336);
		setDest(distance1, 520, 850,805);
	}
}

void Background::GroundUpdate2()
{
	if (distance2 <= -800)
	{
		distance2 = 805;
	}
	else
	{
		distance2-=3;
		setSource(0, 0, 112, 336);
		setDest(distance2, 520, 850,805);
	}
}


