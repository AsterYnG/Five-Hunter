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
	
	return playerSprite.getPosition();

}

Player::Player():GameObject()
{
	Init();
}

void Player::moveLeft(float time,  int frame)
{
	isMoving = true;
	
	
	if (!collision) {
		
		dir = Direction::Left;
	playerSprite.move(-time * speed, 0);
	isMoving = true;
	
	}
	
	prevDir = dir;
	for (int i = 0; i < 6; i++)
	{
		if (frame == i)
		{
			playerSprite.setTextureRect(IntRect(382+i * 32, 44, 30, 42));
		}
	}
	
}

void Player::moveRight(float time,  int frame)
{
	
	
	if (!collision) { 
		
		dir = Direction::Right; 
	
	playerSprite.move(time * speed, 0);
	isMoving = true;
	
	}
	prevDir = dir;
	for (int i = 0 ; i < 6 ; i++)
	{
		if (frame == i)
		{
			playerSprite.setTextureRect(IntRect(i * 32,44 ,30 ,42));
		}
	}
	
}

void Player::moveUp(float time,  int frame)
{
	
	
	if (!collision) { 
		
		dir = Direction::Up; 
	playerSprite.move(0, -time * speed);
	isMoving = true;
	
	}
	prevDir = dir;
	for (int i = 0; i < 6; i++)
	{
		if (frame == i)
		{
			playerSprite.setTextureRect(IntRect(188 + i * 32, 44, 30, 42));
		}
	}
	
}

void Player::moveDown(float time,  int frame)
{
	
	
	if (!collision) { 
		
		dir = Direction::Down; 
	playerSprite.move(0, time * speed);
	isMoving = true;
	
	}
	prevDir = dir;
	
	for (int i = 0; i < 6; i++)
	{
		if (frame == i)
		{
			playerSprite.setTextureRect(IntRect(574 + i * 32, 44, 30, 42));
		}
	}
	
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

		if (dir == Direction::Left) playerSprite.setTextureRect(IntRect(62, 0, 30, 42));
		if (dir == Direction::Right) playerSprite.setTextureRect(IntRect(0, 0, 30, 42));
		if (dir == Direction::Up) playerSprite.setTextureRect(IntRect(28, 0, 30, 42));
		if (dir == Direction::Down) playerSprite.setTextureRect(IntRect(92, 0, 30, 42));
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
			playerSprite.move(time * speed + 0.02, 0);
		}
		if (dir == Right)
		{
			playerSprite.move(-time * speed - 0.02, 0);
		}

		if (dir == Up)
		{

			playerSprite.move(0, time * speed+ 0.02);
		}
		if (dir == Down)
		{

			playerSprite.move(0, -time * speed- 0.02);
		}
	}
	
	
	
}

int Player::getDir()
{
	return dir;
}



