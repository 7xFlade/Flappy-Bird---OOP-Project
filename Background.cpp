#include "Background.hpp"

//Rendering Background
void Background::Render(SDL_Renderer *ren)
{
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

//Rendering the base of the background
void Background::GroundRender(SDL_Renderer *ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}


//Updating the x and y coordinates of base SDl_Rect, so that the birds appear to be moving forward
void Background::GroundUpdate1()
{
	if (distance1 <= -800)
	{
		distance1 = 800;
	}
	else
	{
		distance1 -= 3;
		setSource(0, 0, 336, 112);
		setDest(distance1, 520, 805, 112);
	}
}
void Background::GroundUpdate2()
{
	if (distance2 <= -800)
	{
		distance2 = 800;
	}
	else
	{
		distance2 -= 3;
		setSource(0, 0, 336, 112);
		setDest(distance2, 520, 805, 112);
	}
}