#pragma once
#include "SFMLOrthogonalLayer.hpp"
#include "Screen.h"
class Core
{
private:
	void draw(); // draw objects
	void logic();
	void moveEvent(); // Movement logic
	void viewRender(float x  , float y); // set camera position etc.
public:
	void Render(); // With loop in core
	Core();
private :
	Screen screen; // ������ ������
	Player player; // ������ ������
	TileMap map; // ������ �����
	sf::View view; // ���
	RenderWindow* windowHandle; // ���������� ���� ����
	
};

