#ifndef OBJETO_SIN_TEX_H
#define OBJETO_SIN_TEX_H
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class ObjetoSinTex {
public:
	ObjetoSinTex(sf::Texture &t);
	void Draw(RenderWindow &ww);
	FloatRect GetBB()const;
protected:
	Sprite m_s;
};

#endif
