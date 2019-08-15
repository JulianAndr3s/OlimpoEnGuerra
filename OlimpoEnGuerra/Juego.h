#pragma once
#include "Actor.h"
#include "Carta.h"
#include "render.h"
#include "Arbol.h"

class Juego
{
public:
	SDL_Rect RecF ; 
	SDL_Rect RecM ; 
	SDL_Rect RecG ; 
	SDL_Rect RecL ; 
	SDL_Rect RecP ; 
	SDL_Rect RecC ; 
	SDL_Rect RecRP;
	SDL_Rect RecRI;
	SDL_Rect RecRD;
	SDL_Rect RecAD;
	vector<SDL_Texture*> texturas;
	int Divinidad , Pueblo, Ejercito, Dinero;
	bool game ;
	bool cambio;
	int cambia;
	void creartexturas();
	void Pintar(SDL_Rect r, SDL_Texture* a, int x);
	SDL_Texture* loadImage(std::string a);
	SDL_Texture* loadText(std::string a);
	void Cargar();
	Juego();
	~Juego();
};

