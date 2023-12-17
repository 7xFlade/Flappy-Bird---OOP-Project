#pragma once
#include "Background.hpp"
#include "Object.hpp"

class Obstacles:public Object
{
    private:
        //initializing the x axis of obstacles
        int pipeDistance1 = 700;
	int pipeDistance2 = 900;
	int pipeDistance3 = 1100;
        int incY1 = 0;
        int incY2 = 0;
        int incY3 = 0;
        int loopt;
    public:
        bool Pipe_Above1Update(int incY, int &score);
        bool Pipe_Below1Update(int incY, int &score);
        bool Pipe_Above2Update(int incY, int& score);
        bool Pipe_Below2Update(int incY, int &score);
        bool Pipe_Above3Update(int incY, int& score);
        bool Pipe_Below3Update(int incY, int &score);
        void Reset();
        int getPipe1X() const;
        int getPipe1Y() const;
        int getPipe2X() const;
        int getPipe2Y() const;
        int getPipe3X() const;
        int getPipe3Y() const;
        void Render(SDL_Renderer* ren);
};
