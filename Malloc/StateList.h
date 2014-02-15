#pragma once
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
	void draw();
private:
	State* mStates[2];
	unsigned char mSize;
	State* mCurState;
};