#include "Screen.h"



Screen::Screen()
{
	window = new RenderWindow;
	currentFrame = 0;
	animationSpeed = 10;
	timePerFrame = 0;
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
	window->create(VideoMode(width, height),   " Debug.chlen" );

}



void Screen::updateTime()
{
	timePerFrame = time.restart().asSeconds();
}

float Screen::getTime()
{
	return timePerFrame;
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

