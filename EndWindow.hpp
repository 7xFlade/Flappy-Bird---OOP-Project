#pragma once
#include "Background.hpp"

class EndWindow{
    public:
        bool restart=false;
        Background endBackground; 
        // int score = 0;
        // int prevScore = 0;
        // char buffer[50];
        // int texW = 0;
        // int texH = 0;
        // SDL_Texture* texture = nullptr;
        // SDL_Surface* surface = nullptr;
        // SDL_Renderer* renderer;
        // TTF_Font* font;
        // SDL_Color text_color = {255, 255, 255};
    public:
        ~EndWindow();
        void Initialize(SDL_Renderer* ren);
        int EventHandling(SDL_Event& e);
        void Render(SDL_Renderer* ren);
        bool getRestart();
};