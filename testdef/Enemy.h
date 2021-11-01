#ifndef ENEMY_H
#define ENEMY_H
#include "Objeto.h"
#include "Enemy.h"

class Enemy : public Objeto {
private: 
	int posx=0;
	int posy=0;
	int m_speed=-5;
public:
	Enemy();
	void Update();
	Vector2f SIZE();
	void CambiarPosicion(int pos_y);
};

#endif
