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
	// bool Pipe_Above1Update(int incY, int &score);
	// bool Pipe_Below1Update(int incY);
	// bool Pipe_Above2Update(int incY, int& score);
	// bool Pipe_Below2Update(int incY);
	// bool Pipe_Above3Update(int incY, int& score);
	// bool Pipe_Below3Update(int incY);
	//void Reset();
	// int getPipe1X();
	// int getPipe1Y();
	// int getPipe2X();
	// int getPipe2Y();
	// int getPipe3X();
	// int getPipe3Y();
	void GroundUpdate1();
	void GroundUpdate2();
	void Render(SDL_Renderer* ren);
	void GroundRender(SDL_Renderer* ren);
	// void LeaderboardRender(SDL_Renderer* ren);
	// void PipeRender(SDL_Renderer* ren);

};

