#include "State.h"
#include "StateStack.h"
#include "World.hpp"
#include "Player.h"
#include "Game.hpp"


State::Context::Context(Player& player, Game& game) : player(&player), game(&game)
{
	world = new World(&game);
}

void State::Context::BuildWorld()
{
	world->buildScene();
}

State::State(StateStack& stack, Context context)
	: mStack(&stack)
	, mContext(context)
{
}

State::~State()
{
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
