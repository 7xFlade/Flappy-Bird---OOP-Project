#pragma once
#include "Player.hpp"

//Yellow Bird
class BirdY:public Player{
    private:
        int frate=0;
        SDL_Texture* Tex1;//for second frame of yello bird
    public:
        void Render(SDL_Renderer* ren);
        void createTexture1(const char* address, SDL_Renderer* ren);
        void createTexture2(const char* address, SDL_Renderer* ren);
        void createTexture3(const char* address, SDL_Renderer* ren);
};