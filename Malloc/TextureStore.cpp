#include "TextureStore.h"

TextureStore TextureStore::store;

const sf::Texture& TextureStore::getTexture(std::string ref) {
	ref += ".png";
	if(store.mTextures.count(ref) == 0)
	{
		sf::Texture* t = new sf::Texture();
		t->loadFromFile(ref);
		store.mTextures.insert(std::pair<std::string, sf::Texture*>(ref, t));
		return *t;
	}
	return *store.mTextures.at(ref);
}

TextureStore::TextureStore() : mTextures() {
}


TextureStore::~TextureStore() {
}
