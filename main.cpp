#include "GameLoop.hpp"

GameLoop* g= new GameLoop();

int main(int argc, char* argv[]){
    double first;
    double last;
    g->Initialize();
    g->MainMenu();
    g->SelectBird();
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
    g->Clear();
    return 0;
}