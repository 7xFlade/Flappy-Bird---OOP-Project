#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Object{
    private:
        SDL_Rect src,dest;
        SDL_Texture* Tex;
    public:
        Object();
        //mutators for SDL_Rects
        void setSource(int x, int y, int w, int h);
        void setDest(int x, int y, int w, int h);
        //Accessors of SDL_Rects
        SDL_Texture* getTexture();
        SDL_Rect& getSrc();
        SDL_Rect& getDest();

        void CreateTexture(const char* address, SDL_Renderer* ren);
        virtual void Render(SDL_Renderer* ren)=0;

};