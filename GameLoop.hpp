#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "Background.hpp"
#include "Mainmenu.hpp"
#include "SelectBird.hpp"
#include "Obstacles.hpp"
#include "CollisionManager.hpp"
#include "Score.hpp"
#include <iostream>
using namespace std;

class GameLoop {
private:
    bool Blue=false;
    Player p;
    Background b;
    Background ground1, ground2;
    Obstacles b1;
    Score score;
    MainMenu menu;
    SelectBird sb;
    //Obstacles brick; 
    const int Height = 600;
    const int Width = 800; 
    bool GameState;
    SDL_Window* window;
    SDL_Event event1;
    SDL_Renderer* renderer;
    //SDL_Texture* background;
public:
    GameLoop();
    void MainMenu();
    void SelectBird();
    bool getGameState();
    void Update();
    //void Reset();
    void CollisionDetection();
    void Initialize();
    void Event();
    void Render();
    void Clear();
};
