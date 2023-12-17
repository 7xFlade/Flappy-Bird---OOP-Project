#include "BirdB.hpp"
#include "TextureManager.hpp"

//constructor
BirdY::BirdY():Tex1(nullptr),frate(0){}
//destructor
BirdY::~BirdY(){
	Tex1=nullptr;
	std::cout<<"Yellow bird destructed"<<std::endl;
}

//copy constructor
BirdY::BirdY(const BirdY& other):Tex1(other.Tex1),frate(other.frate){}

//Rendering the two frames of yellow birds
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

}
void BirdY::createTexture1(const char* address, SDL_Renderer* ren){
    Tex1=TextureManager::Texture(address, ren);
}

//following functions are defined only to make this class not abstract, because Player(parent) these functions are virtual
void BirdY::createTexture2(const char* address, SDL_Renderer* ren){
    std::cout<<"No need"<<std::endl;
}
void BirdY::createTexture3(const char* address, SDL_Renderer* ren){
    std::cout<<"No need"<<std::endl;
}
