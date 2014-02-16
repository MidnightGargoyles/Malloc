#include "MenuState.h"
#include "EnterStateCommand.h"
#include "TextureStore.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "GameData.h"
#include "Difficulty.h"

MenuState::MenuState(StateList &owner, GameData &gData) : State(owner), 
	mEasy(sf::Vector2f(0, 0), 
	new EnterStateCommand(gData.difficulty, diff::EASY, owner, StateList::PLAY)),
	mBackground(TextureStore::getTexture("res/crapOS"))
{
	
}


MenuState::~MenuState()
{
}

void MenuState::update(GameData &gData) {
	mEasy.update(gData);
}

void MenuState::draw(sf::RenderWindow &win) {
	win.draw(mBackground);
	mEasy.draw(win);
}