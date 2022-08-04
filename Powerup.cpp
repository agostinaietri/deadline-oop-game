#include "Powerup.h"
#include <SFML/Graphics/Texture.hpp>
Powerup::Powerup(){
	posx = 725;
}
void Powerup::Asignar(sf::Texture *t, float speed)  {
	m_s.scale(0.5,0.5);
	m_speed = speed;
}
void Powerup::Update ( ) {
	m_s.move(m_speed,0);
}
void Powerup::CambiarPosicion (int pos_y, int i) {
	posy = pos_y;
	m_s.setPosition(posx+450*i,posy);
}

Vector2f Powerup::posicion ( ) {
	return m_s.getPosition();
}
