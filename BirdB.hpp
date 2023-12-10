#pragma once
#include "Player.hpp"

//Blue Bird
class BirdB:public Player{
    private:
        int frate=0;
        SDL_Texture* Tex1;//for second frame of blue bird
        SDL_Texture* Tex2;//for third frame of blue bird
    public:
        void Render(SDL_Renderer* ren);
        void createTexture1(const char* address, SDL_Renderer* ren);
        void createTexture2(const char* address, SDL_Renderer* ren);
        void createTexture3(const char* address, SDL_Renderer* ren);
};