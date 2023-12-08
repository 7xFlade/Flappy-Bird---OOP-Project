#include "TextureManager.hpp"

// Function to load an image file and create an SDL_Texture
// Parameters:
//   filelocation: The file path of the image file to load
//   ren: The SDL_Renderer on which the texture will be rendered
// Returns:
//   SDL_Texture pointer representing the loaded texture
SDL_Texture* TextureManager::Texture(const char* filelocation, SDL_Renderer* ren) {
    // Load the image from file and store it in an SDL_Surface
    SDL_Surface* surface = IMG_Load(filelocation);

    // Create an SDL_Texture from the loaded surface using the provided renderer
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);

    // Release the allocated surface memory since it is no longer needed
    SDL_FreeSurface(surface);

    // Return the created texture
    return tex;
}
