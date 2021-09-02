#include "Enemy.h"

Enemy::Enemy() : Objeto("calc.png") {
	m_s.setPosition(725,341);
	m_s.scale(0.6,0.6);
}


void Enemy::Update ( ) {
	m_s.move(-5,0);
	
}

