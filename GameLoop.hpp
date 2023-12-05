#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "Background.hpp"
#include "Mainmenu.hpp"
#include "SelectBird.hpp"
#include "Obstacles.hpp"
#include "CollisionManager.hpp"
#include "EndWindow.hpp"
#include "BirdB.hpp"
#include "BirdY.hpp"
#include "BirdO.hpp"
#include "Score.hpp"
#include "NueralNetwork.hpp"
#include <iostream>
using namespace std;

class GameLoop 
{
private:
    BirdB p;
    BirdY y;
    BirdO o;
    Background b;
    Background ground1, ground2;
    Obstacles Pipe_Above1;
	Obstacles Pipe_Below1;
	Obstacles Pipe_Above2;
	Obstacles Pipe_Below2;
	Obstacles Pipe_Above3;
    NeuralNetwork neuralNetwork;
	Obstacles Pipe_Below3;
    Score score;
    MainMenu menu;
    SelectBird sb;
    EndWindow ew;
    const int Height = 600;
    const int Width = 800; 
    int points = 0;
	int generations = 0;
	int nextCheckPoint = 0;
	int variance1 = rand() % 201 - 100;
	int variance2 = rand() % 201 - 100;
	int variance3 = rand() % 201 - 100;
    bool GameState;
    SDL_Window* window;
    SDL_Event event1;
    SDL_Renderer* renderer;
    int timer=0;
    int t1=0;
    int score1=0;
    
public:
    GameLoop();
    void MainMenu();
    void SelectBird();
    void Endgame();
    bool getGameState();
    void Update();
    //void Reset();
    void CollisionDetection();
    void Initialize();
    void Event();
    void Render();
    void Clear();
};
