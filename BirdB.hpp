#pragma once
#include "Player.hpp"


class BirdB:public Player{
    private:
        //std::vector<SDL_Rect> BFrames={};
        int frate=0;
        SDL_Texture* Tex1;
        SDL_Texture* Tex2;
    public:
        void Render(SDL_Renderer* ren);
        void createTexture1(const char* address, SDL_Renderer* ren);
        void createTexture2(const char* address, SDL_Renderer* ren);
};