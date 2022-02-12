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
	GameOver(int new_score);
	void Update(Game &gamee);
	void Draw(RenderWindow &Window2);
private:
	Font m_font;
	Text m_tex1, m_tex2;
	Music game_over_music;

	// para score
	Text m_tex_pidedatos; // el texto q dice "enter your name" y el otro es del nombre q se va a ingresar por teclado.
	vector<Text>textos_players ;
	vector<Puntaje>ranking_p;
	
	/// Métodos para manejo de Archivo.
	void Archivo();
	void SetearPuntajes();
	void Ingresar(string new_name,int new_score);
	void Actualizar();
};

#endif
