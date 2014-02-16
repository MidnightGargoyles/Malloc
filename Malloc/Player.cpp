#include "Player.h"
#include "TextureStore.h"
#include "SFML\Window\Keyboard.hpp"
#include "SFML\Graphics\RenderWindow.hpp"
#include "GameData.h"
#include "PlayStateData.h"
Player::Player(const sf::Vector2i startPos) : mSprite(TextureStore::getTexture("res/characters")), mPos(startPos)
{
	mSprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
	mSprite.setOrigin(16, 16);
	addSubtype(Creature_Subtype::INCORPOREAL);
}


Player::~Player()
{
}


void Player::update(GameData &gData, PlayStateData &pData) {
	for(auto it = gData.events->begin(); it != gData.events->end(); ++it) {
		switch(it->type) {
		case sf::Event::KeyPressed:
			if(it->key.code == sf::Keyboard::W)
				pData.w.move(this, sf::Vector2i(mPos.x, mPos.y - 1));
			if(it->key.code == sf::Keyboard::A)
				pData.w.move(this, sf::Vector2i(mPos.x - 1, mPos.y));
			if(it->key.code == sf::Keyboard::S)
					pData.w.move(this, sf::Vector2i(mPos.x, mPos.y + 1));
			if(it->key.code == sf::Keyboard::D)
				pData.w.move(this, sf::Vector2i(mPos.x + 1, mPos.y));
			break;
		}
	}
}

void Player::draw(sf::RenderWindow &win) {
	mSprite.setPosition(mPos.x*32+16, mPos.y*32+16);
	win.draw(mSprite);
}

const sf::Vector2i& Player::getPos() const {
	return mPos;
}

const sf::Vector2i& Player::getTarget() const {
	return mPos;
}

void Player::setPos( sf::Vector2i pos ) {
	mPos = pos;
}

void Player::act( GameObject* obj ) {

}

bool Player::isAlly( GameObject* obj ) {
	return obj->getObjectType() == GameObject_Type::PLAYER;
}

GameObject_Type Player::getObjectType() {
	return GameObject_Type::PLAYER;
 }