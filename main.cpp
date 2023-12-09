#include "GameLoop.hpp"

GameLoop* g= new GameLoop();

int main(int argc, char* argv[]){
    double first;
    double last;
    //calling the game initializer function
    g->Initialize();
    //loading the game main menu
    g->MainMenu();
    //loading the select bird function
    g->SelectBird();
    //loading different functionalities of the game according to the game state
    while (g->getGameState()){
        // g->Render();
        g->Event();
        g->Update();
        g->Render();
        first=SDL_GetTicks();
        if (first-last<20.7){//fps
            SDL_Delay(20.7-(first-last));
        }
        last=first;
    }
    g->Endgame();
    //clearing all resources
    g->Clear();
    return 0;
}
