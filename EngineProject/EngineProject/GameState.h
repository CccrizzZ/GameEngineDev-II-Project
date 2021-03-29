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
    virtual bool handleEvent();

private:
    Game* mGame;
    
    World mWorld;
    Player& mPlayer;
    
};

