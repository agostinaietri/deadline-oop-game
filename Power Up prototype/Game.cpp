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
	

/*Cuando se ingrese el nickname del Playerpara guardar su Puntaje, la clase game se la tiene que pasar a gameover para que esta 
	almacene el nombre junto con el puntaje que recibió de la clase Match.
		Preguntar como enlazar est co GameOver. Esta duda duda esta en la linea 55.*/
		if(e.type == Event::TextEntered){
			if (e.text.unicode < 128 && e.text.unicode != 13){
				std::string new_name;
				new_name.push_back(static_cast<char>(e.text.unicode));
			}
			if (e.text.unicode == 13){
				pasar_a_gameover(new_name);
			}
		}

	}
}

void Game::SetScene (Scene * next_scene) {
	m_next_scene = next_scene;
}

