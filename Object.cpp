#include "Object.hpp"
#include "TextureManager.hpp"

// Default constructor for the Object class
Object::Object() {
    Tex = NULL; // Initialize the texture pointer to NULL
}

// Getter function to retrieve the texture associated with the object
SDL_Texture* Object::getTexture() {
    return Tex;
}

// Getter function to retrieve the source rectangle
SDL_Rect& Object::getSrc() {
    return src;
}

// Getter function to retrieve the destination rectangle
SDL_Rect& Object::getDest() {
    return dest;
}

// Setter function to set the source rectangle parameters
// Parameters:
//   x, y: Top-left corner coordinates of the source rectangle
//   w, h: Width and height of the source rectangle
void Object::setSource(int x, int y, int w, int h) {
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
}

// Setter function to set the destination rectangle parameters
// Parameters:
//   x, y: Top-left corner coordinates of the destination rectangle
//   w, h: Width and height of the destination rectangle
void Object::setDest(int x, int y, int w, int h) {
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
}

// Function to load a texture from a file and set it as the object's texture
// Parameters:
//   address: File address of the texture image
//   ren: SDL_Renderer used for rendering
void Object::CreateTexture(const char* address, SDL_Renderer* ren) {
    Tex = TextureManager::Texture(address, ren);
}
