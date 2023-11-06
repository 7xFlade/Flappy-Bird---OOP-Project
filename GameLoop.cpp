#include "GameLoop.hpp"

GameLoop::GameLoop() : window(nullptr), renderer(nullptr), GameState(false) {
    p.setSource(0,0,65, 55);
    p.setDest(10,20,65,55);

}

bool GameLoop::getGameState(){
    return GameState;
}

void GameLoop::Initialize() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_RESIZABLE);

    if (window) {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) { 
            cout << "Succeeded!" << endl;
            GameState= true;
            p.CreateTexture("image/Frame-1 (1).png", renderer);    
            b.CreateTexture("image/bg.png", renderer);
        } else {
            cout << "Renderer not created" << endl;
        }
    } else {
        cout << "Window not created" << endl;
    }
}

void GameLoop::Event(){
    SDL_PollEvent(&event1);
    if (event1.type==SDL_QUIT){
        GameState=false;
    }
    //Mouse Events
    // if (event1.type==SDL_MOUSEMOTION){
    //     cout<<event1.motion.x<<" "<<event1.motion.y<<endl;
    // }
    // if(event1.type==SDL_MOUSEBUTTONDOWN){
    //     cout<<"Pressed"<<endl;
    // }
    //Keyboard Events
    if (event1.type==SDL_KEYDOWN){
        if (event1.key.keysym.sym==SDLK_SPACE){//specific to space key
            cout<<"Pressed"<<endl;
            p.Gravity();
        }
    }
}

void GameLoop::Update(){
    p.Update();
    
}

void GameLoop::Render() {
    SDL_RenderClear(renderer);
    b.Render(renderer);
    p.Render(renderer);
    SDL_RenderPresent(renderer);
}

void GameLoop::Clear() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
