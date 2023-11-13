#pragma once 

class Score{
    private:
        double score=0;
        double highscore=0;
    public:
        void scoreInc();
        void setHighscore(const double x);
        double getScore() const;
        double getHighschore() const;
};