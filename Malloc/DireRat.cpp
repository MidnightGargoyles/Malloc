#include "DireRat.h"
#include "TextureStore.h"
#include "SFML\Graphics\RenderWindow.hpp"

DireRat::DireRat(const sf::Vector2i &startPos) : mPos(startPos), mSprite(TextureStore::getTexture("res/characters")) {
	mSprite.setTextureRect(sf::IntRect(224, 0, 32, 32));
	mSprite.setOrigin(16, 16);
}


DireRat::~DireRat() {
}

void DireRat::update(GameData &gData, PlayStateData &pData) {

}

void DireRat::draw(sf::RenderWindow &win) {
	mSprite.setPosition(mPos.x*32+16, mPos.y*32+16);
	win.draw(mSprite);
}

const sf::Vector2i& DireRat::getPos() const {
	return mPos;
}

const sf::Vector2i& DireRat::getTarget() const {
	return mPos;
}

void DireRat::act( GameObject* obj ) {

}