#pragma once
#include "SFMLOrthogonalLayer.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;
class GameObject
{
protected:

	unsigned int x;
	unsigned int y;
	Texture tex;
public:
	virtual void Init() = 0;
	GameObject();

};

