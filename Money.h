#pragma once
#include "GameObject.h"

class Money : public GameObject
{
public :
	void setParametres(std::vector <tmx::Object> coins);
	void draw(sf::RenderWindow* windowHandle);
	~Money();
	bool isAvailableToPick(sf::Vector2f position);
	void isPickedUp(bool isPickedUp);
private:
	void Init();
	std::vector <sf::Sprite*> moneySprites;
	sf::Texture* tex; // Basic Texture of a coin
	sf::Texture* tex2; // Texture of a pickable coin
	int coinToPick;
};

