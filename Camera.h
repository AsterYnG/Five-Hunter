#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <tmxlite/Object.hpp>
using namespace sf;
class Camera
{
private:
	View view; // View object:)
	bool notMoving;
	int dir;
	int cameraPreSet;
	bool fullscreen;
	int width, height;
	
public:
	Camera();
	void updateView(RenderWindow* window);
	void renderView(sf::Vector2f coords, int dir);
	void setCollisionFlag(bool flag);
	void init(tmx::Object player_coords );
	void changeSize(int width , int height);
	void setCameraPreSet(int i);
private:
	void moveRender(int dir);
	bool borderRender(sf::Vector2f coords);
	void checkFullscreen();
};

