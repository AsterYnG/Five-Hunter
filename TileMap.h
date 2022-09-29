#pragma once
#include "SFMLOrthogonalLayer.hpp"
using namespace tmx;
class TileMap
{
public:
	TileMap();
	std::vector <MapLayer*> getLayers();
	~TileMap();
	std::vector<Object> player_coords; // player coords
	std::vector <Object> coll; //collisions Xd
	std::vector <Object> cameraPositions; // positions of camera:)
private:


private:
	Map map; // .tmx file (Tiled map)
	std::vector <MapLayer*> layers; //  Tile layers(Ptrs)
};

