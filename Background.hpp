#pragma once
#include "Object.hpp"

class Background :public Object
{
private:
	//attributes which will be used as x coordinate when updating the 2 grounds
	int distance1 = 0;
	int distance2 = 800;
public:
	void GroundUpdate1();
	void GroundUpdate2();
	void Render(SDL_Renderer* ren);
	void GroundRender(SDL_Renderer* ren);

};

