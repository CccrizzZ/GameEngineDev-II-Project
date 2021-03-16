#pragma once
#include "Entity.hpp"
#include "CommandQueue.h"

class SpriteNode : public Entity
{
public:
    struct BGMover
    {
        XMFLOAT3 velocity;
    
	    BGMover(float vx, float vy, float vz) : velocity(vx, vy, vz){}
        void operator() (SceneNode& node, const GameTimer& gt) 
        {
            SpriteNode& spriteNode = static_cast<SpriteNode&>(node);
            spriteNode.move(velocity);
        }
    };

	SpriteNode(Game* game);
	void Update(const GameTimer gt);
	void UpdateWithCmd(CommandQueue& commands);

	float backgroundSpeed;

private:
	virtual void drawCurrent() const;
	virtual void buildCurrent();
};
