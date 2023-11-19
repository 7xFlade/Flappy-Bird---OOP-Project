#pragma once
#include "Object.hpp"

class Background :public Object
{
private:
	int distance1 = 0;
	int distance2 = 800;
	int pipeDistance1 = 400;
	int pipeDistance2 = 700;
	int pipeDistance3 = 1000;
	int incY1 = 0;
	int incY2 = 0;
	int incY3 = 0;
public:
	void GroundUpdate1();
	void GroundUpdate2();
	void Render(SDL_Renderer* ren);
	void GroundRender(SDL_Renderer* ren);

};

