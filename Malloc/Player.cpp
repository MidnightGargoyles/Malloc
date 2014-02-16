#include "Player.h"
#include "TextureStore.h"
#include "SFML\Window\Keyboard.hpp"
#include "SFML\Graphics\RenderWindow.hpp"
Player::Player() : mSprite(TextureStore::getTexture(""))
{
	mSprite.setTextureRect(sf::IntRect(0, 0, 32, 32)); // TODO proper intRect
	mSprite.setOrigin(16, 16);
}


Player::~Player()
{
}


void Player::update() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		++mPos.y;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		--mPos.y;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		--mPos.x;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		++mPos.x;
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