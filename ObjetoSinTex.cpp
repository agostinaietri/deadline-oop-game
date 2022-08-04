#include "ObjetoSinTex.h"

ObjetoSinTex::ObjetoSinTex(sf::Texture *t) {
	m_s.setTexture(*t);
}
void ObjetoSinTex::Draw (RenderWindow &ww) {
	ww.draw(m_s);
}

FloatRect ObjetoSinTex::GetBB ( ) const {
	return m_s.getGlobalBounds();
}
