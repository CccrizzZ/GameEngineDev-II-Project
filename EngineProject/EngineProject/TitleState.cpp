#include "TitleState.h"

TitleState::TitleState(StateStack& stack, Context context)
    : State(stack, context)
{
}

void TitleState::draw()
{
}

bool TitleState::update(const GameTimer& gt)
{
	return false;
}
