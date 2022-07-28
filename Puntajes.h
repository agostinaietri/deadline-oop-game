#ifndef PUNTAJES_H
#define PUNTAJES_H
#include "Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include <SFML/Graphics/Font.hpp>
#include "ManejoArchivo.h"
using namespace std;

class Puntajes : public Scene {
public:
	Puntajes(string new_name,int new_score);
	Puntajes();
	void Draw (RenderWindow & Window);
	void Update (Game & gamee);
	void SetearPuntajes();
	void ProcessEvent (Event & e){}
private:
	Font m_font;
	vector<Text>textos_players;
	ManejoArchivo m_archivo;
};

#endif

