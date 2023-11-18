#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include "Background.hpp"

class EndWindow{
    public:
        bool restart=false;
        Background endBackground; 
    public:
        ~EndWindow();
        void Initialize(SDL_Renderer* ren);
        int EventHandling(SDL_Event& e);
        void Render(SDL_Renderer* ren);
        bool getRestart();
};