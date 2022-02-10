#include "Powerup.h"

Powerup::Powerup(float speed,int aux) : Objeto ("coffee-pickup.png"){
	m_s.scale(0.5,0.5);
	posx=725;
	m_speed = speed;
	diferentePowerup = aux;
}

void Powerup::Update ( ) {
	m_s.move(m_speed,0);
}

Vector2f Powerup::posicion ( ) {
	return m_s.getPosition();
}


void Powerup::CambiarPosicion (int pos_y,int i) {
	posy = pos_y;
	m_s.setPosition(posx+450*i,posy);
}

int Powerup::QuePowerUpEs ( ) {
	return diferentePowerup;
}

