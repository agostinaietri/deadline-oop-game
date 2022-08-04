#include "Enemy.h"
Enemy::Enemy(sf::Texture *t, float speed) : ObjetoSinTex(t) {
	m_s.scale(0.6,0.6);
	posx = 725;
	m_speed = speed;
}

void Enemy::CambiarPosicion (int pos_y, int i) {
	posy = pos_y;
	m_s.setPosition(posx+450*i,posy);
}
void Enemy::Update ( ) {
	m_s.move(m_speed,0);
}
void Enemy::bajarVelocidad(float nro){ // nro = 0.05.
	m_speed += nro;
}
Vector2f Enemy::posicion ( ) {
	return m_s.getPosition();
}

