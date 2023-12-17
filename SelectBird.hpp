#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include "Background.hpp"

//Page to choose between the three birds
class SelectBird{
    private:
        bool isChosenB;
        Background m;//aggreagation of Background
        int bird;//for maintaining record of which bird is chosen
    public:
        SelectBird();
        void Initialize(SDL_Renderer* ren);
        int EventHandling(SDL_Event& b);
        void Render(SDL_Renderer* ren);
        bool getChosenB();
        int getBird();
};