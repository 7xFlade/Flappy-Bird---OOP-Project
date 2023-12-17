#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include "Background.hpp"

//Main Screen
class MainMenu{
    public:
        bool isClicked;
        Background menuBackground; //aggregation of Background
    public:
        MainMenu();
        ~MainMenu();
        void Initialize(SDL_Renderer* ren);
        int EventHandling(SDL_Event& e);
        void Render(SDL_Renderer* ren);
        bool getClicked();


};