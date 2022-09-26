#include "Player.h"
#include <iostream>


void Player::Init()
{
	
	if (tex.loadFromFile("assets/Image/sprite.png"))
	{
		
		playerSprite.setTexture(tex);
		playerSprite.setTextureRect(IntRect(92, 0, 32, 42));
	}
	else { std::cout << " error with reading hero sprite" << std::endl; }
	playerSprite.setOrigin(15, 20);
	speed = 100;
	isMoving = false;
	collision = false;
	dir = Direction::Down;
	
}

float Player::getSpeed()
{
	return speed;
}

sf::Vector2f Player::getPlayerCoords()
{
	x = playerSprite.getPosition().x;
	y = playerSprite.getPosition().y;
	sf::Vector2f Coords(this->x , this->y);
	return Coords;

}

Player::Player():GameObject()
{
	Init();
}

void Player::moveLeft(float time, View& view, int frame)
{
	isMoving = true;
	
	
	if (!collision) {
		prevDir = dir;
		dir = Direction::Left;
	playerSprite.move(-time * speed, 0);
	isMoving = true;
	}
	

	for (int i = 0; i < 6; i++)
	{
		if (frame == i)
		{
			playerSprite.setTextureRect(IntRect(382+i * 32, 44, 26, 42));
		}
	}
	std::cout << "Left" << std::endl;
}

void Player::moveRight(float time, View& view, int frame)
{
	
	
	if (!collision) { 
		prevDir = dir;
		dir = Direction::Right; 
	
	playerSprite.move(time * speed, 0);
	isMoving = true;
	}
	for (int i = 0 ; i < 6 ; i++)
	{
		if (frame == i)
		{
			playerSprite.setTextureRect(IntRect(i * 32,44 ,26 ,42));
		}
	}
	std::cout << "Right" << std::endl;
}

void Player::moveUp(float time, View& view, int frame)
{
	
	
	if (!collision) { 
		prevDir = dir;
		dir = Direction::Up; 
	playerSprite.move(0, -time * speed);
	isMoving = true;
	}
	
	for (int i = 0; i < 6; i++)
	{
		if (frame == i)
		{
			playerSprite.setTextureRect(IntRect(188 + i * 32, 44, 30, 42));
		}
	}
	std::cout << "Up" << std::endl;
}

void Player::moveDown(float time, View& view, int frame)
{
	
	
	if (!collision) { 
		prevDir = dir;
		dir = Direction::Down; 
	playerSprite.move(0, time * speed);
	isMoving = true;
	}
	
	
	for (int i = 0; i < 6; i++)
	{
		if (frame == i)
		{
			playerSprite.setTextureRect(IntRect(574 + i * 32, 44, 26, 42));
		}
	}
	std::cout << "Down" << std::endl;
}

void Player::isHeroMoving()
{
	if (!(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::S)))
	{
		isMoving = false;
	}
	
}

void Player::checkRotation()
{
	isHeroMoving();
	if (!isMoving){

		if (dir == Direction::Left) playerSprite.setTextureRect(IntRect(62, 0, 26, 42));
		if (dir == Direction::Right) playerSprite.setTextureRect(IntRect(0, 0, 26, 42));
		if (dir == Direction::Up) playerSprite.setTextureRect(IntRect(28, 0, 32, 42));
		if (dir == Direction::Down) playerSprite.setTextureRect(IntRect(92, 0, 32, 42));
	}
}

void Player::setCollisionFlag(bool flag)
{
	collision = flag;
}

void Player::collisionMovement(float time)
{
	if (isMoving) {
		if (dir == Left)
		{
			playerSprite.move(time * speed , 0);
		}
		if (dir == Right)
		{
			playerSprite.move(-time * speed , 0);
		}
		
		if (dir == Up)
		{
			if(prevDir == Right) playerSprite.move(-time * speed-5, 0);
			playerSprite.move(0, time * speed );
		}
		if (dir == Down)
		{
			if (prevDir == Right) playerSprite.move(-time * speed -5, 0);
			playerSprite.move(0, -time * speed );
		}
	}
	
}




