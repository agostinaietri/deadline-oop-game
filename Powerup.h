#ifndef POWERUP_H
#define POWERUP_H
#include <SFML/System/Vector2.hpp>
#include "ObjetoSinTex.h"

class Powerup : public ObjetoSinTex {
public:
	Powerup();
	void Asignar(sf::Texture *t, float speed);
	float Velocidad(){return m_speed;}
	Vector2f posicion();
	void Update();
	void CambiarPosicion (int pos_y, int i);
	~Powerup(){}
private:
	Vector2f m_pos;
	float m_speed;
	int posx;
	int posy;
};


#endif

