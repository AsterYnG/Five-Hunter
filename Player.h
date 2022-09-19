#pragma once
#include "SFMLOrthogonalLayer.hpp"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
using namespace sf;
class Player : public GameObject
{
public:
	
	Sprite playerSprite;
private :
	float speed;
	Texture texAnim;
	
public:
	void Init() override;
	float getSpeed();
	sf::Vector2f getPlayerCoords();
	Player();
};

