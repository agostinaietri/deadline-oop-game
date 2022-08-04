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
#include "Powerup.h"
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
	
//	coffee_texture.loadFromFile("coffee-pickup.png");
	///en vez d pickup pongo vida1
//	Pickup.setTexture(coffee_texture);
//	vida1.setTexture(coffee_texture);
//	Pickup.setPosition(500,20);
//	vida1.setPosition(500,20);
//	Pickup.setScale(0.666,0.666);
//	vida1.setScale(0.666,0.666);
	
	shadow_texture.loadFromFile("zeds-shadow.png");
	Shadow.setTexture(shadow_texture);
	Shadow.setPosition(-200,48);
	Shadow.setScale(2.0,2.0);
	
//	coffeeMugTexture.loadFromFile("coffee-pickup.png");
//	coffeeMug.setTexture(coffeeMugTexture);
	
	stage_music.setVolume(10);
	// stage_music.play();
	
	int min_y = 230;
	int max_y = 341;
		
	scoreFont.loadFromFile("FreePixel.ttf");
	scoreText.setFont(scoreFont);
	scoreText.setString("score: ");
	scoreText.setCharacterSize(40);
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setPosition(150,8.7);
	scoreText.setColor(sf::Color::Red);
	
	scoreToStr = to_string(puntaje);
	scorePrint.setFont(scoreFont);
	scorePrint.setString(scoreToStr);
	scorePrint.setCharacterSize(40);
	scorePrint.setStyle(sf::Text::Bold);
	scorePrint.setPosition(300,8.7);
	scorePrint.setColor(sf::Color::Red);
}

void Match::Draw (RenderWindow & window) {
	window.clear(Color(125,60,0,100));		///maximo 255
	window.draw(background);
	//window.draw(Zeds_face);
	
	///en vez d pickup pongo vida1
	//window.draw(Pickup);
//	window.draw(vida1);
	
	window.draw(Shadow);
	player.Draw(window); 
/*	shadow.Draw(window); */
	
	m_powerup.Draw(window);
	
	scorePrint.setString(scoreToStr);
	window.draw(scoreText);
	window.draw(scorePrint);
	
	for(int i = 0; i<enemigos.size(); i++) {
		enemigos[i].Draw(window);
	}
	
	window.display();
}

bool estaafuera(Enemy &enemigo){
	return enemigo.posicion().x==-10;
}
string elegirText(){
	string elegida;
	int opcion = rand()% 3 + 1;
	switch (opcion){
	case 1:
		elegida = "calc.png";
		break;
	case 2:
		elegida = "calendar.png";
		break;
	case 3:
		elegida = "folder.png";
		break;		
	};
	return elegida;
}
void asignarPos(Enemy &e){
	
	int result = rand() % 2;  // varia la posicion donde se generan enemies
	if(result == 1){
		e.CambiarPosicion(341,0);
	}else{
		e.CambiarPosicion(230,0);
	}
}
void asignarPos(Powerup &p_up){		
	int result2 = rand() % 2;  // determina la pos
	if(result2 == 1){
		p_up.CambiarPosicion(300,0);
	}else{
		p_up.CambiarPosicion(260,0);
	}
}
void Match::Update ( Game &gamee ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){ // para volver a Menu
		gamee.SetScene(new Menu());
		stage_music.stop();
	}
	
	// updates
	player.Update();
	m_powerup.Update();
	for(Enemy &e : enemigos) {
		e.Update();
		if( player.colisionaCon(e) ){ // colision player-obstaculos
			gamee.SetScene(new GameOver(puntaje));
		}else{
			cant_enemigos_pasados += 1;
		}
	}
	
	/// POWERUP
	if( player.colisionaCon(m_powerup) ){
		
		int contador = 5;
		while( contador!=0 ){ // la velocidad se hace mas lenta por cinco segundos
			
			for(int i=0;i<enemigos.size();i++){ // colisión player-enemigo
				enemigos[i].bajarVelocidad(0.5);
			}
			contador--;
		}
		cant_enemigos_pasados = 0;
	}
	
	if( m_powerup.posicion().x==-10 ){ // si esta afuera de la pantalla (no lo agarró)..
		// borrarlo de la pantalla
		m_powerup.CambiarPosicion(725,0);// que vuelva a estar quieto en la parte de atras dea
		cant_enemigos_pasados = 0;
		
	}
	
	/// generación de objetos en movimiento
	Time time_enemigos = tiempoenemigos.getElapsedTime(); // de clock  a time
	float secsPassed  = time_enemigos.asSeconds();
	
	if(secsPassed >= distan) { // condicional para q los objetos se generen a cierta distancia
		
		if( cant_enemigos_pasados==10 ){//y si ademas ya esquivó 10 obstaculos..
			powerup_texture = new sf::Texture;// genera powerup
			powerup_texture->loadFromFile("clip.png");
			asignarPos(m_powerup);
			m_powerup.Asignar(powerup_texture,speed);
			
		}else { //en caso q player no esquivó 10 obstaculos, siguen apareciendo
			
			string file_elegido = elegirText(); // para variar la textura de enemigo
			enemy_texture = new sf::Texture;
			enemy_texture->loadFromFile(file_elegido);
			Enemy aux_e(enemy_texture,speed);
			
			asignarPos(aux_e);
			enemigos.push_back(aux_e);
		}
		
		speed = speed-0.2; // la velocidad aumenta gradualmente.
		
		int valordistan = rand()%3;
		if(valordistan == 1){ 
			distan=distan-0.02; // se genera mas cerca
		} else {
			if(valordistan == 2){
				distan = distan + 0.10; // se genera mas lejos
			} else {
				distan = distan-0.15; // se genera mucho mas cerca
			}
		}
		tiempoenemigos.restart();
	}
	
	auto it = remove_if(enemigos.begin(),enemigos.end(),estaafuera); //si ya no figuran dentro d la pantalla, se borran del vector.
	int cant = enemigos.end() - it;
	enemigos.erase(it,enemigos.end());
	
	puntaje += 1; // se actualiza el puntaje
	scoreToStr = to_string(puntaje);	

}
