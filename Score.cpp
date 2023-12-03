#include "Score.hpp"
//this is one functionality of the increment operation
//adding the overloaded functionality soon
void Score::scoreInc(){
    score++;
}
//current score value is compared everytime to the existing high score value
void Score::setHighscore(const double x){
    if (x>=highscore){
        highscore=x;
    }
}
//the following are standard getters for both the score and the high score      
double Score::getScore() const{
    return score;
}
        
double Score::getHighschore() const{
    return highscore;
}
