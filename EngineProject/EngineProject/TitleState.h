#pragma once
#include "State.h"
#include "Player.h"
#include "World.hpp"
using namespace std;


class TitleState : public State
{
public:
    TitleState(StateStack* stack, Context* context);


    virtual void draw();
    virtual bool update(const GameTimer& gt);
    // virtual bool handleEvent();

private:


    // entities
    TitleSprite* bg;
    TitleSprite* bg2;
    TitleSprite* bg3;


};

