#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
class render
{
public:
	bool initialize(int w, int h, int fps, bool hw);
	SDL_Renderer* getrender();
	static render* getinstance();
	void AddTexture(SDL_Texture *t, SDL_Rect &r);
	void Renderize();
	SDL_Renderer* srender;
	render();
	SDL_Window * swindow;
	static render* instancia;

private:

};


