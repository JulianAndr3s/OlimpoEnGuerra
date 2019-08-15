#pragma once
#include <vector>
#include "Actor.h"

class Carta : public Actor
{
private:
	Uint8 tIzquierda, tDerecha, tSpace;
public:
	Carta(SDL_Rect r, SDL_Texture* t);
	Carta(Uint8 izquierda, Uint8 derecha, Uint8 space, SDL_Texture* t, SDL_Rect r);
	bool Move();
	

};

