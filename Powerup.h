#ifndef POWERUP_H
#define POWERUP_H
#include "Objeto.h"
#include <SFML/System/Vector2.hpp>

class Powerup : public Objeto {
public:
	Powerup();
	void Update();
	Vector2f posicion();
private:
	Vector2f m_pos;
	float m_speed;
};


#endif

