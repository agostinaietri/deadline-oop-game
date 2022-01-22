#include "Objeto.h"

Objeto::Objeto(std::string fname) {
	m_t.loadFromFile(fname);
	m_s.setTexture(m_t);
}


void Objeto::Draw (RenderWindow &ww) {
	ww.draw(m_s);
}

FloatRect Objeto::GetBB ( ) const {
	return m_s.getGlobalBounds();
}

