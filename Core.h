#pragma once
#include "SFMLOrthogonalLayer.hpp"
#include "Screen.h"
#include "GJK.h"
class Core
{
private:
	void draw(); // draw objects
	void logic();
	void moveEvent(); // Movement logic
	void collission();
	
	void viewRender(float x  , float y); // set camera position etc.

	std::vector<vec2> getVerticesObj(Object& o);
	std::vector<vec2> getVerticesPl(sf::Sprite& p);
public:
	void Render(); // With loop in core
	Core();
	~Core();
private :
	Screen screen; // Объект экрана
	Player player; // объект игрока
	TileMap map; // объект карты
	sf::View view; // вид
	RenderWindow* windowHandle; // дескриптор окна типа
	
};

