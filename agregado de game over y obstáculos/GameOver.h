#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Scene.h"
#include <SFML/Audio/Music.hpp>

using namespace sf;

class GameOver : public Scene {
public:
	GameOver();
	void Update(Game &gamee);
	void Draw(RenderWindow &Window2);
private:
	Font m_font;
	Text m_tex1, m_tex2;
	Music game_over_music;
};

#endif
