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
#include <SFML/Graphics/Font.hpp>
#include "Powerup.h"
using namespace std;

class Match : public Scene{
public:
	Match();
	void Draw(RenderWindow &window);
	void Update(Game &gamee);
	void ProcessEvent(Event &e){}
	~Match(){stage_music.stop();}
private:
	Music stage_music;
/*	Player shadow = Player("shadow.png");*/
	Player player;
	Texture background_texture;	///textura del Fondo
	Sprite background;
	Texture face_texture;		///textura de la cara del gatito HUD
	Sprite Zeds_face;
	Texture coffee_texture;			///textura de la taza HUD
	//Texture coffee_texture1 y coffee_texture2;
	
	/// en vez de pickup pongo vida1
	//Sprite Pickup;
	Sprite vida1;
	
	Texture shadow_texture;			///textura de la sombra Enemigo
	Sprite Shadow;
	vector <Enemy> enemigos;
	Texture *enemy_texture,*powerup_texture;
	
	//las partes del score
	Font scoreFont;
	Text scorePrint;
	Text scoreText;
//	Sprite coffeeMug;
//	Texture coffeeMugTexture;
	int estamuerto = -1;
	float speed = -5;
	float distan = 1.5; // distancia q haye entre cada obstaculo.
	Clock tiempoenemigos, tiempopowerup;
	int puntaje = 0;
	string scoreToStr;
	
	Powerup m_powerup;
	int cant_enemigos_pasados = 0;
};

#endif

