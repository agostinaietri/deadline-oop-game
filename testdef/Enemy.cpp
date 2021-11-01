#include "Enemy.h"

Enemy::Enemy() : Objeto("calc.png") {
	posx=725;
	m_s.scale(0.6,0.6);
}

void Enemy::Update ( ) {
	m_s.move(m_speed,0);
	
}


void Enemy::CambiarPosicion (int pos_y) {
	posy = pos_y;
	m_s.setPosition(posx,posy);
}

Vector2f Enemy::SIZE ( ) {
	m_s.getPosition();
}
