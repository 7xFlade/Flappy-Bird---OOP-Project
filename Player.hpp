#pragma once
#include "Object.hpp"

//Child class of Object, Parent of all Bird classes
class Player:public Object{
    private:
        //y axis coordinate
        double gravity=250;
        int time=0;
    public:
        void Update();
        void Gravity();
        double getYPos ();//const
        virtual void Render(SDL_Renderer* ren)=0;
        virtual void createTexture1(const char* address,SDL_Renderer* ren)=0;
        virtual void createTexture2(const char* address,SDL_Renderer* ren)=0;
        virtual void createTexture3(const char* address,SDL_Renderer* ren)=0;
        void Reset();
        
};