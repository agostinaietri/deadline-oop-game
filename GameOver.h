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
	GameOver(int puntaje_g);
	void Update(Game &gamee);
	void Draw(RenderWindow &Window2);
private:
	Font m_font;
	Text m_tex1, m_tex2;
	Music game_over_music;
	
	// para score
	Text m_tex_datosjugador, m_tex_nomjugador; //el 1ro es el texto que le indica que ingrese su nombre, el 2do es para armar el txt de cada jugador
	vector<Puntaje>ranking_p;
	int m_new_score; // se le asigna el valor del puntaje que ingrea en el ctor.
	void Archivo();
	void SetearPuntajes();
	void Ingresar(string new_name);
	void Actualizar();
};

#endif
