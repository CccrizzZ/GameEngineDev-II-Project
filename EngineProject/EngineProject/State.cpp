#include "State.h"
// #include "StateStack.h"



State::Context::Context(World& w, Player& p) : world(&w), player(&p)
{
}

State::State(StateStack& stack, Context context)
	: mStack(&stack)
	, mContext(context)
{
}

State::~State()
{
}

void State::draw()
{
}

bool State::update(const GameTimer& gt)
{
	return false;
}

void State::requestStackPush(States::ID stateID)
{
	mStack->pushState(stateID);
}

void State::requestStackPop()
{
	mStack->popState();
}

void State::requestStateClear()
{
	mStack->clearStates();
}

State::Context State::getContext() const
{
	return mContext;
}
