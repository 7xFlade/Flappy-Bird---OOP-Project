
#include "Background.hpp"
#include<cstdlib>

// Render method is used to render the background. 
void Background::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}


// GroundRender method is used to render the ground with specific source and destination rectangles
void Background::GroundRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}


// GroundUpdate1 and GroundUpdate2 methods update the position of the ground texture for a scrolling effect
void Background::GroundUpdate1()
{
	if (distance1 <= -800)
	{
		distance1 = 805;
	}
	else
	{
		distance1-=3;
		setSource(0, 0, 336 ,112);
		setDest(distance1, 520, 830 ,112);
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
		setSource(0, 0, 336, 112);
		setDest(distance2, 520, 830 ,112);
	}
}
