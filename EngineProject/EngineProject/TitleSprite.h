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

	string TextureName;

private:
	virtual void drawCurrent() const;
	virtual void buildCurrent();

	
    unique_ptr<RenderItem> SpriteRenderer;

	
};

