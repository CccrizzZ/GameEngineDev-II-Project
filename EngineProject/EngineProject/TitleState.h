#pragma once
#include "State.h"



class TitleState : public State
{
public:
    TitleState(StateStack& stack, Context context);


    virtual void draw();
    virtual bool update(const GameTimer& gt);
    // virtual bool handleEvent();

private:



};

