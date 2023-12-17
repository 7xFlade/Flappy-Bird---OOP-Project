#pragma once
#include "Background.hpp"


//GAME OVER SCREEN
class EndWindow{
    public:
        bool restart=false;
        Background endBackground; //aggregation of Background class
    public:
        EndWindow();
        ~EndWindow();
        void Initialize(SDL_Renderer* ren);
        int EventHandling(SDL_Event& e);
        void Render(SDL_Renderer* ren);
        bool getRestart() const;
        void setRestart(const bool s);
};