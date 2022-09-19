#pragma once
#include "SFMLOrthogonalLayer.hpp"
#include "Screen.h"
class Core
{
private:
	void draw(); // draw objects
	void logic();
	void moveEvent();
	void viewRender(float x  , float y);
public:
	void Render(); // With loop in core
	Core();
private :
	Screen screen; // Объект экрана
	Player player; // объект игрока
	TileMap map; // объект карты
	sf::View view; // вид
	RenderWindow* windowHandle; // дескриптор окна типа
	
};

