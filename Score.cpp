#include "Score.hpp"

//operator overloading obj++
//here instead of using a function to update the score, we are simply making use of an overloaded iterator
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
//directly calling set high score function
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
//following is to access and return highscore value
int Score::getHighschore() const
{
    return highscore;
}
