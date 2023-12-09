#pragma once
#include<SDL.h>
#include<SDL_image.h>
class CollisionManager{
    private:
        //state for collision
        bool collided=false;
    public:
        //function to check collision
        static bool checkCollision(SDL_Rect* A, SDL_Rect* B);
};
