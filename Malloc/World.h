#pragma once

#include <string>
#include <vector>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Vector2.hpp>

namespace sf { class RenderWindow; }
class Tile;

class World {
public:
	bool loadWorldData( std::string string );
	unsigned int getTileId( sf::Vector2i position );
	const sf::Vector2i& getStartPos() const;

	void draw( sf::RenderWindow& win );

	bool isSolid(sf::Vector2i position ) const;

	void move( GameObject* obj, sf::Vector2i position );

	~World();
private:
	sf::Sprite mTileset;
	sf::Vector2i mStartPos;
	std::vector< std::vector< Tile* > > mTileLayer;

	unsigned int mWidth;
	unsigned int mHeight;
	unsigned int mTileSize;
};