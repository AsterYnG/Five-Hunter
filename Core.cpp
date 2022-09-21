#include "Core.h"

void Core::Render()
{
	
	Event event;
	while (windowHandle->isOpen())
	{
		while (windowHandle->pollEvent(event))
		{
			if (event.type == Event::Closed) windowHandle->close();
		}
		
		logic();
		screen.changeView(view);
		windowHandle->clear();
		draw();
		windowHandle->display();
	}
}

Core::Core()
{
	screen.createWindow(800, 600);
	windowHandle = screen.getWindowHandle();
	player.playerSprite.setPosition(map.player_coords[0].getPosition().x, map.player_coords[0].getPosition().y);
	view.setCenter(player.getPlayerCoords());
	
	
}

void Core::draw()
{
	for (auto el : map.getLayers())
	{
		windowHandle->draw(*el);

	}
	windowHandle->draw(player.playerSprite);
	
}

void Core::logic()
{
	moveEvent();
	
}

void Core::moveEvent()
{

	float time = screen.getTime();
	screen.setFrame(time);
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player.moveUp(time, view,screen.getFrame());
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player.moveDown(time, view  , screen.getFrame());
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player.moveRight(time, view, screen.getFrame());
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player.moveLeft(time, view, screen.getFrame());
	}
	
	player.checkRotation();
}

void Core::viewRender(float x, float y)
{
	
}

