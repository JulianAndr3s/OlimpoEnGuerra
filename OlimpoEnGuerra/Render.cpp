#include "Render.h"



render* render::instancia = nullptr;
render::render()
{
}
SDL_Renderer* render::getrender()
{
	return srender;
}
render* render::getinstance() {
	if (instancia == nullptr) {
		instancia = new render();
	}
	return instancia;
}
bool render::initialize(int w, int h, int fps, bool hw)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}
	swindow = SDL_CreateWindow(
		"Olimpo En Guerra",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		w, h,
		0);
	if (swindow == NULL) {
		return false;

	}
	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;
	IMG_Init(imgFlags);
	TTF_Init();
	Mix_Music * music;
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	music = Mix_LoadMUS("Utilidades/Cancion.mp3");
	Mix_PlayMusic(music, -1);
	srender = SDL_CreateRenderer(swindow, -1, hw ? SDL_RENDERER_ACCELERATED : SDL_RENDERER_SOFTWARE);
	return true;
}
void render::AddTexture(SDL_Texture *t, SDL_Rect &r)
{
	SDL_RenderCopy(srender, t, NULL, &r);
}
void render::Renderize()
{
	SDL_PumpEvents();
	SDL_RenderPresent(srender);
	SDL_RenderClear(srender);
	SDL_Delay(100);
}

