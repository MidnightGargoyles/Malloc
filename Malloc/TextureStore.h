#pragma once
#include "SFML\Graphics\Texture.hpp"
#include <map>
#include <string>
class TextureStore
{
public:
	static const sf::Texture& getTexture(std::string ref);
private:
	TextureStore();
	TextureStore(const TextureStore&);
	TextureStore& operator=(const TextureStore&);
	~TextureStore();

	static TextureStore store;

	std::map<std::string, sf::Texture*> mTextures;
};

