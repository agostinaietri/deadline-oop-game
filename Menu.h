#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Scene.h"
#include <SFML/Audio/Music.hpp>

using namespace sf;

class Menu : public Scene {
public:
	Menu();
	void Update(Game &gamee);
	void Draw(RenderWindow &Window2);
private:
	Music menu_music;
	Font m_font;
	Text m_tex1, m_tex2;
};

#endif

