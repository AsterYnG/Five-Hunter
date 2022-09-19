#pragma once
#include "SFMLOrthogonalLayer.hpp"
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Player.h"
using namespace sf;
class Screen
{
private :
	RenderWindow* window;
	Clock time;
public :
	Screen();
	~Screen();
	RenderWindow* getWindowHandle();
	void createWindow(int width, int height);
	void changeView(View &view);
	float getTime();
private:
	
};

