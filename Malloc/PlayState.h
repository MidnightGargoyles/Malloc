#pragma once

#include "State.h"
#include "PlayStateData.h"
class PlayState : public State
{
public:
	PlayState(StateList &owner);
	~PlayState();

	virtual void draw(sf::RenderWindow &win);
	virtual void update(GameData &gData);
private:
	PlayStateData mData;
};

