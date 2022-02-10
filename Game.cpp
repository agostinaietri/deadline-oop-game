#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Scene.h"

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
		if(m_next_scene){
			delete m_scene;
			m_scene = m_next_scene;	///eliminando la escena acá te evitas problemas de que reviente el juego
			m_next_scene = nullptr;
		}
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
}

void Game::SetScene (Scene * next_scene) {
	m_next_scene = next_scene;
}

