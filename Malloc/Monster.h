#pragma once
#include "GameObject.h"
class Monster : public GameObject {
public:
	Monster();
	~Monster();
	virtual void setPos( sf::Vector2i pos );
	virtual void act( GameObject* obj ) = 0;
	virtual bool isAlly( GameObject* obj );
	virtual GameObject_Type getObjectType();
};

