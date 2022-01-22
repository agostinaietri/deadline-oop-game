#ifndef PLAYER_H
#define PLAYER_H
#include "Objeto.h"



class Player : public Objeto {
public:
	Player();
	void Update();
private:
	Vector2f m_pos,m_speed;
	int m_num_frame = 0;
};

#endif

