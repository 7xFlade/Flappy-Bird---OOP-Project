#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "Background.hpp"
#include "Mainmenu.hpp"
#include <iostream>
using namespace std;

class GameLoop {
private:
    Player p;
    Background b;
    Background ground1, ground2;
    MainMenu menu;
    const int Height = 600;
    const int Width = 800; // Changed 'width' to 'Width' for consistency
    bool GameState;
    SDL_Window* window;
    SDL_Event event1;
    SDL_Renderer* renderer;
    //SDL_Texture* background;
public:
    GameLoop();
    void MainMenu();
    bool getGameState();
    void Update();
    void Initialize();
    void Event();
    void Render();
    void Clear();
};
