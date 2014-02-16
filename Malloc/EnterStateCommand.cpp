#include "EnterStateCommand.h"

EnterStateCommand::EnterStateCommand(diff::Difficulty& gDiff, diff::Difficulty tarDiff, StateList &sList, StateList::State_Type nextState) :
	mGDiff(gDiff), mTarDiff(tarDiff), mSList(sList), mNextState(nextState) {

}

void EnterStateCommand::execute() {
	mGDiff = mTarDiff;
	mSList.changeState(mNextState);
}