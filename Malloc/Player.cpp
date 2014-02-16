#include "Player.h"
#include "TextureStore.h"
#include "SFML\Window\Keyboard.hpp"
#include "SFML\Graphics\RenderWindow.hpp"
#include "GameData.h"mPos.y;
Player::Player() : mSprite(TextureStore::getTexture("res/Jerrko")), mPos(0, 0)
{
	mSprite.setTextureRect(sf::IntRect(0, 0, 32, 32)); // TODO proper intRect
	mSprite.setOrigin(16, 16);
}


Player::~Player()
{
}


void Player::update(GameData *gData) {
	for(auto it = gData->events->begin(); it != gData->events->end(); ++it) {
		switch(it->type) {
		case sf::Event::KeyPressed:
			if(it->key.code == sf::Keyboard::W)
				--mPos.y;
			if(it->key.code == sf::Keyboard::A)
				--mPos.x;
			if(it->key.code == sf::Keyboard::S)
				++mPos.y;
			if(it->key.code == sf::Keyboard::D)
				++mPos.x;
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