#ifndef MATCH_H
#define MATCH_H
#include "Player.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
#include <SFML/Audio/Music.hpp>
#include "Enemy.h"
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>
using namespace std;

class Match : public Scene{
public:
	Match();
	void Draw(RenderWindow &window);
	void Update(Game &gamee);
	~Match();
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
	vector <Enemy> enemies;
	Texture enemy_texture;
	int estamuerto = -1;
	float speed=-5;
	float distan=1.5;
	Clock tiempoenemigos;
	int puntaje=0;
	
};

#endif

