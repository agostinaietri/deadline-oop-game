#include "GameOver.h"
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"
#include "Menu.h"
#include <iostream>
#include <SFML/Window/Event.hpp>
#include "Puntajes.h"
	
GameOver::GameOver(int new_score) : text_entrada(m_font,30,sf::Color::White) { 
	
	// aca tengo que llamar a la clase inputbox.
	text_entrada.setPosition(170,225);
	text_entrada.setMaxChars(10); // no mas de 10 caracteres
	text_entrada.setSingleWord(true); // no permitir ingresar espacios, para que sea solo una 
	
	m_new_score = new_score;
	
	m_font.loadFromFile("FreePixel.ttf");
	m_tex1.setFont(m_font);
	m_tex2.setFont(m_font);
	m_tex_pidenom.setFont(m_font);
	
	m_tex1.setString("game over!");
	m_tex1.setPosition(180,70); 
	m_tex1.setCharacterSize(80);
	
	m_tex2.setString("press Escape to return to the menu screen");
	m_tex2.setFillColor({150,150,150});
	m_tex2.setPosition(150 ,280);
	m_tex2.setCharacterSize(20);
	
	game_over_music.openFromFile("game_over_music.ogg");
	game_over_music.setVolume(10);
	game_over_music.play();
	
	/// Seteo texto para pedir el nombre del player que terminó de jugar.
	m_tex_pidenom.setString("write your name: ");
	m_tex_pidenom.setFillColor({150,150,150});
	m_tex_pidenom.setPosition(180,180);
	m_tex_pidenom.setCharacterSize(20);
	
}
//

void GameOver::Update(Game &gamee) {
	
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();
	
	m_tex1.setFillColor({r,g,b});
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){ // Esc para volver a Menu
		gamee.SetScene(new Menu());
		game_over_music.stop();
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::Return)){ // Enter para pasar a la escena de Puntajes.
		m_new_name = text_entrada.getValue();
		gamee.SetScene(new Puntajes(m_new_name,m_new_score));
		game_over_music.stop();
	}
}
//

void GameOver::Draw (RenderWindow &Window2) {
	Window2.clear({0,0,0});
	Window2.draw(m_tex1);
	Window2.draw(m_tex2);
	Window2.draw(m_tex_pidenom); //el txt "ingrese su nombre"
	
	text_entrada.update();// para que el texto se dibuje correctamente
	Window2.draw(text_entrada); // el q se ingresa x teclado
	
	Window2.display();
}

void GameOver:: ProcessEvent(Event &e){ // acá necesita el nombre ingresado
	text_entrada.processEvent(e); // para que el texto tome las teclas que pulsamos
}
