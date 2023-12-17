#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include "Background.hpp"

//Instructions Screen
class Instructions{
    public:
        bool next;
        Background inst; //aggregation of Background
    public:
        Instructions();
        ~Instructions();
        void Initialize(SDL_Renderer* ren);
        int EventHandling(SDL_Event& e);
        void Render(SDL_Renderer* ren);
        bool getNext() const;


};