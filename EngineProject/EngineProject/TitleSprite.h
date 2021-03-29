#pragma once
#include "Entity.hpp"
#include "CommandQueue.h"


class TitleSprite :  public Entity
{
public:
	// TitleSprite(Game* game);
	TitleSprite(State* state);

	void Update(const GameTimer gt);
	void UpdateWithCmd(CommandQueue& commands);


private:
	virtual void drawCurrent() const;
	virtual void buildCurrent();
};

