#pragma once
#include "SceneNode.hpp"



class Entity : public SceneNode
{
public:
	// Entity(Game* game);
	Entity(State* state);

	void setVelocity(XMFLOAT2 velocity2);
	void setVelocity(XMFLOAT3 velocity3);
	void setVelocity(float vx, float vy);
	XMFLOAT2 getVelocity2() const;
	XMFLOAT3 getVelocity3() const;


	virtual	void updateCurrent(const GameTimer& gt);

public:
	XMFLOAT3 mVelocity;
};

