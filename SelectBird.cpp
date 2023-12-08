#include "SelectBird.hpp"

// Constructor to initialize SelectBird object
SelectBird::SelectBird() {
    isChosenB = false;
}

// Function to initialize SelectBird, loads background texture
void SelectBird::Initialize(SDL_Renderer* ren) {
    m.CreateTexture("image/sb.png", ren);
}

// Function to handle mouse events for bird selection
// Returns: -1 if SDL_QUIT event occurs, 0 otherwise
int SelectBird::EventHandling(SDL_Event& b) {
    // Poll for SDL events
    SDL_PollEvent(&b);

    // Check for SDL_QUIT event
    if (b.type == SDL_QUIT) {
        return -1;
    }
    // Check if the user clicked on the first bird
    else if (b.type == SDL_MOUSEBUTTONDOWN && b.motion.x > 100 && b.motion.x < 250 && b.motion.y > 280 && b.motion.y < 350) {
        bird = 1;
        isChosenB = true;
    }
    // Check if the user clicked on the second bird
    else if (b.type == SDL_MOUSEBUTTONDOWN && b.motion.x > 350 && b.motion.x < 500 && b.motion.y > 280 && b.motion.y < 350) {
        bird = 2;
        isChosenB = true;
    }
    // Check if the user clicked on the third bird
    else if (b.type == SDL_MOUSEBUTTONDOWN && b.motion.x > 550 && b.motion.x < 730 && b.motion.y > 280 && b.motion.y < 350) {
        bird = 3;
        isChosenB = true;
    }

    // Return 0 to indicate that no SDL_QUIT event occurred
    return 0;
}

// Function to render the background texture
void SelectBird::Render(SDL_Renderer* ren) {
    m.Render(ren);
}

// Getter function to retrieve the status of whether a bird is chosen
bool SelectBird::getChosenB() {
    return isChosenB;
}

// Getter function to retrieve the index of the selected bird
int SelectBird::getBird() {
    return bird;
}
