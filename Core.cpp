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
		screen.updateTime();
		/*player.moveUp(screen.getTime() , view , screen.getFrame());*/
		logic();
		viewRender();
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

Core::~Core()
{
	
}

void Core::draw()
{
	int i = 0;
	for (auto el : map.getLayers())
	{

		windowHandle->draw(*el);
		i++;
		 
	}
	windowHandle->draw(player.playerSprite);
	
}

void Core::logic()
{
	collission();
	moveEvent();
	
}

void Core::moveEvent()
{

	auto time = screen.getTime(); // время за один кадр
	screen.setFrame(time); // установить определенный кадр для анимации
	bool directionIsUsed = false; // ограничить движение наискось и тд.
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		
		if (!directionIsUsed) {
			player.moveUp(time, view, screen.getFrame());
			directionIsUsed = true;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (!directionIsUsed) {
			player.moveDown(time, view, screen.getFrame());
			directionIsUsed = true;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (!directionIsUsed) {
			player.moveRight(time, view, screen.getFrame());
			directionIsUsed = true;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (!directionIsUsed) {
			player.moveLeft(time, view, screen.getFrame());
			directionIsUsed = true;
		}
	}
	
	player.checkRotation();
}

void Core::collission()
{
	auto time = screen.getTime();
	for (auto el : map.coll)
	{
		
		auto objectVertices = getVerticesObj(el);
		auto playerVertices = getVerticesPl(player.playerSprite);


		

		if (vec2::gjk(playerVertices , objectVertices) )
		{
			player.setCollisionFlag(true);
			player.collisionMovement(time);
		}
		else
		{
			player.setCollisionFlag(false);
		}
		
			
		
		
	}
			
}



void Core::viewRender()
{
	view.setCenter(map.cameraPositions[0].getPosition().x , map.cameraPositions[0].getPosition().y);
}

std::vector<vec2> Core::getVerticesObj(Object& o)
{
	
	std::vector<vec2> object = { vec2(o.getAABB().left ,  o.getAABB().top)  , vec2(o.getAABB().left , o.getAABB().top + o.getAABB().height) , vec2(o.getAABB().left + o.getAABB().width , o.getAABB().top ) , vec2(o.getAABB().left + o.getAABB().width , o.getAABB().top + o.getAABB().height   )   };

	return object;
}

std::vector<vec2> Core::getVerticesPl(sf::Sprite& p)
{
	std::vector<vec2> player = { vec2(p.getGlobalBounds().left, p.getGlobalBounds().top), vec2(p.getGlobalBounds().left, p.getGlobalBounds().top + p.getGlobalBounds().height), vec2(p.getGlobalBounds().left + p.getGlobalBounds().width, p.getGlobalBounds().top), vec2(p.getGlobalBounds().left + p.getGlobalBounds().width, p.getGlobalBounds().top + p.getGlobalBounds().height) };


	return player;
}



