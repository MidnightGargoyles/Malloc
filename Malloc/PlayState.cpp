#include "PlayState.h"
#include "SFML\Graphics\RenderWindow.hpp"

PlayState::PlayState(StateList &owner) : State(owner), mPlayer() {
}


PlayState::~PlayState() {
}

void PlayState::draw(sf::RenderWindow &win) {
	mPlayer.draw(win);
}

void PlayState::update(GameData *gData) {
	mPlayer.update(gData);
}