#include "Menu.h"
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"
#include "Puntajes.h"
#include "Sobre.h"


Menu::Menu() {
	this->LoadText();
	this->LoadSelect_Bar();
	
	menu_music.openFromFile("menu_music.ogg");
	
	menu_music.setVolume(10);
	menu_music.play();
}
//

void Menu::Draw (RenderWindow &Window2) {
	Window2.clear({0,0,0});
	Window2.draw(m_tex_name);
	Window2.draw(m_tex2);
	Window2.draw(m_text_options);
	Window2.draw(Selection_Bar);
	Window2.display();
}
//

void Menu::Update (Game &gamee ) {
	
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();
	
	m_tex_name.setFillColor({r,g,b});
	
	/// agregado con mas opciones para el menu.
	if(m_clock.getElapsedTime().asSeconds()>0.3){
		if(Keyboard::isKeyPressed(Keyboard::S)){ // para ir hacia abajo
			++Selection_Bar_Pos;
			m_clock.restart();
		}
		if(Keyboard::isKeyPressed(Keyboard::W)){ // para ir hacia arriba
			--Selection_Bar_Pos;
			m_clock.restart();
		}
	}
	if(Selection_Bar_Pos<1){ // para que la barra de seleccion se mantenga dentro de las 3 opciones
		Selection_Bar_Pos = 3;
	}
	if(Selection_Bar_Pos > 3){
		Selection_Bar_Pos = 1;
	}
	
	if(Selection_Bar_Pos==1){
		Selection_Bar.setPosition(260,230);
		Selection_Bar.setSize(Vector2f(90,10));	
	}
	if(Selection_Bar_Pos==2){
		Selection_Bar.setPosition(260,250);
		Selection_Bar.setSize(Vector2f(120,10));	
	}
	if(Selection_Bar_Pos==3){
		Selection_Bar.setPosition(260,270);
		Selection_Bar.setSize(Vector2f(140,10));	
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)){ // space cuando selecciona una opcion del menu.
		if(Selection_Bar_Pos==1){
			gamee.SetScene(new Match());
			menu_music.stop();
		}
		if(Selection_Bar_Pos==2){
			gamee.SetScene(new Puntajes(" ",0));
			menu_music.stop();
		}
		if(Selection_Bar_Pos==3){
			gamee.SetScene(new Sobre());
			menu_music.stop();
		}
	}
}
void Menu::LoadText ( ) {
	m_font.loadFromFile("FreePixel.ttf");
	m_tex_name.setFont(m_font);
	m_tex2.setFont(m_font);
	m_text_options.setFont(m_font);
	
	m_tex_name.setString("deadline");
	m_tex_name.setPosition(220,100);
	m_tex_name.setCharacterSize(80);
	
	m_tex2.setString("press Space to select an option");
	m_tex2.setFillColor({150,150,150});
	m_tex2.setPosition(240,320);
	m_tex2.setCharacterSize(20);
	
	m_text_options.setPosition(260,210);
	m_text_options.setCharacterSize(20);
	m_text_options.setString("New Match\nBest Scores\nAbout the game");
	
}
void Menu::LoadSelect_Bar ( ) {
	Selection_Bar.setPosition(260,250);
	Selection_Bar.setSize(Vector2f(10,0.2));
}

