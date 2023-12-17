#pragma once
#include "Player.hpp"

//OWL
class BirdO:public Player{
    private:
        int frate{};
        SDL_Texture* Tex1{};//for second frame of owl
        SDL_Texture* Tex2{};//for third frame of owl
        SDL_Texture* Tex3{};//for fourth frame of owl
    public:
        BirdO();
        ~BirdO();
        BirdO(const BirdO& other);
        void Render(SDL_Renderer* ren);
        void createTexture1(const char* address, SDL_Renderer* ren);
        void createTexture2(const char* address, SDL_Renderer* ren);
        void createTexture3(const char* address, SDL_Renderer* ren);
};