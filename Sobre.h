#ifndef SOBRE_H
#define SOBRE_H
#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

using namespace sf;

class Sobre : public Scene{
public:
	Sobre();
	void Update(Game &gamee);
	void Draw(RenderWindow &Window2);
	void LoadText();
	void ProcessEvent(Event &e){}
private:
	Music menu_music;
	Font m_font;
	Text m_text, m_tex2;
};

#endif
