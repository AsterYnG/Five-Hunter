#include "TileMap.h"

TileMap::TileMap()
{
    if (map.load("assets/tilemap.tmx"))
    {
        int i = 0;
        const auto& lays = map.getLayers();
        for (const auto& layer : lays)
        {
            if (layer->getType() == tmx::Layer::Type::Object)
            {
                const auto& objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
                const auto& objects = objectLayer.getObjects();
                if(objectLayer.getName() == "collision")
                {
                    for (const auto& object : objects)
                    {
                        coll.push_back(object);
                    }
                }
                else
                {
                    for (const auto& object : objects)
                    {
                    player_coords.push_back(object);
                    }
                }
                if(objectLayer.getName() == "camera")
                {
                    for (const auto &pos : objects)
                    {
                        cameraPositions.push_back(pos);
                    }
                }
            }
            else if (layer->getType() == tmx::Layer::Type::Tile)
            {
                layers.push_back(new MapLayer(map, i));
                
            }
            i++;
        }

        const auto& tilesets = map.getTilesets();
        for (const auto& tileset : tilesets)
        {
            //read out tile set properties, load textures etc...
        }
    }
}

std::vector<MapLayer*> TileMap::getLayers()
{
    return this->layers;
}

TileMap::~TileMap()
{
    for (int i = 0 ; i < layers.size() ; i ++)
    {
        delete layers[i];
    }
}
