#include "CollisionManager.hpp"

//Checks for collision by finding intersection of two sdl_Rects
bool CollisionManager::checkCollision(SDL_Rect *A, SDL_Rect *B)
{
	SDL_bool Collision = SDL_HasIntersection(A, B);
	if (Collision)
	{
		return true;
	}
	else
	{
		return false;
	}
}