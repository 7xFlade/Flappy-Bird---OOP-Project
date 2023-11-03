#include "GameLoop.hpp"

GameLoop* g= new GameLoop();

int main(int argc, char* argv[]){
    g->Initialize();
    while (g->getGameState()){
        g->Render();
        g->Event();
        g->Update();
    }
    g->Clear();
    return 0;
}