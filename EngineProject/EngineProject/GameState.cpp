#include "GameState.h"

GameState::GameState(StateStack& stack, Context context):
    State(stack, context), 
    mWorld(context.game), 
    mPlayer(*context.player)
{
}

void GameState::draw()
{
    mWorld.draw();
}

bool GameState::update(const GameTimer& gt)
{  
    mWorld.update(gt);

	CommandQueue& commands = mWorld.getCommandQueue();
	mPlayer.handleRealtimeInput(commands);

	return true;

}

bool GameState::handleEvent()
{

	return false;
}
