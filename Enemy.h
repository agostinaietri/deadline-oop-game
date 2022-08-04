#ifndef ENEMY_H
#define ENEMY_H
#include "Enemy.h"
#include "ObjetoSinTex.h"

class Enemy : public ObjetoSinTex {
private: 
	int posx=0;
	int posy=0;
	float m_speed;
public:
	Enemy(sf::Texture *t, float speed);
	void Update();
	void bajarVelocidad(float nro);
	Vector2f posicion();
	void CambiarPosicion (int pos_y,int i);
};

#endif
