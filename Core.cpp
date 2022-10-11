#include "Core.h"

void Core::Render()
{
	int menuFrame = 0;
	Event event;
	while (windowHandle->isOpen())
	{
		while (windowHandle->pollEvent(event))
		{
			if (event.type == Event::Closed) windowHandle->close();
			fullscreenMode(event);
			resize(event);
			
			if(menu) menuFrame = menuEvent(event);
		}
		if(!menu)
		{
		screen.updateTime();
		
		logic();
		updateInterface(view.getView());
		view.updateView(windowHandle);

		}
		
		windowHandle->clear();
		if (!menu) {
			draw();
		}
		else { 
			gameIn.drawMenu(windowHandle, menuFrame); 
		}
		
		windowHandle->display();
		
	}
}

Core::Core()
{
	screen.createWindow(800, 600);
	windowHandle = screen.getWindowHandle();
	player.playerSprite.setPosition(map.player_coords[0].getPosition().x, map.player_coords[0].getPosition().y);
	view.init(map.player_coords[0]);
	menu = true;
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
		gameIn.drawInterface(windowHandle, screen.getTime());
	
}

void Core::logic()
{
	collission();
	moveEvent();
	view.renderView(player.getPlayerCoords(),player.getDir() );
}

void Core::moveEvent()
{

	auto time = screen.getTime(); // время за один кадр
	screen.setFrame(time); // установить определенный кадр для анимации
	bool directionIsUsed = false; // ограничить движение наискось и тд.
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

void Core::start(sf::Event& event)
{
	if (event.type == Event::KeyPressed)
	{
		if(event.key.code == Keyboard::P)
		{
			gameIn.setStartFlag(1);
		}
	}
}

int Core::menuEvent(sf::Event& event)
{
	if (event.type == Event::MouseMoved)
	{
		if (event.mouseMove.x >= 175 && event.mouseMove.x <= 626)
		{
			if (event.mouseMove.y >= 168 && event.mouseMove.y <= 269)
			{
				
				return 1;
			}
			if (event.mouseMove.y >= 301 && event.mouseMove.y <= 400)
			{
				
				return 2;
			}
		}
		else return 0;
		
	}
	if(event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.x >= 175 && event.mouseButton.x <= 626)
		{
			if (event.mouseButton.y >= 168 && event.mouseButton.y <= 269)
			{
				if (event.mouseButton.button == Mouse::Button::Left) 
				{
					menu = false;
					windowHandle->create(VideoMode(1920, 1080), "Five&Hunter" , Style::Fullscreen);
					view.changeSize(1920, 1080);
				}
				return 0;
			}
			if (event.mouseButton.y >= 301 && event.mouseButton.y <= 400)
			{
				if (event.mouseButton.button == Mouse::Button::Left) windowHandle->close();
				return 0;
			}

		}
		else return 0;
	}
	
}

void Core::updateInterface(View& view)
{
	gameIn.update(view);
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



