#pragma once
namespace sf {
	class RenderWindow;
};
#include "State.h"

class StateList
{
public:
	enum State_Type {
		MENU, PLAY
	};
	StateList();
	~StateList();
	void changeState(State_Type state);
	void update();
	void draw(sf::RenderWindow &win);
private:
	State* mStates[2];
	unsigned char mSize;
	State* mCurState;
};