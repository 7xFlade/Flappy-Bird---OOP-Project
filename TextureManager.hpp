#pragma once
#include "GameLoop.hpp"
//creates all the textures
class TextureManager
{
    public:
        static SDL_Texture* Texture(const char* filelocation, SDL_Renderer* ren);
};
