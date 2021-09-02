#include "Match.h"
#include "Menu.h"
#include "Game.h"

Match::Match() {
	t2.loadFromFile("fondo.jfif");
	Fondo.setTexture(t2);
	Fondo.setPosition(0,-150);
	t3.loadFromFile("cara gato.png");
	CaraGato.setTexture(t3);
	CaraGato.setPosition(250,20);
	CaraGato.setScale(0.666,0.666);
	t4.loadFromFile("taza cafe.png");
	Taza.setTexture(t4);
	Taza.setPosition(500,20);
	Taza.setScale(0.666,0.666);
	t5.loadFromFile("sombrita 2.png");
	Sombra.setTexture(t5);
	Sombra.setPosition(-200,48);
	Sombra.setScale(2.0,2.0);
	//	rectSourceSprite(0, 0, 265, 231);
	//	sprite(texture, rectSourceSprite);
	//	sprite.setPosition(175, 130); // creo el sprite del personaje
}

void Match::Draw (RenderWindow & window) {
	window.clear(Color(125,60,0,100));		///maximo 255
	window.draw(Fondo);
	window.draw(CaraGato);
	window.draw(Taza);
	window.draw(Sombra);
	catt.Draw(window); 
	/*window.draw(sprite);*/
	window.display();
}

void Match::Update ( Game &gamee ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		gamee.SetScene(new Menu());
	}
	catt.Update();
}



