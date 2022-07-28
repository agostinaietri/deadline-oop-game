#include "Sobre.h"
#include "Menu.h"

Sobre::Sobre() {
	this->LoadText();
}
void Sobre::Update (Game &gamee) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){ // Esc para volver a Menu
		gamee.SetScene(new Menu());
	}	
}

void Sobre::Draw (RenderWindow &Window2) {
	Window2.clear(Color(0,0,0));
	Window2.draw(m_text);
	Window2.display();
}

void Sobre::LoadText ( ) {
	m_font.loadFromFile("FreePixel.ttf");
	
	m_text.setFont(m_font);
	m_text.setPosition(150,150);
	m_text.setCharacterSize(20);
	m_text.setString("Videojuego creado en grupo\n para el Proyecto Final de \nProgramación Orientada a Objetos 2022\n\n\n\nInspirado en el Dinochrome,\nun juego de GoogleChrome que se puede\njugar cuando perdés la conexión a internet.");
	m_text.setFillColor(Color(20,230,20));
	
	m_tex2.setString("press Escape to return to the menu screen");
	m_tex2.setFillColor({150,150,150});
	m_tex2.setPosition(150 ,280);
	m_tex2.setCharacterSize(20);
}


