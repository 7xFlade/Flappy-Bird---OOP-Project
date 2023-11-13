#include "Player.hpp"

void Player::Render(SDL_Renderer* ren){
    SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}
void Player::Update(){//edit it in a way that until space bar is not pressed for the first time, let the bird fly straight, can be done by making changes in update, gravity and event function in gameloop
    //gravity+=0.5;
    time++;
    setSource(0,0,65,55);
    if (time>100){
        gravity+=1;//0.5 if space bar
        setDest(250,gravity,65,55);}
    else{
        setDest(250,250,65,55);
        }
    
}
void Player::Gravity(){//upward acceleration when space bar clicked
    gravity-=10.5;//-10 if up key -70.5 if spce
    setSource(0,0,65,55);
    setDest(250,gravity,65,55);
}

double Player::getYPos(){
    return gravity;
}