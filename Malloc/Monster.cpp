#include "Monster.h"


Monster::Monster(void)
{
}


Monster::~Monster(void)
{
}


void Monster::setPos( sf::Vector2i pos ) {
	
}
bool Monster::isAlly( GameObject* obj ) {
	return true;
}

GameObject_Type Monster::getObjectType() {
	return GameObject_Type::MONSTER;
}