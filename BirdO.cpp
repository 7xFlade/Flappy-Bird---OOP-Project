#include "BirdB.hpp"
#include "TextureManager.hpp"
void BirdO::Render(SDL_Renderer* ren){
    
    frate++;
	if (frate < 16)
	{
		SDL_RenderCopyEx(ren, getTexture(), &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (frate >= 16 && frate <= 32)
	{
		SDL_RenderCopyEx(ren, Tex1, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (frate >32 && frate<=44)
	{
		SDL_RenderCopyEx(ren, Tex2, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
    else if (frate > 44)
	{
		SDL_RenderCopyEx(ren, Tex3, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	if (frate > 43)
	{
		frate = 0;
	}

}
void BirdO::createTexture1(const char* address, SDL_Renderer* ren){
    Tex1=TextureManager::Texture(address, ren);
}
void BirdO::createTexture2(const char* address, SDL_Renderer* ren){
    Tex2=TextureManager::Texture(address, ren);
}
void BirdO::createTexture3(const char* address, SDL_Renderer* ren){
    Tex2=TextureManager::Texture(address, ren);
}

