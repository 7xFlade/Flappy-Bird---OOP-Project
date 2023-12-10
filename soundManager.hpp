#pragma once
#include <SDL.h>
#include <SDL_mixer.h>


//Sound class
class SDLManager {
public:
    SDLManager();
    ~SDLManager();

    bool initializeSDL();
    bool loadMedia();
    bool loadMedia1();
    void closeSDL();
private:
    Mix_Music* bgMusic;
};

