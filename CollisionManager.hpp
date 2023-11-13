#pragma once
#include<SDL.h>
#include<SDL_image.h>
class CollisionManager{
    private:
        bool collided=false;
    public:
        static bool checkCollision(SDL_Rect* A, SDL_Rect* B);
};