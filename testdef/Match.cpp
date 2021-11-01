#include "Match.h"
#include "Menu.h"
#include "Game.h"
#include <SFML/Audio/Music.hpp>
#include "GameOver.h"
#include <SFML/System/Time.hpp>
#include <sstream>
#include <cstdlib>
using namespace std;

Match::Match() {
	stage_music.openFromFile("stage_music.ogg");
	background_texture.loadFromFile("background.jfif");
	background.setTexture(background_texture);
	background.setPosition(0,-150);
	face_texture.loadFromFile("zeds-face.png");
	Zeds_face.setTexture(face_texture);
	Zeds_face.setPosition(250,20);
	Zeds_face.setScale(0.666,0.666);
	coffee_texture.loadFromFile("coffee-pickup.png");
	Pickup.setTexture(coffee_texture);
	Pickup.setPosition(500,20);
	Pickup.setScale(0.666,0.666);
	shadow_texture.loadFromFile("zeds-shadow.png");
	Shadow.setTexture(shadow_texture);
	Shadow.setPosition(-200,48);
	Shadow.setScale(2.0,2.0);
	
	stage_music.setVolume(10);
	// stage_music.play();
	
	int min_y = 230;
	int max_y = 341;
	
	for(int i = 0; i<2; i++) {
		Enemy e1;
		enemies.push_back(e1);
		int result = rand() % 2;
		if(result == 1) {
			enemies[i].CambiarPosicion(341);
		} else {
			enemies[i].CambiarPosicion(230);
		}
	}

	
	/*score = 1;
	
	stringstream ss;
	ss << score;
	
	score_text.setString( ss.str().c_str() );
	*/
}

void Match::Draw (RenderWindow & window) {
	window.clear(Color(125,60,0,100));		///maximo 255
	window.draw(background);
	window.draw(Zeds_face);
	window.draw(Pickup);
	//window.draw(score_text);
	window.draw(Shadow);
	player.Draw(window); 
	
	for(int i = 0; i<2; i++) {
		enemies[i].Draw(window);
	}
	
	window.display();
}

void Match::Update ( Game &gamee ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		gamee.SetScene(new Menu());
		stage_music.stop();
	}
	player.Update();
	for(Enemy e : enemies) {
		e.Update();
	}
	
	/*
	Time time = clock.getElapsedTime();
	float secsPassed  = time.asSeconds();
	if(secsPassed == 10000) {
		score = score * 5; 
	}
	*/
	
	auto bb1 = enemies[0].GetBB(); 
	auto bb2 = player.GetBB();
	bb2.left+=50; 
	bb2.width-=60;
	if(bb1.intersects(bb2)){
		gamee.SetScene(new GameOver());
		// clock.restart();
	}

}


Match::~Match ( ) {
	stage_music.stop();
}

