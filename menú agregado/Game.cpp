#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Scene.h"

#include <iostream>
using namespace std;
using namespace sf;

Game::Game() : m_w(VideoMode(720,480),"deadline"){
	m_w.setFramerateLimit(60);
	m_scene = new Menu();
	
}


void Game::Run ( ) {
	while(m_w.isOpen()) {
		ProcesadoJuego();
		Update();
		Draw();
//		stage_music.openFromFile("stage_music.ogg");
//		stage_music.setLoop(true);
//		stage_music.setVolume(50.0);
//		stage_music.play(); //le doy play a la música, pero en qué loop iría?
		if(m_next_scene){
			delete m_scene;
			m_scene = m_next_scene;	//poniendo aca la eliminación de la escena te evitas problemas de que reviente el juego
			m_next_scene = nullptr;
		}
//		if(clock.getElapsedTime().asSeconds() > 0.15f) { // esto me controla los frames del sprite
//			if(rectSourceSprite.left == 530) {
//				rectSourceSprite.left = 0;
//			} else {
//				rectSourceSprite.left += 265;
//			}
//			
//			sprite.setTextureRect(rectSourceSprite);
//			clock.restart();
//		}
	}
}



void Game::Draw ( ) {
	m_scene->Draw(m_w);
}

void Game::Update () {
	m_scene->Update(*this);
}

void Game::ProcesadoJuego ( ) {
	Event e;
	while(m_w.pollEvent(e)){ {
		if(e.type == Event::Closed)
			m_w.close();	
		}
	}
//	while(!stage_music.openFromFile("stage_music.ogg")) {
//		cout << "ERROR" << endl;
//	} // si no lo encuentra, tira error 
}

void Game::SetScene (Scene * next_scene) {
	m_next_scene = next_scene;
}

