#pragma once
#include "SDL.h"

class Actor
{
public:
	SDL_Texture* texture;
	SDL_Rect rect;
	int rot;

	virtual bool Move();
};

