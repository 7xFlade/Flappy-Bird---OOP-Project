#pragma once
#include "Player.hpp"

//Yellow Bird
class BirdY:public Player{
    private:
        int frate{};
        SDL_Texture* Tex1{};//for second frame of yello bird
    public:
        BirdY();
        ~BirdY();
        BirdY(const BirdY& other);
        void Render(SDL_Renderer* ren);
        void createTexture1(const char* address, SDL_Renderer* ren);
        void createTexture2(const char* address, SDL_Renderer* ren);
        void createTexture3(const char* address, SDL_Renderer* ren);
};