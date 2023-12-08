#include "TextManager.hpp"

// Function to load a font from a file and set its size
void TextManager::CreateFont(const char* fileAddress, int size)
{
    // Open the font from the specified file with the given size
    font = TTF_OpenFont(fileAddress, size);
    if (!font)
    {
        // Print an error message if the font fails to load
        std::cout << TTF_GetError() << std::endl;
    }
}

// Function to render text using the loaded font and specified color
void TextManager::Text(std::string Text, int r, int g, int b, SDL_Renderer* ren)
{
    // Convert std::string to char* for SDL_ttf compatibility
    char* Txt = new char[Text.size() + 1];
    std::copy(Text.begin(), Text.end(), Txt);
    Txt[Text.size()] = '\0';

    // Set the color for the text rendering
    SDL_Color color = { r, g, b, 255 };

    // Render the text onto an SDL_Surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, Txt, color);
    if (textSurface == NULL)
    {
        // Print an error message if text rendering fails
        std::cout << TTF_GetError() << std::endl;
    }

    // Create a texture from the rendered text surface
    CreateTexture(textSurface, ren);

    // Free the surface memory as it is no longer needed
    SDL_FreeSurface(textSurface);
    
    // Deallocate the char* memory
    delete[] Txt;
}

// Function to create an SDL_Texture from an SDL_Surface
void TextManager::CreateTexture(SDL_Surface* sur, SDL_Renderer* ren)
{
    // Create a texture from the given surface and set it as the font texture
    fontTexture = SDL_CreateTextureFromSurface(ren, sur);
}

// Function to render the text on the screen at the specified position
void TextManager::Render(SDL_Renderer* ren, int x, int y)
{
    // Set the position of the text rendering rectangle
    TextRect.x = x, TextRect.y = y;

    // Query the texture for its width and height
    SDL_QueryTexture(fontTexture, NULL, NULL, &TextRect.w, &TextRect.h);

    // Render the texture on the provided renderer at the specified position
    SDL_RenderCopy(ren, fontTexture, NULL, &TextRect);
}

// Function to close and deallocate the loaded font
void TextManager::CloseFont()
{
    // Close the loaded font
    TTF_CloseFont(font);
}
