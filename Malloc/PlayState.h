#pragma once

#include "State.h"
#include "Player.h"

class PlayState : public State
{
public:
	PlayState(StateList &owner);
	~PlayState();

	virtual void draw(sf::RenderWindow &win);
private:
	Player mPlayer;
};

