#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Window.hpp> 
#include <SFML/Graphics/Font.hpp>	
#include <SFML/Graphics/Text.hpp>
#include "Scene.h"
#include <SFML/Audio/Music.hpp>
#include "InputBox.h"

using namespace std;

class GameOver : public Scene {
public:
	GameOver(int new_score);
	void Update(Game &gamee);
	void Draw(RenderWindow &Window2);
	void ProcessEvent(Event &e);
private:
	Font m_font;
	Text m_tex1, m_tex2;
	Music game_over_music;
	
	// para score
	Text m_tex_pidenom;
	vector<Text>textos_players;
	InputText text_entrada;
	int m_new_score;
	string m_new_name;
};

#endif
