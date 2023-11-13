#pragma once
#include "Background.hpp"
#include "Object.hpp"

class Obstacles:public Object{
    private:
        int leftward=800;
    public:
        void Render(SDL_Renderer* ren);
        void Update();
};