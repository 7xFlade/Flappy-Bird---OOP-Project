#include "CollisionManager.hpp"

bool CollisionManager::checkCollision(SDL_Rect* A, SDL_Rect* B)
{
	//checking for collision using standard SDL function
    SDL_bool Collision = SDL_HasIntersection(A, B);
	if (Collision)
	{   return true;
	}
	else{
		return false;
    }
}

// bool CollisionManager::checkCollision(SDL_Rect* A, SDL_Rect* B) {
//     return SDL_HasIntersection(A, B) == SDL_TRUE;
// }
