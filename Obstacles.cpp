#include "Obstacles.hpp"

void Obstacles::Render(SDL_Renderer* ren){
    SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}
void Obstacles::Update(){
    leftward-=3;
    setSource(0,0,52,320);
    setDest(leftward,200,100,320);
}
