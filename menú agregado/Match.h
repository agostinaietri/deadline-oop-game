#ifndef MATCH_H
#define MATCH_H
#include "Cat.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"

class Match : public Scene{
public:
	Match();
	void Draw(RenderWindow &window);
	void Update(Game &gamee);
private:
	Cat catt;
	Texture t2;			///textura del Fondo
	Sprite Fondo;
	Texture t3;			///testura de la cara del gatito HUD
	Sprite CaraGato;
	Texture t4;			///textura de la taza HUD
	Sprite Taza;
	Texture t5;			///textura de la sombra Enemigo
	Sprite Sombra;
	/*	Music stage_music;*/ // creo la música
	//	Texture texture;
	//	IntRect rectSourceSprite;
	//	Sprite sprite; acá creo el sprite del personaje
};

#endif

