#include "Entity.hpp"
#include "State.h"

// Entity::Entity(Game* game) : SceneNode(game), mVelocity(0, 0, 0)
// {
// }

Entity::Entity(State* state) : SceneNode(state), mVelocity(0, 0, 0)
{
}


void Entity::setVelocity(XMFLOAT2 velocity2)
{
	mVelocity.x = velocity2.x;
	mVelocity.y = velocity2.y;

}

void Entity::setVelocity(XMFLOAT3 velocity3)
{
	mVelocity = velocity3;
}

void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}


XMFLOAT3 Entity::getVelocity3() const
{
	return mVelocity;
}

XMFLOAT2 Entity::getVelocity2() const
{
	return XMFLOAT2(mVelocity.x, mVelocity.y);
}

void Entity::updateCurrent(const GameTimer& gt) 
{
	XMFLOAT3 mV;
	mV.x = mVelocity.x * gt.DeltaTime();
	mV.y = mVelocity.y * gt.DeltaTime();
	mV.z = mVelocity.z * gt.DeltaTime();

	move(mV.x, mV.y, mV.z);

	renderer->World = getWorldTransform();
	renderer->NumFramesDirty++;
}
