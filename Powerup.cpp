#include "Powerup.h"

Powerup::Powerup() : Objeto ("coffee-pickup.png") , m_pos(270,304){
	m_s.scale(0.5,0.5);
}

void Powerup::Update ( ) {
	m_s.move(m_speed,0);
	
}

Vector2f Powerup::posicion ( ) {
	return m_s.getPosition();
}

