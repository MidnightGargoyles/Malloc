#pragma once

#include "StateList.h"
#include "Difficulty.h"
#include "Command.h"

class EnterStateCommand : public Command {
public:
	EnterStateCommand(diff::Difficulty& gDiff, diff::Difficulty tarDiff, StateList &sList, StateList::State_Type nextState);
	virtual void execute();
private:
	diff::Difficulty& mGDiff;
	diff::Difficulty mTarDiff;
	StateList &mSList;
	StateList::State_Type mNextState;
	
};