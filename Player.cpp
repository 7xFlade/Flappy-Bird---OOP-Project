#include "Player.hpp"


void Player::Update(){//constant downward gravity
    time++;
    setSource(0,0,65,55);
    if (time>100){//to not start updating immediately
        gravity+=1.25;
        setDest(150,gravity,65,55);}
    else{
        setDest(150,250,65,55);
        }
    
}

//manages the upward motion of bird when up key is pressed
void Player::Gravity(){
    time++;
    setSource(0,0,65,55);
    if (time>100){//to not start updating immediately
        gravity-=10.5;//0.5 if space bar
        setDest(150,gravity,65,55);}
    else{
        setDest(150,250,65,55);
        }
}

//Accessor of y axis
double Player::getYPos(){
    return gravity;
}

//resetting all the initial values of this class, for restart
void Player::Reset(){
    double gravity=250;
    double speed=0;
    int time=0;
    setSource(150,250,65,55);
    setDest(150,250,65,55);
}

//virtual destructor because an abstract class
Player::~Player(){
    std::cout<<"Player destructed"<<std::endl;
}