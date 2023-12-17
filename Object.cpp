#include "Object.hpp"
#include "TextureManager.hpp"

//constructor
Object::Object(){
    Tex=nullptr;
}

Object::~Object(){
    std::cout<<"Object destructed"<<std::endl;
}

//Accesors
SDL_Texture* Object::getTexture() {
    return Tex;
}
SDL_Rect& Object::getSrc(){
    return src;
}
SDL_Rect& Object::getDest(){
    return dest;
}
//mutator
void Object::setSource(int x, int y, int w, int h){
    src.x=x;
    src.y=y;
    src.w=w;
    src.h=h;
}
void Object::setDest(int x, int y, int w, int h){
    dest.x=x;
    dest.y=y;
    dest.w=w;
    dest.h=h;
}

//creating texture of all bjects
void Object::CreateTexture(const char* address, SDL_Renderer* ren){
    Tex=TextureManager::Texture(address, ren);
}