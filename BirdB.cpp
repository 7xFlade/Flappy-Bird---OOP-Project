#include "BirdB.hpp"
#include "TextureManager.hpp"

//constructor
BirdB::BirdB():Tex1(nullptr),Tex2(nullptr),frate(0){}

BirdB::~BirdB(){
	Tex1=nullptr;
	Tex2=nullptr;
	std::cout<<"Blue bird destructed"<<std::endl;
}
//copy constructor
BirdB::BirdB(const BirdB& other):Tex1(other.Tex1),Tex2(other.Tex2),frate(other.frate){}

//rendering between 3 frames of blue birds to make its wings flap
void BirdB::Render(SDL_Renderer* ren){

    frate++;
	if (frate < 16)//switch to next frame 
	{
		SDL_RenderCopyEx(ren, getTexture(), &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (frate >= 16 && frate <= 32)//other frame in between these intervals of time
	{
		SDL_RenderCopyEx(ren, Tex1, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (frate > 32)
	{
		SDL_RenderCopyEx(ren, Tex2, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	if (frate > 48)
	{
		frate = 0;//start over from first frame
	}

}

//For the seconf and third frame of the blue bird
void BirdB::createTexture1(const char* address, SDL_Renderer* ren){
    Tex1=TextureManager::Texture(address, ren);
}
void BirdB::createTexture2(const char* address, SDL_Renderer* ren){
    Tex2=TextureManager::Texture(address, ren);
}
void BirdB::createTexture3(const char* address, SDL_Renderer* ren){
    std::cout<<"No need"<<std::endl;
}

