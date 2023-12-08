#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Background.hpp"

class PauseScreen
{
public:
    Background paused; // Background object for the pause screen

public:
    // Function to initialize the pause screen, loads background texture
    // Parameters:
    //   ren: The SDL_Renderer used for rendering
    void Initialize(SDL_Renderer* ren);

    // Function to render the pause screen on the provided renderer
    // Parameters:
    //   ren: The SDL_Renderer used for rendering
    void Render(SDL_Renderer* ren);
};
