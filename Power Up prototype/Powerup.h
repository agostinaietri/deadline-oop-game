#ifndef POWERUP_H
#define POWERUP_H
#include "Objeto.h"
#include <SFML/System/Vector2.hpp>

class Powerup : public Objeto {
public:
	Powerup(float speed , int aux);
	void Update();
	Vector2f posicion();
	void CambiarPosicion(int posy,int i);
	int QuePowerUpEs();
private:
	int posx=0;
	int posy=0;
	Vector2f m_pos;
	float m_speed;
	int diferentePowerup;
};


#endif

