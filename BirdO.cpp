#include "BirdB.hpp"
#include "TextureManager.hpp"

//constructor
BirdO::BirdO():Tex1(nullptr),Tex2(nullptr),Tex3(nullptr),frate(0){}

//destructor
BirdO::~BirdO(){
	Tex1=nullptr;
	Tex2=nullptr;
	Tex3=nullptr;
	std::cout<<"Owl destructed"<<std::endl;
}

//copy constructor
BirdO::BirdO(const BirdO& other):Tex1(other.Tex1),Tex2(other.Tex2),Tex3(other.Tex3),frate(other.frate){}

//Rendering between 4 frames of owl to make appear flying
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

//creating Texture for the 3 frames of the owl
void BirdO::createTexture1(const char* address, SDL_Renderer* ren){
    Tex1=TextureManager::Texture(address, ren);
}
void BirdO::createTexture2(const char* address, SDL_Renderer* ren){
    Tex2=TextureManager::Texture(address, ren);
}
void BirdO::createTexture3(const char* address, SDL_Renderer* ren){
    Tex2=TextureManager::Texture(address, ren);
}

