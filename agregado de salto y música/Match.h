#ifndef MATCH_H
#define MATCH_H
#include "Player.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
#include <SFML/Audio/Music.hpp>
#include "Enemy.h"

class Match : public Scene{
public:
	Match();
	void Draw(RenderWindow &window);
	void Update(Game &gamee);
private:
	Music stage_music;
	Player player;
	Texture background_texture;	///textura del Fondo
	Sprite background;
	Texture face_texture;		///textura de la cara del gatito HUD
	Sprite Zeds_face;
	Texture coffee_texture;			///textura de la taza HUD
	Sprite Pickup;
	Texture shadow_texture;			///textura de la sombra Enemigo
	Sprite Shadow;
	Enemy enemy;
};

#endif

