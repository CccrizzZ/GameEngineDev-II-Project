#pragma once
#include "Entity.hpp"
#include <string>





class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};
	

	Aircraft(Type type, Game* game);
	void Update(const GameTimer& gt);
	unsigned int getCategory() const;

	
private:
	virtual void drawCurrent() const;
	virtual void buildCurrent();


	Type mType;
	std::string mSprite;
};
