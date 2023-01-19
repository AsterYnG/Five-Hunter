#include "Money.h"

void Money::setParametres(std::vector <tmx::Object> coins)
{
	Init();
	int i = 0;
	while(coins.size() != moneySprites.size())
	{
		moneySprites.push_back(new sf::Sprite(*tex));
		moneySprites[i]->setOrigin(8, 8);
		moneySprites[i]->setPosition(coins[i].getPosition().x + moneySprites[i]->getOrigin().x, coins[i].getPosition().y - moneySprites[i]->getOrigin().y);
		i++;
	}
	
	
}

void Money::draw(sf::RenderWindow* windowHandle)
{
	for(int i = 0 ; i < moneySprites.size() ; i++)
	{
		
		windowHandle->draw(*moneySprites[i]);
		
		
	}

}

Money::~Money()
{
	for(int i = 0 ; i < moneySprites.size() ; i++)
	{
		delete moneySprites[i];
	}
	delete tex;
	delete tex2;
}

bool Money::isAvailableToPick(sf::Vector2f position)
{
	int i = 0;
	for(auto el : moneySprites)
	{
		if((position.x >= el->getPosition().x - 32) & (position.x <= el->getPosition().x + 32))
		{
			if((position.y >= el->getPosition().y - 32) & (position.y <= el->getPosition().y + 32))
			{
				moneySprites[i]->setTexture(*tex2);
				coinToPick = i;
				return true;
			}
		}
		i++;
	}
	if (!((position.x >= moneySprites[coinToPick]->getPosition().x - 32) & (position.x <= moneySprites[coinToPick]->getPosition().x + 32)))
	{
		moneySprites[coinToPick]->setTexture(*tex);
	}
	if (!((position.y >= moneySprites[coinToPick]->getPosition().y - 32) & (position.y <= moneySprites[coinToPick]->getPosition().y + 32)))
	{
		moneySprites[coinToPick]->setTexture(*tex);
	}
	return false;
}

void Money::isPickedUp(bool isPickedUp)
{
	if(isPickedUp)
	{
		delete moneySprites[coinToPick];
		moneySprites[coinToPick] = new sf::Sprite();
	}
}

void Money::Init()
{
	coinToPick = 0;
	tex = new sf::Texture;
	tex2 = new sf::Texture;
	tex->loadFromFile("assets/Image/coin.png");
	tex2->loadFromFile("assets/Image/coin(pickable).png");
}
