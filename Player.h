#pragma once
#include "SFMLOrthogonalLayer.hpp"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
using namespace sf;




class Player : public GameObject
{
public:
	 enum  Direction
	{
		Up = 0,
		Down,
		Left,
		Right
	};

	Sprite playerSprite;
	Direction dir;
private :
	float speed;
	bool isMoving;
	bool collision;
	void isHeroMoving();
public:
	void Init() override;
	float getSpeed();
	sf::Vector2f getPlayerCoords();
	Player();
	void moveLeft(float time , View & view , int frame);
	void moveRight(float time, View& view, int frame);
	void moveUp(float time, View& view, int frame);
	void moveDown(float time, View& view, int frame);
	void checkRotation();
	void setCollisionFlag(bool flag);
	void collisionMovement();
	
	
};

