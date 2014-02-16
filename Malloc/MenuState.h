#pragma once
#include "StateList.h"
#include "Shortcut.h"
#include "SFML\Graphics\Sprite.hpp"
class MenuState : public State
{
public:
	MenuState(StateList &owners, GameData &gData);
	~MenuState();
	virtual void update(GameData &gData);
	virtual void draw(sf::RenderWindow &win);
private:
	Shortcut mEasy;
	sf::Sprite mBackground;
};

