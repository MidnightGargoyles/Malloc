#pragma once
namespace sf {
	class RenderWindow;
};
struct GameData;
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
	void update(GameData &gData);
	void draw(sf::RenderWindow &win);
private:
	State* mStates[2];
	unsigned char mSize;
	State* mCurState;
};