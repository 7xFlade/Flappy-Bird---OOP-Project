#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Background.hpp"

class SelectBird
{
private:
    bool isChosenB;  // Flag to indicate whether a bird is chosen
    Background m;    // Background object for rendering
    int bird;        // Index representing the selected bird
public:
    // Constructor to initialize the SelectBird object
    SelectBird();

    // Function to initialize the SelectBird object, takes an SDL_Renderer for rendering
    void Initialize(SDL_Renderer* ren);

    // Function to handle events related to bird selection, returns the selected bird index
    int EventHandling(SDL_Event& b);

    // Function to render the bird selection screen on the provided renderer
    void Render(SDL_Renderer* ren);

    // Getter function to retrieve the status of whether a bird is chosen
    bool getChosenB();

    // Getter function to retrieve the index of the selected bird
    int getBird();
};
