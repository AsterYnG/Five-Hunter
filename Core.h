#pragma once
#include "SFMLOrthogonalLayer.hpp"
#include "Screen.h"
#include "GJK.h"
#include "Camera.h"
#include "Interface.h"
class Core
{
private:
	void draw(); // draw objects
	void logic();
	void moveEvent(); // Movement logic
	void collission();
	void fullscreenMode(sf::Event &event);
	void resize(sf::Event& event);
	void start(sf::Event& event);
	int menuEvent(sf::Event& event);
	void updateInterface(View& view);
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
	Camera view;// вид
	RenderWindow* windowHandle; // дескриптор окна типа
	Interface gameIn; // Interface
	bool menu; // menu flag ( 0 if not in menu , 1 other case)
	
};

