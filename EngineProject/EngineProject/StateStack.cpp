#include "StateStack.h"

StateStack::StateStack(State::Context context)
	: mStack()
	, mPendingList()
	, mContext(context)
	, mFactories()
{
}


void StateStack::update(const GameTimer& gt)
{

	// Iterate from top to bottom, stop as soon as update() returns false
	for (auto i = mStack.rbegin(); i != mStack.rend(); ++i)
	{
		if (!(*i)->update(gt))
		{
			break;
		}


	}

	applyPendingChanges();
}

void StateStack::UpdateStateObjectCB()
{
	for (auto i = mStack.rbegin(); i != mStack.rend(); ++i)
	{

		if (!(*i)->UpdateObjectCB())
		{
			break;
		}

	}
	
}


void StateStack::draw()
{
	// Draw all active states from bottom to top
	for(State::Ptr& state: mStack)
	{
		state->draw();
	}
}

void StateStack::pushState(States::ID stateID)
{
	mPendingList.push_back(PendingChange(Push, stateID));
}

void StateStack::popState()
{
	mPendingList.push_back(PendingChange(Pop));
}

void StateStack::clearStates()
{
	mPendingList.push_back(PendingChange(Clear));
}

bool StateStack::isEmpty() const
{
	return mStack.empty();
}

void StateStack::BuildStateWorld()
{
	mContext.BuildWorld();
}

State::Ptr StateStack::createState(States::ID stateID)
{
	// found (ID, state pointer initiallizer)
	auto found = mFactories.find(stateID);

	assert(found != mFactories.end());

	return found->second();
}


// apply changes for changing state
void StateStack::applyPendingChanges()
{
	for(PendingChange change: mPendingList)
	{
		switch (change.action)
		{
		case Push:
			mStack.push_back(createState(change.stateID));
			break;

		case Pop:
			mStack.pop_back();
			break;

		case Clear:
			mStack.clear();
			break;
		}
	}

	mPendingList.clear();
}






// pendingchange constructor
StateStack::PendingChange::PendingChange(Action action, States::ID stateID)
	: action(action)
	, stateID(stateID)
{
}