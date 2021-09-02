#include "Match.h"
#include "Menu.h"
#include "Game.h"
#include <SFML/Audio/Music.hpp>

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
	stage_music.play();
	
}

void Match::Draw (RenderWindow & window) {
	window.clear(Color(125,60,0,100));		///maximo 255
	window.draw(background);
	window.draw(Zeds_face);
	window.draw(Pickup);
	window.draw(Shadow);
	player.Draw(window); 
	enemy.Draw(window);
	window.display();
}

void Match::Update ( Game &gamee ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		gamee.SetScene(new Menu());
		stage_music.stop();
	}
	player.Update();
	enemy.Update();
}



