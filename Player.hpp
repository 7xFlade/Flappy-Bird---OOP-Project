#pragma once
#include "Object.hpp"

class Player:public Object
{
    private:
        double gravity=250;
        double speed=0;
        int time=0;
    public:
        void Update();
        void Gravity();
        double getYPos ();//const
        virtual void Render(SDL_Renderer* ren)=0;
        
};
