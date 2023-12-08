#pragma once
#include "GameLoop.hpp"
class TextureManager
{
    public:
        static SDL_Texture* Texture(const char* filelocation, SDL_Renderer* ren);
};
