#include "GameState.h"

GameState::GameState(StateStack* stack, Context* context):
    State(stack, context), 
    mPlayer(*context->player), 
    mGame(context->game)
{

    mWorld = World(mGame);

    mWorld.buildScene();

    // OutputDebugString(L"gamestate init");
    // OutputDebugString(L"\n");

}

void GameState::draw()
{
    mWorld.draw();
}

bool GameState::update(const GameTimer& gt)
{  
    
    // update world
    mWorld.update(gt);

    
    // handle player input
	CommandQueue& commands = mWorld.getCommandQueue();
	mPlayer.handleRealtimeInput(commands);


	return true;

}

bool GameState::handleEvent()
{

	return false;
}
