#include "Enemy.h"

Enemy::Enemy(sf::Texture &t,float speed) : ObjetoSinTex(t) {
	posx=725;
	m_s.scale(0.6,0.6);
	m_speed=speed;
}

void Enemy::Update ( ) {
	m_s.move(m_speed,0);
	
}


void Enemy::CambiarPosicion (int pos_y, int i) {
	posy = pos_y;
	m_s.setPosition(posx+450*i,posy);
}

Vector2f Enemy::posicion ( ) {
	return m_s.getPosition();
}

