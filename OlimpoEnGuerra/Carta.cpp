#include "Carta.h"

Carta::Carta(Uint8 izquierda, Uint8 derecha, Uint8 space, SDL_Texture * t, SDL_Rect r)
{
	tIzquierda = izquierda;
	tDerecha = derecha;
	tSpace = space;
	texture = t;
	rect = r;
	rot = 0;

}

Carta::Carta(SDL_Rect r, SDL_Texture* t) {
	rect = r;
	texture = t;
	rot = 0;
}

bool Carta::Move() {
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	
	if (state[tSpace]) {
		rect.x = 496;
		rect.y = 85;
		return true;
	}
		
	if (state[tIzquierda]) {
		rect.x = 487;
		rect.y = 85;
		return true;

	}
	if (state[tDerecha]) {
		rect.x = 507;
		rect.y = 85;
		return true;
	}

	return false;
}
