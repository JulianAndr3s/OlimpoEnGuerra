#include "Juego.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

void Juego::Pintar(SDL_Rect r, SDL_Texture* a, int x) {

	render* ren = render::getinstance();
	SDL_Rect Coor = r;
	
	int Tipo = x;
	// 1 = TEXTO;
	// 0 = IMAGEN

	if (Tipo == 1) {

		ren->AddTexture(a, Coor);
	}

	else if (Tipo == 0){

		ren->AddTexture(a, Coor);
		
	}
}


void Juego::Cargar() {
	srand(time(NULL));
	render* ren = render::getinstance();
	ren->initialize(1366, 768, 225, true);

	// Textos.
	creartexturas();
	SDL_Texture* a = loadText("¿Eres tú gran rey?");
	SDL_Texture* ard = loadText("Si");
	SDL_Texture* ari =loadText( "No");
	SDL_Texture* d = loadText("Lo se, eres el mas fuerte");
	SDL_Texture* Intro =loadText( "<< Abre la boca, cierra los ojos y mira cuánto te enviará Zeus >>");
	SDL_Texture* GameOver = loadText("<< Has perdido, los dioses no estan muy felices contigo, ha llegado la muerte a buscarte. >>");
	//Rectangulos.

	

	
	/*SDL_Rect RecPjH = { 525, 210, 340, 370 }; // Personaje Hermes.
	SDL_Rect RecPjA = { 495, 210, 380, 370 }; // Personaje Atenea.
	SDL_Rect RecPjE = { 520, 210, 345, 375 }; // Personaje Espartano.
	SDL_Rect RecPjG = { 540, 230, 330, 360 }; // Personaje Granjera.
	SDL_Rect RecPjJ = { 540, 230, 330, 360 }; // Personaje Justicia.*/

	SDL_Rect RecPj =  { 495, 210, 390, 390 }; // Personaje Zeus.
	SDL_Rect RecPj2 = { 495, 210, 410, 370 }; // Personaje Dos.
	SDL_Rect RecPjI = { 440, 215, 390, 390 }; // Personaje Zeus izquierda.
	SDL_Rect RecPjD = { 550, 215, 390, 390 }; // Personaje Zeus derecha.

	//Direcciones.

	
	SDL_Texture* DirM = loadImage("Utilidades/Personajes/Humanos/Muerte.png");
	SDL_Texture* DirPJ =loadImage( "Utilidades/Personajes/Dioses/Zeus.png");
	SDL_Texture* DirPJ2 = loadImage("Utilidades/Personajes/Dioses/Poseidon.png");


	Actor* carta = new Carta(SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_SPACE, loadImage("Utilidades/Cartas/Carta.png"), RecC);
	Actor* carta2 = new Carta(SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_SPACE, loadImage("Utilidades/Cartas/Carta2.png"), RecC);
	Actor* carta3 = new Carta(SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_SPACE, loadImage("Utilidades/Cartas/Carta3.png"), RecC);
	Actor* carta4 = new Carta(SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_SPACE, loadImage("Utilidades/Cartas/Carta4.png"), RecC);
	Actor* carta5 = new Carta(SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_SPACE, loadImage("Utilidades/Cartas/Carta5.png"), RecC);

	//Juego.


	while (game) {
		
		string TextDiv = to_string(Divinidad) +"          " +to_string(Pueblo)
		+"          "+to_string(Ejercito)+"         "+to_string(Dinero);
		
		ren->AddTexture(loadImage("Utilidades/Fondo2B.png"), RecF);
		ren->AddTexture(loadImage("Utilidades/Logo2.png"),RecL);
		ren->AddTexture(Intro,RecM);
		ren->AddTexture(loadText(TextDiv),RecAD);
		

		if (Divinidad <= 0 || Pueblo <= 0 || Ejercito <= 0 || Dinero <= 0) {
			game = false;
			
		}

		if (carta->Move()) {
			
			ren->AddTexture(carta->texture, carta->rect);
			if (carta->rect.x == 496) {
				
				ren->AddTexture(carta2->texture, carta2->rect);
				ren->AddTexture(d,RecRP);
				cambio = true;
			}

			else if (carta->rect.x == 487 && cambio == false) { 
				Pintar(RecPjI, DirPJ,0);
				Pintar(RecRI, ari,1);
				cambio = false;
				Divinidad -= 2; //Para mirar que cambia los numeros.
				Pueblo += 2;
			}
			else if (carta->rect.x == 507 && cambio == false) {
				Pintar(RecPjD, DirPJ,0);
				Pintar(RecRD, ard,1);
				cambio = false;   
				Divinidad += 2; //Para mirar que cambia los numeros.
				Pueblo -= 2;
			}
		}
		else if (cambio == false) {
			
			ren->AddTexture(carta->texture, RecC);
			Pintar(RecPj, DirPJ,0);
			Pintar(RecP,a,1);

		}
		else if (cambio == true ) {

			ren->AddTexture(carta2->texture, RecC);
			Pintar(RecPj2, DirPJ2,0);
			Pintar(RecRP,d,1);

			carta = carta2;
			carta->rect.x = 497;
			cambio = false;
			DirPJ = DirPJ2;
			
			a = d;
			RecP = RecRP;

		}
		
		ren->Renderize();
	}


	if (game == false){
		
		ren->AddTexture(loadImage("Utilidades/Fondo2B.png"), RecF);
		ren->AddTexture(loadImage("Utilidades/Logo2.png"), RecL);
		ren->AddTexture(carta->texture, RecC);
		ren->AddTexture(DirM, RecC);
		ren->AddTexture(GameOver,RecG);
		ren->Renderize();
		system("pause");
	}
}

SDL_Texture * Juego::loadImage(std::string a) {
	auto img = IMG_Load(a.c_str());
	auto texture = SDL_CreateTextureFromSurface(render::getinstance()->getrender(), img);
	return texture;

}
SDL_Texture* Juego::loadText(std::string a) {
	TTF_Font* fuente = TTF_OpenFont("Utilidades/Fuentes/BebasNeue.otf", 100);
	SDL_Color color; color.r = 200;
	SDL_Surface* textSurface2 = TTF_RenderText_Solid(fuente, a.c_str(), color);
	auto texture = SDL_CreateTextureFromSurface(render::getinstance()->getrender(), textSurface2);
	SDL_FreeSurface(textSurface2);
	return texture;
}
Juego::Juego()
{
	 Divinidad = 20; Pueblo = 20; Ejercito = 20; Dinero = 20;
	 game = true;
	 cambio = false;
	 cambia = 0;
	 RecF = { 0, 0, 1400, 750 }; // Fondo.
	 RecM = { 350, 690, 700, 80 }; // Mensaje.
	 RecG = { 290, 690, 850, 90 }; // Mensaje GameOver.
	 RecL = { 20, -20, 200, 200 }; // Logo
	 RecP = { 600, 85, 180, 60 }; // Texto preguntas.
	 RecC = { 497, 80, 400, 600 }; // Carta.
	 RecRP = { 550, 85, 300, 60 }; // Respuesta pregunta.
	 RecRI = { 540, 90, 80, 60 }; // Respuesta izquierda.
	 RecRD = { 780, 90, 80, 60 }; // Respuesta derecha.
	 RecAD = { 533, 48, 330, 20 }; // valores reino

}


Juego::~Juego()
{

}
void Juego::creartexturas() {
	texturas.push_back(loadImage("Utilidades/Personajes/Dioses/Afrodita.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Dioses/Artemisa.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Dioses/Atenea.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Dioses/Hermes.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Dioses/Poseidon.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Dioses/Zeus.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Abanderado.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Caballero.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Diplomatico.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Espartano.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Faraon.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Granjera.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Granjero.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Guardia.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Justicia.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Muerte.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Novia.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Romano.png"));
	texturas.push_back(loadImage("Utilidades/Personajes/Humanos/Vikingo.png"));
}