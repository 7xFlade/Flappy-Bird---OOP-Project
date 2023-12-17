#include "soundManager.hpp"
#include <stdio.h>

//constructor
SDLManager::SDLManager() : bgMusic(nullptr) {}

//destructor
SDLManager::~SDLManager() {
    bgMusic=nullptr;
    closeSDL();
}

//checking if the sdl extension for sound is initialized prperly or not
bool SDLManager::initializeSDL() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    return true;
}

//loading the background music file
bool SDLManager::loadMedia() {
    bgMusic = Mix_LoadMUS("bg_music.wav");
    if (bgMusic == NULL) {
        printf("Unable to load music: %s \n", Mix_GetError());
        return false;
    }
    Mix_PlayMusic(bgMusic, -1);//play it indefinitely
    return true;
}

//loading the collison music file
bool SDLManager::loadMedia1() {
    bgMusic = Mix_LoadMUS("collision_sound.wav");
    if (bgMusic == NULL) {
        printf("Unable to load music: %s \n", Mix_GetError());
        return false;
    }
    Mix_PlayMusic(bgMusic, 1);//play it indefinitely
    return true;
}

//closing sdl music
void SDLManager::closeSDL() {
    Mix_FreeMusic(bgMusic);
    Mix_Quit();
}


