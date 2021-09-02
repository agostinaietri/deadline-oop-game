#include "Menu.h"
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"


Menu::Menu() {
	m_font.loadFromFile("FreePixel.ttf");
	m_tex1.setFont(m_font);
	m_tex2.setFont(m_font);
	
	
	m_tex1.setString("deadline.");
	m_tex1.setPosition(200,140);
	m_tex1.setCharacterSize(80);
	
	m_tex2.setString("<press Space to start>");
	m_tex2.setFillColor({150,150,150});
	m_tex2.setPosition(250,280);
	m_tex2.setCharacterSize(20);
}



void Menu::Draw (RenderWindow &Window2) {
	Window2.clear({0,0,0});
	Window2.draw(m_tex1);
	Window2.draw(m_tex2);
	Window2.display();
}

void Menu::Update (Game &gamee ) {
	
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();
	
	m_tex1.setFillColor({r,g,b});
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)){
		gamee.SetScene(new Match());
	}
	
}

