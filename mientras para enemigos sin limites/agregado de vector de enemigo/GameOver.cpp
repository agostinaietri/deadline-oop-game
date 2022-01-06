#include "GameOver.h"
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"
#include "Menu.h"


GameOver::GameOver() {
	m_font.loadFromFile("FreePixel.ttf");
	m_tex1.setFont(m_font);
	m_tex2.setFont(m_font);
	
	
	m_tex1.setString("game over!");
	m_tex1.setPosition(180,140);
	m_tex1.setCharacterSize(80);
	
	m_tex2.setString("press Backspace to return to the menu screen");
	m_tex2.setFillColor({150,150,150});
	m_tex2.setPosition(150 ,260);
	m_tex2.setCharacterSize(20);
	
	game_over_music.openFromFile("game_over_music.ogg");
	
	game_over_music.setVolume(10);
	game_over_music.play();
}
void GameOver::Draw (RenderWindow &Window2) {
	Window2.clear({0,0,0});
	Window2.draw(m_tex1);
	Window2.draw(m_tex2);
	Window2.display();
}
void GameOver::Update (Game &gamee ) {
	
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();
	
	m_tex1.setFillColor({r,g,b});
	
	if (Keyboard::isKeyPressed(Keyboard::Key::BackSpace)){
		gamee.SetScene(new Menu());
		game_over_music.stop();
	}
	
}
