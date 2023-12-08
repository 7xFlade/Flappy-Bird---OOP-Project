#pragma once
#include "Object.hpp"

class Player : public Object {
private:
    double gravity = 250; // Gravity affecting the player
    double speed = 0;     // Speed of the player's movement
    int time = 0;         // Time variable (not specified for what purpose)

public:
    // Function to update the player's state
    void Update();

    // Function to apply gravity to the player
    void Gravity();

    // Getter function to retrieve the Y position of the player
    // Returns:
    //   The Y position of the player
    double getYPos(); // const

    // Pure virtual function to render the player on the screen
    // Parameters:
    //   ren: The SDL_Renderer used for rendering
    virtual void Render(SDL_Renderer* ren) = 0;
};
