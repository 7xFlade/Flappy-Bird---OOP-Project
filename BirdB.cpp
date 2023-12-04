#include "BirdB.hpp"
#include "TextureManager.hpp"
// The Render method is used to render the bird based on its frame rate
void BirdB::Render(SDL_Renderer* ren){
    
    frate++;
	if (frate < 16)
	{
		SDL_RenderCopyEx(ren, getTexture(), &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (frate >= 16 && frate <= 32)
	{
		SDL_RenderCopyEx(ren, Tex1, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (frate > 32)
	{
		SDL_RenderCopyEx(ren, Tex2, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	if (frate > 48)
	{
		frate = 0;
	}
//polymorphic behaviour
//we need two more create texture operation since one instance of the bird is already instantiated when the game loads. After that we only have two more pictures to cater out of the four for BirdB
}

// createTexture1 and createTexture2 methods are used to create additional textures
void BirdB::createTexture1(const char* address, SDL_Renderer* ren){
    Tex1=TextureManager::Texture(address, ren);
}
void BirdB::createTexture2(const char* address, SDL_Renderer* ren){
    Tex2=TextureManager::Texture(address, ren);
}
