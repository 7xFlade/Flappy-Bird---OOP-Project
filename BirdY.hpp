#pragma once
#include "Player.hpp"


class BirdY:public Player{
    private:
        int frate=0;
        SDL_Texture* Tex1;
    public:
        void Render(SDL_Renderer* ren);
        void createTexture1(const char* address, SDL_Renderer* ren);
};