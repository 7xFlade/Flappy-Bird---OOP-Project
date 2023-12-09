#include <SDL.h>
#include <SDL_audio.h>
//initializing constant values for the sound properties
const int sampleRate = 44100;
const Uint16 audioFormat = AUDIO_S16SYS;
const int channels = 2;
const int chunkSize = 4096;

SDL_AudioSpec desired, obtained;
Uint32 deviceId;

void audioCallback(void* userdata, Uint8* stream, int len) {
    SDL_memset(stream, 0, len);
}

int main(int argc, char* argv[]) {
    //initializing error just in case
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        SDL_Log("SDL initialization failed: %s", SDL_GetError());
        return 1;
    }
    //setting up values according to the constants declared earlier
    desired.freq = sampleRate;
    desired.format = audioFormat;
    desired.channels = channels;
    desired.samples = chunkSize;
    desired.callback = audioCallback;

    deviceId = SDL_OpenAudioDevice(NULL, 0, &desired, &obtained, 0);
    //initializing error for audio device just in case
    if (deviceId == 0) {
        SDL_Log("Failed to open audio device: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8* wavBuffer;
    //loading audio according to its path on the computer
    if (SDL_LoadWAV("path/to/your/audio/file.wav", &wavSpec, &wavBuffer, &wavLength) == NULL) {
        //initializing loading error just in case
        SDL_Log("Failed to load WAV file: %s", SDL_GetError());
        SDL_CloseAudioDevice(deviceId);
        SDL_Quit();
        return 1;
    }

    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0); // Start playing audio

    // Delayig the audio by a certain amount of time
    SDL_Delay(5000); // Wait for 5000 milliseconds (5 seconds) as an example

    // Cleaning up all resources
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();

    return 0;
}
