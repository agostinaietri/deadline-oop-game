#ifndef ENEMY_H
#define ENEMY_H
#include "ObjetoSinTex.h"
#include "Enemy.h"

class Enemy : public ObjetoSinTex {
private: 
	int posx=0;
	int posy=0;
	int m_speed=-5;
public:
	Enemy(sf::Texture &t);
	void Update();
	Vector2f SIZE();
	void CambiarPosicion (int pos_y,int i);
};

#endif

