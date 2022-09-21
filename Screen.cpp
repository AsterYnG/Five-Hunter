#include "Screen.h"



Screen::Screen()
{
	window = new RenderWindow;
	currentFrame = 0;
	animationSpeed = 10;

}

Screen::~Screen()
{
	delete window;
}

RenderWindow* Screen::getWindowHandle()
{
	return this->window;
	
}



void Screen::createWindow(int width, int height)
{
	window->create(VideoMode(width, height), " Debug.chlen");

}

void Screen::changeView(View& view)
{
	if (Keyboard::isKeyPressed(Keyboard::P))
	{
		view.zoom(1.0001);
	}
	if (Keyboard::isKeyPressed(Keyboard::I))
	{
		view.zoom(0.998991);
	}
	if (Keyboard::isKeyPressed(Keyboard::H))
	{
		view.setSize(200, 150);
	}
	window->setView(view);
}

float Screen::getTime()
{
	return time.restart().asSeconds();
}

void Screen::setFrame(float time)
{
	if (currentFrame > 6) currentFrame -= 6;
	currentFrame += time * animationSpeed;
}

int Screen::getFrame()
{
	return int(currentFrame);
}

