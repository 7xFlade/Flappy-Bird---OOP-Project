#pragma once
#include "Player.hpp"

//part of the three available sprites for the user
class BirdO:public Player{
    private:
        int frate=0;
        SDL_Texture* Tex1;
        SDL_Texture* Tex2;
        SDL_Texture* Tex3;
    public:
        void Render(SDL_Renderer* ren);
        void createTexture1(const char* address, SDL_Renderer* ren);
        void createTexture2(const char* address, SDL_Renderer* ren);
        void createTexture3(const char* address, SDL_Renderer* ren);
};
