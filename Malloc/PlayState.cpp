#include "PlayState.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "Player.h"
PlayState::PlayState(StateList &owner) : State(owner), mData() {
	mData.w.loadWorldData("test.tmx");
	mData.player = new Player(mData.w.getStartPos());
}


PlayState::~PlayState() {
}

void PlayState::draw(sf::RenderWindow &win) {
	mData.w.draw(win);
	mData.player->draw(win);
}

void PlayState::update(GameData &gData) {
	mData.player->update(gData, mData);
}