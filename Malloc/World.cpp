#include "World.h"
#include "tinyxml2.h"
#include "XMLParser.h"
#include "TextureStore.h"
#include <map>
#include <SFML\Graphics\Texture.hpp>
#include <vector>

bool World::loadWorldData( std::string file ) {
	std::map< unsigned int, const sf::Texture* > gidToTexture;
	static const int solidIds[] = { 0, 1, 2, 3 };
	int x = 0;
	int y = 0;

	auto mapHandler = [&](tinyxml2::XMLElement* e) {
		mWidth = e->IntAttribute("width");
		mHeight = e->IntAttribute("height");
		mTileSize = e->IntAttribute("tilewidth");
		mTileLayer.resize( mWidth, std::vector< Tile* >( mHeight, nullptr ) );
	};

	auto tilesetHandler = [&](tinyxml2::XMLElement* e) {
		unsigned int gid = e->IntAttribute("firstgid");
		tinyxml2::XMLElement* child = e->FirstChildElement();
		std::string textureFile = child->Attribute("source");
		textureFile = textureFile.substr( 0, textureFile.find_last_of('.') );
		const sf::Texture* texture = &TextureStore::getTexture( textureFile );
		gidToTexture[gid] = texture;
	};

	auto tilehandler = [&](tinyxml2::XMLElement* e) {
		unsigned int gid = e->IntAttribute("gid");
		bool solid = false;
		for( unsigned int i : solidIds ) {
			if( gid != i ) continue;
			solid = true;
			break;
		}
		++x;
		if( x == mWidth ) {
			x = 0;
			++y;
		}
	};

	ch::XMLParser parser;
	parser.hook( "map", mapHandler );

	return parser.parse( "test.tmx" );
}

unsigned int World::getTileId( unsigned int x, unsigned int y ) {
	return 0;
}