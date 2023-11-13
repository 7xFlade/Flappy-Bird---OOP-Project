#include "Score.hpp"

void Score::scoreInc(){
    score++;
}

void Score::setHighscore(const double x){
    if (x>=highscore){
        highscore=x;
    }
}
        
double Score::getScore() const{
    return score;
}
        
double Score::getHighschore() const{
    return highscore;
}