#include "Interface.h"

Interface::Interface()
{
	
	 
	 initSprites();
	 initBordersRect();
	 initText();

	
	i = 0;
	time = 0;
	start = false;
	
}

void Interface::setStartFlag(bool start)
{
	this->start = start;
}

void Interface::update( View& view)
{

	setCounterPosition(view);
	setTextPosition(view);
	setBordersPos(view);
	
}

void Interface::drawInterface(RenderWindow* window, float time)
{
	this->time += time;
	if (this->time >= 4) {
		if (i < str.getSize()) {

			if (this->time >= 4.1) {

				if (text.getGlobalBounds().left + text.getGlobalBounds().width >= borders[0].getGlobalBounds().left + borders[0].getGlobalBounds().width - 10)
				{
					temp.erase(temp.getSize() - 1);
					temp += '\n';
				}
				temp += str[i];
				text.setString(temp);

				this->time = 4;
				i++;

				std::cout << text.getGlobalBounds().width << std::endl;
			}
		}
		window->draw(borders[0]);
		window->draw(text);
	}
		window->draw(borders[1]);
		window->draw(sprite[1]);
		window->draw(counter);
	
	
	
}

void Interface::drawMenu(RenderWindow* window, int frame)
{
	if (frame == 0 )
	{
		tex[0].loadFromFile("assets/Image/start_menu(none).png");
	
	}
	if(frame == 1) 
	{
		tex[0].loadFromFile("assets/Image/start_menu(start).png");

	}
	if(frame == 2)
	{
		tex[0].loadFromFile("assets/Image/start_menu(exit).png");
	}
	sprite[0].setTexture(tex[0]);
	window->draw(sprite[0]);
	
}



void Interface::setTextPosition(View& view)
{
	text.setPosition(borders[0].getPosition().x +6 , borders[0].getPosition().y +2);
	
}

void Interface::setCounterPosition(View& view)
{
	sprite[1].setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y + view.getSize().y / 2 - 32);
	counter.setPosition(view.getCenter().x - view.getSize().x / 2 + 40, view.getCenter().y + view.getSize().y / 2 - counter.getCharacterSize()/2);
	
}

void Interface::initBordersRect()
{
	borders.push_back(sf::RectangleShape(sf::Vector2f(365, 42)));
	borders.push_back(sf::RectangleShape(sf::Vector2f(100, 34)));
	borders[0].setFillColor(Color(255, 255, 255 , 100));
	
	borders[0].setOutlineThickness(3);
	borders[1].setFillColor(Color(255 ,255 ,255 , 100));
	borders[1].setOutlineThickness(1.5);
	borders[0].setOutlineColor(Color::Black);
	borders[1].setOutlineColor(Color::Black);

}

void Interface::setBordersPos(View& view)
{
	borders[0].setSize(sf::Vector2f(view.getSize().x - 32, 46));
	borders[1].setSize(sf::Vector2f(view.getSize().x / 3.4, 34));
	borders[0].setPosition(view.getCenter().x - view.getSize().x / 2 + 16, view.getCenter().y - view.getSize().y / 2 + 3);
	borders[1].setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y + view.getSize().y / 2 - 33);
	
}

void Interface::initSprites()
{
	tex = { Texture() , Texture() };
	sprite = { Sprite() , Sprite() };
	tex[0].loadFromFile("assets/Image/start_menu(none).png");
	
	
	sprite[0].setTexture(tex[0]);
	
	tex[1].loadFromFile("assets/Image/rubble_icon.png");
	
	sprite[1].setTexture(tex[1]);
	
}

void Interface::initText()
{
	font.loadFromFile("fonts/F77 Minecraft.ttf");
	counter.setFont(font);
	counter.setFillColor(Color(0,246,181,255));
	counter.setStyle(Text::Bold);
	counter.setCharacterSize(70);
	counter.setScale(0.5, 0.5);
	counter.setString(L"500");
	counter.setOutlineThickness(2);
	text.setFont(font);
	
	str = L"blablablablablablablablablablablablablalblalblalblalblalblcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc";
	text.setCharacterSize(20);
	float avrX = text.getGlobalBounds().width / 2;
	float avrY = text.getGlobalBounds().height / 2;
	text.setOrigin(avrX, avrY);
	text.setFillColor(Color::Black);
	text.setScale(0.5, 0.5);
	text.setStyle(Text::Bold);
}
