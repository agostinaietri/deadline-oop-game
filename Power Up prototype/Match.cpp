#include "Match.h"
#include "Menu.h"
#include "Game.h"
#include <SFML/Audio/Music.hpp>
#include "GameOver.h"
#include <SFML/System/Time.hpp>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics/Text.hpp>
using namespace std;

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
	
	coffeeMugTexture.loadFromFile("coffee-pickup.png");
	coffeeMug.setTexture(coffeeMugTexture);
	
	stage_music.setVolume(10);
	// stage_music.play();
	
	int min_y = 230;
	int max_y = 341;
	
	enemy_texture.loadFromFile("calc.png");
	

	if (!scoreFont.loadFromFile("FreePixel.ttf"))
	{
		// cout << "cannot load file" << endl;
	}
	
	
	///esta parte imprime en la pantalla el mensaje de score
	string scoreToStr = to_string(puntaje);
	
	scoreText.setFont(scoreFont);
	scoreText.setString("score:");
	scoreText.setCharacterSize(40);
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setPosition(200,20);
	scoreText.setColor(sf::Color::Red);
	
	scorePrint.setFont(scoreFont);
	scorePrint.setString(scoreToStr);
	scorePrint.setCharacterSize(40);
	scorePrint.setStyle(sf::Text::Bold);
	scorePrint.setPosition(350,22);
	scorePrint.setColor(sf::Color::Red);
	
}

void Match::Draw (RenderWindow & window) {
	window.clear(Color(125,60,0,100));		///maximo 255
	window.draw(background);
	//window.draw(Zeds_face);
	window.draw(Pickup);
	string scoreToStr = to_string(puntaje);
	scorePrint.setString(scoreToStr);
	window.draw(Shadow);
	player.Draw(window); 
/*	shadow.Draw(window); */
	window.draw(scoreText);
	window.draw(scorePrint);
	
	for(int i = 0; i<enemies.size(); i++) {
		enemies[i].Draw(window);
	}
	
	window.display();
}

//bool Match::estaafuera(Enemy enemigo){
//	if(enemigo.posicion().x==-10){
//		return true;
//	}else{
//		return false;
//	}
//}

void Match::Update ( Game &gamee ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		gamee.SetScene(new Menu());
		stage_music.stop();
	}
	player.Update();
	for(Enemy &e : enemies) {
		e.Update();
	}
	

	
	
	Time time = tiempoenemigos.getElapsedTime();
	float secsPassed  = time.asSeconds();
	
	if(secsPassed >= distan) {
		Enemy aux(enemy_texture,speed);
		
		int result = rand() % 2; 
		if(result == 1){
			aux.CambiarPosicion(341,0);
		}else{
			aux.CambiarPosicion(230,0);
		}
		enemies.push_back(aux);
		speed=speed-0.2;
		int valordistan = rand()%3;
		if(valordistan == 1){
			distan=distan-0.02;
		}else{
			if(valordistan == 2){
				distan=distan+0.10;
			}else{
				distan=distan-0.15;
			}
		}
		tiempoenemigos.restart();
		
	}
	
	///esta parte imprime el valor del puntaje que se modifica
	string scoreToStr = to_string(puntaje);
	scorePrint.setString(scoreToStr);
	
//	auto it = remove_if(enemies.begin(),enemies.end());
//	int cant = enemies.end()-it;
//	enemies.erase(it,enemies.end());
//	
//	puntaje = puntaje + cant*100;
	
	/// valores para probar la modificasion del escore
	puntaje += 1;
	///
	for(int i=0;i<enemies.size();i++){
		auto bb1 = enemies[i].GetBB(); 
		auto bb2 = player.GetBB();
		bb2.left+=40; 
		bb2.width-=50;
		
		if(bb1.intersects(bb2)){
			gamee.SetScene(new GameOver());
			// clock.restart();
		}
	}
	
	
}




Match::~Match ( ) {
	stage_music.stop();
}

