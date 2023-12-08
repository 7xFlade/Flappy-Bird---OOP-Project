#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Background.hpp"

// MainMenu class representing the main menu of the game
class MainMenu
{
public:
    bool isClicked;            // Flag indicating if a button in the menu is clicked
    Background menuBackground;  // Background object for the main menu

public:
    // Default constructor for the MainMenu class
    MainMenu();

    // Destructor for the MainMenu class
    ~MainMenu();

    // Function to initialize the main menu, loads background texture
    // Parameters:
    //   ren: The SDL_Renderer used for rendering
    void Initialize(SDL_Renderer* ren);

    // Function to handle events in the main menu
    // Parameters:
    //   e: Reference to the SDL_Event object for event handling
    // Returns:
    //   An integer indicating the event result
    int EventHandling(SDL_Event& e);

    // Function to render the main menu on the provided renderer
    // Parameters:
    //   ren: The SDL_Renderer used for rendering
    void Render(SDL_Renderer* ren);

    // Getter function to retrieve the state of the isClicked flag
    // Returns:
    //   A boolean indicating if a button in the menu is clicked
    bool getClicked();
};
