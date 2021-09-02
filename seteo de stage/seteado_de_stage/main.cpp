#include <SFML/Graphics.hpp>
using namespace sf;

float x = 250;
float y = 0;
float velocityX = 0;
float velocityY = 0;
float accelerationX = 0;
float accelerationY = 0;

float gravity = 2;

void updateMovement() {
	
	if(y < 280)                  // si estás arriba del suelo
		velocityY += gravity;    // añadí gravedad
	else if(y > 280)             // si estás abajo del suelo
		y = 280;                 // eso no se supone que debería pasar, ponelo en su lugar 
	
	velocityX += accelerationX;
	velocityY += accelerationY;
	
	x += velocityX;
	y += velocityY;
}

int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(640,480),"deadline"); // resolución y nombre de ventana
	
	Texture t;
	t.loadFromFile("spritesheet.png"); // cargar spritesheet
	
	Texture t_shadow;
	t_shadow.loadFromFile("shadow.png");
	
	Texture texture_backg;
	texture_backg.loadFromFile("background.png");
	sf::Sprite sprite_backg(texture_backg); // seteo el fondo
	
	Texture texture_floor;
	texture_floor.loadFromFile("floor.png");
	sf::Sprite sprite_floor(texture_floor); // seteo el piso
	sprite_floor.setPosition(0, 425);
	
	Texture texture_life;
	texture_life.loadFromFile("life.png");
	sf::Sprite sprite_life(texture_life); // seteo el hud de vida
	sprite_life.setPosition(200, 10);
	sprite_life.setScale(0.6,0.6);
	
	Texture texture_pickup;
	texture_pickup.loadFromFile("pickup.png");
	sf::Sprite sprite_pickup(texture_pickup); // seteo el hud de pickup
	sprite_pickup.setPosition(400, 10);
	sprite_pickup.setScale(0.6,0.6);
	
	IntRect rectSourceSprite(265,0,265,231);
	Sprite s(t, rectSourceSprite);
	s.setScale(0.6,0.6);
	s.setTexture(t);
	s.setPosition(250, 300); // seteo el personaje
	Clock clock; // agrego un timer
	
	Sprite s_shadow(t_shadow, rectSourceSprite);
	s_shadow.setScale(2,2);
	s_shadow.setTexture(t_shadow);
	s_shadow.setPosition(-250, 10); // seteo el personaje
	
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed) {
				w.close();
			} else if(e.type==Event::KeyPressed && e.key.code==Keyboard::Space){
				velocityY = -10;
			}
		}
		
		if(clock.getElapsedTime().asSeconds() > 1.0f){ // "por cada segundo"
			if(rectSourceSprite.left == 265) { // si es el segundo cuadro
				rectSourceSprite.left = 0; // anda al primero
			} else {
				rectSourceSprite.left += 265; // si no, anda al tercero
			}
			s.setTextureRect(rectSourceSprite);
			clock.restart();
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Left))
		   velocityX = -10;
		else if(Keyboard::isKeyPressed(Keyboard::Left))
			velocityX = 10;
		
		updateMovement();
		s.setPosition(x, y);
		
		w.clear(Color(255,255,255,255));
		w.draw(sprite_backg);
		w.draw(sprite_floor);
		w.draw(sprite_life);
		w.draw(sprite_pickup);
		
		w.draw(s);
		w.draw(s_shadow);
		w.display(); // dibujo y muestro lo creado
	}
	return 0;
}

