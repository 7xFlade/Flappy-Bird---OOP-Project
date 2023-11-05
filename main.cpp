#include "GameLoop.hpp"

GameLoop* g= new GameLoop();

int main(int argc, char* argv[]){
    double first;
    double last;
    g->Initialize();
    while (g->getGameState()){
        g->Render();
        g->Event();
        g->Update();
        first=SDL_GetTicks();
        if (first-last<16.7){//fps
            SDL_Delay(16.7-(first-last));
        }
        last=first;

    }
    g->Clear();
    return 0;
}