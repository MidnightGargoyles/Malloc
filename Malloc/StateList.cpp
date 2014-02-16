#include "StateList.h"
#include "PlayState.h"
#include "MenuState.h"
#include <cassert>
#include "SFML\Graphics\RenderWindow.hpp"

StateList::StateList() : mCurState(0), mSize(2)
{
	mStates[0] = new PlayState(*this);
	mStates[1] = new MenuState(*this);
	changeState(MENU);
}


StateList::~StateList()
{
	for(unsigned char i = 0; i < mSize; i++) {
		delete mStates[i];
	}
}

void StateList::changeState(State_Type state) {
	switch(state) {
	case MENU:
		mCurState = mStates[0];
		break;
	case PLAY:
		mCurState = mStates[1];
		break;
	default:
		assert(false);
		break;
	}
}

void StateList::update() {
	assert(mCurState != 0);
	mCurState->update();
}

void StateList::draw(sf::RenderWindow &win) {
	mCurState->draw(win);
}