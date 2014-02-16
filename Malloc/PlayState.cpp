#include "PlayState.h"
#include "SFML\Graphics\RenderWindow.hpp"

PlayState::PlayState(StateList &owner) : State(owner), mPlayer(sf::Vector2i(4, 6)), mData() {
	mData.w.loadWorldData("test.tmx");
}


PlayState::~PlayState() {
}

void PlayState::draw(sf::RenderWindow &win) {
	mData.w.draw(win);
	mPlayer.draw(win);
}

void PlayState::update(GameData &gData) {
	mPlayer.update(gData, mData);
}