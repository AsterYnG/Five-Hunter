#pragma once
#include "SFMLOrthogonalLayer.hpp"
#include "Money.h"
using namespace tmx;
class TileMap
{
public:
	TileMap();
	std::vector <MapLayer*> getLayers();
	std::vector <Object>& getGameObjects();
	~TileMap();
	Money cash; // coins on the map:)
	Money* getCoins();
	std::vector<Object> player_coords; // player coords
	std::vector <Object> coll; //collisions Xd
	std::vector <Object> cameraPositions; // positions of camera:)
	std::vector <Object> coins;
private:
	
private:
	Map map; // .tmx file (Tiled map)
	std::vector <MapLayer*> layers; //  Tile layers(Ptrs)
};

