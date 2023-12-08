#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
class TextManager
{
private:
	TTF_Font* font;
	SDL_Rect TextRect;
	SDL_Texture* fontTexture;
public:
	void CreateFont(const char* fileAddress, int size);
	void Text(std::string Text, int r, int g, int b, SDL_Renderer* ren);
	void CreateTexture(SDL_Surface* sur, SDL_Renderer* ren);
	void Render(SDL_Renderer* ren, int x, int y);
	void CloseFont();
};
