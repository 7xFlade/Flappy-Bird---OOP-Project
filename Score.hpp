#pragma once 

//Manages score in a single game loop, and highscore over several restarts
class Score{
    private:
        int score;
        int highscore=0;
        
    public:
        
        void setscore(const int x);
        void setHighscore(const int x);
        int getScore() const;
        int getHighschore() const;
        int operator++(int);
        void operator=(const int x);
        
};