#ifndef OBJETO_H
#define OBJETO_H
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class Objeto {
public:
	Objeto(std::string fname);
	void Draw(RenderWindow &ww);
protected:
	Texture m_t;
	Sprite m_s;
};

#endif

