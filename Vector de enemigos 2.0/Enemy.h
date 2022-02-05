#ifndef ENEMY_H
#define ENEMY_H
#include "ObjetoSinTex.h"
#include "Enemy.h"

class Enemy : public ObjetoSinTex {
private: 
	int posx=0;
	int posy=0;
	float m_speed;
public:
	Enemy(sf::Texture &t,float speed);
	void Update();
	Vector2f posicion();
	void CambiarPosicion (int pos_y,int i);
};

#endif

