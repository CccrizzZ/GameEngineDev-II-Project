#pragma once
#include "SceneNode.hpp"
#include "Aircraft.hpp"
#include "SpriteNode.h"
#include "CommandQueue.h"
#include "TitleSprite.h"



// NOT USING THIS SCRIPT
class World 
{
public:
	World() = default;
	explicit World(Game* game, State* state);
	void update(const GameTimer& gt);
	void draw();

	void buildScene();
	CommandQueue& getCommandQueue();
	

private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};


private:
	Game* mGame;
	State* CurrState;

	SceneNode* mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;


	// entities
	Aircraft* mPlayerAircraft;
	SpriteNode*	mBackground;
	Aircraft* mEnemy;
	
	
	XMFLOAT3 aircraftSize;
	XMFLOAT3 enemySize;

	CommandQueue cQueue;
};
