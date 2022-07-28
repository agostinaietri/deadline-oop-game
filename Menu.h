#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Scene.h"
#include <SFML/Audio/Music.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

class Menu : public Scene {
public:
	Menu();
	void Update(Game &gamee);
	void Draw(RenderWindow &Window2);
	void ProcessEvent(Event &e){}
	void LoadText();
	void LoadSelect_Bar();
private:
	Music menu_music;
	Font m_font;
	Text m_tex_name, m_tex2, m_text_options;
	Clock m_clock;
	RectangleShape Selection_Bar;
	int Selection_Bar_Pos = 1;
};

#endif

