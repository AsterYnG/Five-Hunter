#include "Core.h"

void Core::Render()
{
	
	Event event;
	while (windowHandle->isOpen())
	{
		while (windowHandle->pollEvent(event))
		{
			if (event.type == Event::Closed) windowHandle->close();
			fullscreenMode(event);
			resize(event);
		}
		screen.updateTime();
		/*player.moveUp(screen.getTime() , view , screen.getFrame());*/
		logic();
		
		view.updateView(windowHandle);
		
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
	view.init(map.player_coords[0]);
	
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
	view.renderView(player.getPlayerCoords(),player.getDir() );
}

void Core::moveEvent()
{

	auto time = screen.getTime(); // ����� �� ���� ����
	screen.setFrame(time); // ���������� ������������ ���� ��� ��������
	bool directionIsUsed = false; // ���������� �������� �������� � ��.
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		
		if (!directionIsUsed) {
			player.moveUp(time,  screen.getFrame());
			directionIsUsed = true;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (!directionIsUsed) {
			player.moveDown(time,  screen.getFrame());
			directionIsUsed = true;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (!directionIsUsed) {
			player.moveRight(time,  screen.getFrame());
			directionIsUsed = true;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (!directionIsUsed) {
			player.moveLeft(time,  screen.getFrame());
			directionIsUsed = true;
		}
	}
	
	player.checkRotation();
}

void Core::collission()
{
	auto time = screen.getTime();
	auto playerVertices = getVerticesPl(player.playerSprite);
	for (auto el : map.coll)
	{
		
		auto objectVertices = getVerticesObj(el);


		

		if (vec2::gjk(playerVertices , objectVertices) )
		{
			player.setCollisionFlag(true);
			player.collisionMovement(time);
			view.setCollisionFlag(true);
		}
		else
		{
			player.setCollisionFlag(false);
		}
	}
	for (auto cam : map.cameraPositions)
	{
		auto cameraVertices = getVerticesObj(cam);
		if(vec2::gjk(playerVertices , cameraVertices))
		{
			for (int i = 1 ; i < 7 ; i ++)
			{
				if (std::stoi(cam.getName()) == i) view.setCameraPreSet(i);
			}
		}
	}
			
}

void Core::fullscreenMode(sf::Event& event)
{
	if (event.type == Event::KeyPressed)
	{
		if(event.key.code == Keyboard::F)
		{
			windowHandle->create(VideoMode(1920, 1080), "Five&Hunter", Style::Fullscreen);
			view.changeSize(1920,1080);
		}
		if(event.key.code == Keyboard::Escape)
		{
			windowHandle->create(VideoMode(800, 600), "Five&Hunter");
			view.changeSize(800, 600);
		}
	}
}

void Core::resize(sf::Event& event)
{
	if (event.type == Event::Resized)
	{
		view.changeSize(event.size.width, event.size.height);
		windowHandle->setSize(sf::Vector2u(event.size.width, event.size.height));
	}
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



