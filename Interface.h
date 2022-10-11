#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
class Interface
{
private :
	Font font; // Font 
	sf::Text text; // Text
	sf::Text counter; // Counter
	int i; // for every char in (text) to print char after char
	float time; // time...
	sf::String str; // message
	sf::String temp; // temperorary string
	bool start; // start to draw text
	std::vector<Texture> tex; // two textures : Menu and Ruble icon
	std::vector<Sprite> sprite; // two sprites : MEnu and Ruble icon
	std::vector<sf::RectangleShape> borders; // array of borders
	
public:
	Interface();
	void setStartFlag(bool start);
	void update( View& view); // update interface
	void drawInterface(RenderWindow* window, float time); // draw interface
	void drawMenu(RenderWindow* window,int frame); // draw menu function
private:
	void setTextPosition(View& view); //Set text Position
	void setCounterPosition(View& view); // set icon and counter position
	void initBordersRect();
	void setBordersPos(View& view);
	void initSprites();
	void initText();
	

};
