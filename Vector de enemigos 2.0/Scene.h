#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"


using namespace sf;
class Game;
class Scene {
public:
	Scene();
	virtual void Draw(RenderWindow &Window) = 0;
	virtual void Update(Game &gamee) = 0;
	virtual ~Scene () {};
private:
};

#endif

