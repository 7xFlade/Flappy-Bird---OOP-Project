#include "Score.hpp"

//operator overloading obj++
int Score::operator++(int)
{
    int x=score+1;
    return x;
}

//mutating it 
void Score::setscore(const int x)
{
    score=x;
    
}

//if score>highscore
void Score::setHighscore(const int x){
    if (x>highscore){
        highscore=x;
    }
}

//Accessors of score and highscore    
int Score::getScore() const
{
    return score;
}
        
int Score::getHighschore() const
{
    return highscore;
}
