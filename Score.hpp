#pragma once

class Score
{
private:
    double score = 0;    // Current score value
    double highscore = 0; // Highest score achieved

public:
    // Function to increase the current score
    void scoreInc();

    // Function to set the highscore to a specific value
    // Parameters:
    //   x: The value to set as the new highscore
    void setHighscore(const double x);

    // Getter function to retrieve the current score
    // Returns:
    //   The current score value
    double getScore() const;

    // Getter function to retrieve the highscore
    // Returns:
    //   The highest score achieved
    double getHighscore() const;
};
