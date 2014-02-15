#pragma once
class StateList;
class State
{
public:
	State(StateList &owner);
	virtual ~State(){}
	virtual void update();
	virtual void draw();
protected:
	StateList &mOwner;
};

