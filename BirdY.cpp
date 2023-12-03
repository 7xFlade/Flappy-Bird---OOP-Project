#include "BirdB.hpp"
#include "TextureManager.hpp"
void BirdY::Render(SDL_Renderer* ren){
    
    frate++;
	if (frate < 10)
	{
		SDL_RenderCopyEx(ren, getTexture(), &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (frate >= 10 && frate <= 20)
	{
		SDL_RenderCopyEx(ren, Tex1, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	if (frate > 19)
	{
		frate = 0;
	}
//polymorphic behaviour
//we only need one more create texture operation since one instance of the bird is already instantiated when the game loads. After that we only have one more picture to cater
}
void BirdY::createTexture1(const char* address, SDL_Renderer* ren){
    Tex1=TextureManager::Texture(address, ren);
}

