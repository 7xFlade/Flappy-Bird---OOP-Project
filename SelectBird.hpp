#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include "Background.hpp"

class SelectBird{
    private:
        bool isChosenB;
        Background m;
    public:
        SelectBird();
        void Initialize(SDL_Renderer* ren);
        int EventHandling(SDL_Event& b);
        void Render(SDL_Renderer* ren);
        bool getChosenB();
};