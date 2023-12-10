#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "TextureManager.hpp"
#include "Background.hpp"
#include "Object.hpp"
#include "Player.hpp"
#include "Mainmenu.hpp"
#include "SelectBird.hpp"
#include "Obstacles.hpp"
#include "CollisionManager.hpp"
#include "EndWindow.hpp"
#include "BirdB.hpp"
#include "BirdY.hpp"
#include "BirdO.hpp"
#include "Score.hpp"
#include "PauseScreen.hpp"
#include "Instruction.hpp"
#include "soundManager.hpp"
#include "NueralNetwork.hpp"
#include <iostream>
using namespace std;



//While the game is running this class will be implemented with the help of all the other classes
class GameLoop {
private:
    Player *p;//blue bird
    Player *y;// yellow bird
    Player *o;//owl
    Background b;//Static background
    Background ground1, ground2;//base of the background

    //Obstacles
    Obstacles Pipe_Above1;
	Obstacles Pipe_Below1;
	Obstacles Pipe_Above2;
	Obstacles Pipe_Below2;
	Obstacles Pipe_Above3;
	Obstacles Pipe_Below3;


    SDLManager sound;
    NeuralNetwork neuralNetwork;
    Score score;
    MainMenu menu;
    SelectBird sb;
    EndWindow ew;
    Instructions ins;
    PauseScreen PScreen;

    //Dimensions of the window
    const int Height = 600;
    const int Width = 800; 

    //Helpful for continuos generation of obstacles
    int points = 0;
	int generations = 0;
	int nextCheckPoint = 0;
	int variance1 = rand() % 201 - 100;
	int variance2 = rand() % 201 - 100;
	int variance3 = rand() % 201 - 100;

    //To check which states we are in
    bool GameState;
    bool startState;
    bool PauseState;

    SDL_Window* window;
    SDL_Event event1;
    SDL_Renderer* renderer;
    int timer=0;
    int t1=0;
    int s=0;
    int score1=0;
    
public:
    GameLoop();
    ~GameLoop();
    void SetHighscore();
    void MainMenu();
    void Instructions();
    void SelectBird();
    void Paused();
    void Endgame();
    bool getGameState() const;
    bool getPauseState() const;
    bool getStartState() const;
    void Update();
    void setStartState(const bool x);
    void Reset();
    void CollisionDetection();
    void Initialize();
    void Event();
    void Render();
    void Clear();
    void bgMusic();
};