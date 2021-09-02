#ifndef CAT_H
#define CAT_H
#include "Objeto.h"

class Cat : public Objeto {
public:
	Cat();
	void Update();
private:
	Vector2f m_pos,m_speed;
};

#endif

