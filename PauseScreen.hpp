#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include "Background.hpp"


//Pause screen
class PauseScreen{
    public:
        Background paused; //aggreagtion of Background
    public:
        void Initialize(SDL_Renderer* ren);
        void Render(SDL_Renderer* ren);
};