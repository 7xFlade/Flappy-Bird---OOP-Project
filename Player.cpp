#include "Player.hpp"

// Function to update the player's state
void Player::Update() {
    time++;

    // Set the source rectangle for rendering
    setSource(0, 0, 65, 55);

    // If more than 100 updates have occurred, apply gravity
    if (time > 100) {
        gravity += 1.25; // Adjust gravity value based on requirements
        setDest(150, gravity, 65, 55);
    } else {
        // If less than or equal to 100 updates, keep the player at a fixed position
        setDest(150, 250, 65, 55);
    }
}

// Function to simulate gravity by adjusting the player's position
void Player::Gravity() {
    time++;

    // Set the source rectangle for rendering
    setSource(0, 0, 65, 55);

    // If more than 100 updates have occurred, apply upward acceleration
    if (time > 100) {
        gravity -= 10.5; // Adjust acceleration value based on requirements
        setDest(150, gravity, 65, 55);
    } else {
        // If less than or equal to 100 updates, keep the player at a fixed position
        setDest(150, 250, 65, 55);
    }
}

// Getter function to retrieve the Y position of the player
double Player::getYPos() {
    return gravity;
}

// Uncomment this function and add the necessary code when rendering is implemented
// void Player::Render(SDL_Renderer* ren) {
//     SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
// }
