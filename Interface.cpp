#include "Interface.h"

Interface::Interface()
{
	
	 
	 initSprites();
	 initBordersRect();
	 initText();

	
	i = 0;
	time = 0;
	
	showText = true;
}



void Interface::update( View& view)
{

	setCounterPosition(view);
	setTextPosition(view);
	setBordersPos(view);
	closeText();
}

void Interface::drawInterface(RenderWindow* window, float time)
{
	this->time += time;
	if (this->time >= 4) {
		if (showText) {
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
				}
			}
			else
			{
				if(int(this->time) == 4)
				{
					tex[2].loadFromFile("assets/Image/F_icon(1).png");
				}
				if(int(this->time) == 5)  tex[2].loadFromFile("assets/Image/F_icon(2).png");
				if (int(this->time) == 6) this->time = 4;

				window->draw(sprite[2]);
			}
			window->draw(borders[0]);
			window->draw(text);
			
				
			

		}
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
	
	window->draw(sprite[0]);
	
}



void Interface::setTextPosition(View& view)
{
	text.setPosition(borders[0].getPosition().x +6 , borders[0].getPosition().y +2);
	sprite[2].setPosition(borders[0].getGlobalBounds().left + borders[0].getGlobalBounds().width - 60, borders[0].getGlobalBounds().top + borders[0].getGlobalBounds().height +3);
}

void Interface::setCounterPosition(View& view)
{
	sprite[1].setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y + view.getSize().y / 2 - 32/2);
	counter.setPosition(view.getCenter().x - view.getSize().x / 2 + 20, view.getCenter().y + view.getSize().y / 2 - counter.getCharacterSize()/4);
	
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
	borders[1].setSize(sf::Vector2f(view.getSize().x / 8, view.getSize().y / 16));
	borders[0].setPosition(view.getCenter().x - view.getSize().x / 2 + 16, view.getCenter().y - view.getSize().y / 2 + 3);
	borders[1].setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y + view.getSize().y / 2 - borders[1].getSize().y);
	
}

void Interface::initSprites()
{
	tex = { Texture() , Texture(), Texture() };
	sprite = { Sprite() , Sprite() , Sprite() };
	tex[0].loadFromFile("assets/Image/start_menu(none).png");
	
	
	sprite[0].setTexture(tex[0]);
	
	tex[1].loadFromFile("assets/Image/rubble_icon.png");
	
	sprite[1].setTexture(tex[1]);
	sprite[1].setScale(0.5, 0.5);
	
	tex[2].loadFromFile("assets/Image/F_icon(1).png");
	sprite[2].setTexture(tex[2]);
}

void Interface::initText()
{
	font.loadFromFile("fonts/F77 Minecraft.ttf");
	counter.setFont(font);
	counter.setFillColor(Color(0,246,181,255));
	counter.setStyle(Text::Bold);
	counter.setCharacterSize(70);
	counter.setScale(0.25, 0.25);
	counter.setString(L"0");
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

void Interface::closeText()
{
	if(Keyboard::isKeyPressed(Keyboard::F))
	{
		showText = false;
	}
}

void Interface::setCounter(int money)
{
	counter.setString(std::to_wstring(money));
}
