#include "Player.h"



void Player::Init()
{
	
	if (tex.loadFromFile("assets/Image/sprite.png"))
	{
		
		playerSprite.setTexture(tex);
		playerSprite.setTextureRect(IntRect(92, 0, 32, 42));
	}
	else { std::cout << " error with reading hero sprite" << std::endl; }
	speed = 100;
	
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
