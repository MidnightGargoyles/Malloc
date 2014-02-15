#pragma once

#include <string>
#include <vector>

class Tile;

class World {
public:
	bool loadWorldData( std::string string );
	unsigned int getTileId( unsigned int x, unsigned int y );
private:
	std::vector< std::vector< Tile* > > mTileLayer;

	unsigned int mWidth;
	unsigned int mHeight;
	unsigned int mTileSize;
};