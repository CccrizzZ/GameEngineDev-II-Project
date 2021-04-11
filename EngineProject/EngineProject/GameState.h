#pragma once
#include "State.h"
#include "Player.h"
#include "World.hpp"


class GameState : public State
{
public:
    GameState(StateStack* stack, Context* context);

    void draw();
    bool update(const GameTimer& gt);
    virtual bool handleEvent(WPARAM btnState);
    
private:
    Game* mGame;
    Aircraft* mPlayerAircraft;
	SpriteNode*	mBackground;
	Aircraft* mEnemy;
	
    World mWorld;
    Player& mPlayer;
    	
	XMFLOAT3 aircraftSize;
	XMFLOAT3 enemySize;

	CommandQueue cQueue;
};

