#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Object
{
private:
    SDL_Rect src;       // Source rectangle for texture rendering
    SDL_Rect dest;      // Destination rectangle for texture rendering
    SDL_Texture* Tex;   // Texture for the object

public:
    // Default constructor for the Object class
    Object();

    // Setter function to set the source rectangle parameters
    // Parameters:
    //   x, y: Top-left corner coordinates of the source rectangle
    //   w, h: Width and height of the source rectangle
    void setSource(int x, int y, int w, int h);

    // Setter function to set the destination rectangle parameters
    // Parameters:
    //   x, y: Top-left corner coordinates of the destination rectangle
    //   w, h: Width and height of the destination rectangle
    void setDest(int x, int y, int w, int h);

    // Getter function to retrieve the texture associated with the object
    SDL_Texture* getTexture();

    // Getter function to retrieve the source rectangle
    SDL_Rect& getSrc();

    // Getter function to retrieve the destination rectangle
    SDL_Rect& getDest();

    // Function to load a texture from a file and set it as the object's texture
    // Parameters:
    //   address: File address of the texture image
    //   ren: SDL_Renderer used for rendering
    void CreateTexture(const char* address, SDL_Renderer* ren);

    // Pure virtual function for rendering the object on the provided renderer
    // Parameters:
    //   ren: SDL_Renderer used for rendering
    virtual void Render(SDL_Renderer* ren) = 0;
};
