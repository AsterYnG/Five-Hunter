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
	Direction dir;  // направление движения игрока
	Direction prevDir; // предыдущее направление
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
	void moveLeft(float time ,  int frame);
	void moveRight(float time,  int frame);
	void moveUp(float time,  int frame);
	void moveDown(float time,  int frame);
	void checkRotation();
	void setCollisionFlag(bool flag);
	void collisionMovement(float time);
	int getDir();
	
	
	
};

