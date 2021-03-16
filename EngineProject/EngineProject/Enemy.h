#pragma once
#include "Entity.hpp"
#include <string>
using namespace std;

class Enemy : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};

	Enemy(Type type, Game* game);


private:
	virtual void drawCurrent() const;
	virtual void buildCurrent();

    
	Type mType;
	string mSprite;



};

