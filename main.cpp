
#include "GameLoop.hpp"
GameLoop* g = new GameLoop();

int main(int argc, char* argv[]) {
    double first;
    double last;

    // Initialize the game loop and set highscore to 0
    g->Initialize();
    g->SetHighscore();
    do {
        g->setStartState(false);
        g->bgMusic();
        g->MainMenu();
        g->Instructions();
        g->SelectBird();
        while (g->getGameState()) {
            if (!g->getPauseState()) {
                g->Event();
                g->Update();
                g->Render();
                first = SDL_GetTicks();
                if (first - last < 20.7) {  // fps
                    SDL_Delay(20.7 - (first - last));
                }
                last = first;
            } else {
                g->Paused();
                g->Event();
            }
        }

        // End the game and check if restart is requested
        std::cout<<"game end"<<std::endl;
        std::cout<<g->getGameState()<<std::endl;
        g->Endgame();
        
    } while (g->getStartState());

    g->Clear();
    g->~GameLoop();
    delete g; // Don't forget to free the allocated memory
    g=nullptr;
    return 0;
}