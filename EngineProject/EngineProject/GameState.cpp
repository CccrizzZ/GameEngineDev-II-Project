#include "GameState.h"

GameState::GameState(StateStack& stack, Context context) : State(stack, context), mWorld(*context.world), mPlayer(*context.player)
{
}

void GameState::draw()
{
    mWorld.draw();
}

bool GameState::update(const GameTimer& gt)
{  
    mWorld.update(gt);


	return false;
}

bool GameState::handleEvent()
{

	return false;
}
