#pragma once

#include <string>
#include <vector>
#include <SFML\Graphics\Sprite.hpp>

namespace sf { class RenderWindow; }
class Tile;

class World {
public:
	bool loadWorldData( std::string string );
	unsigned int getTileId( unsigned int x, unsigned int y );

	void draw( sf::RenderWindow& win );

	~World();
private:
	sf::Sprite mTileset;
	std::vector< std::vector< Tile* > > mTileLayer;

	unsigned int mWidth;
	unsigned int mHeight;
	unsigned int mTileSize;
};