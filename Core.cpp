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
	view.setCenter(map.player_coords[0].getPosition().x, map.player_coords[0].getPosition().y);
	
	
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
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player.playerSprite.move(0, -time * player.getSpeed());
		view.move(0, -time * player.getSpeed());
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player.playerSprite.move(0, time * player.getSpeed());
		view.move(0, time * player.getSpeed());
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player.playerSprite.move(time * player.getSpeed(), 0);
		view.move(time * player.getSpeed(), 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player.playerSprite.move(-time * player.getSpeed(), 0);
		view.move(-time * player.getSpeed(), 0);
	}
}

void Core::viewRender(float x, float y)
{
	
}

