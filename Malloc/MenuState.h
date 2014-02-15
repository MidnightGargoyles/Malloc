#pragma once
#include "StateList.h"
class MenuState : public State
{
public:
	MenuState(StateList &owners);
	~MenuState();
};

