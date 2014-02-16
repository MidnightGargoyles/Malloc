#pragma once
namespace sf {
	class RenderWindow;
};
struct GameData;
struct PlayStateData;
#include <bitset>
#include "Creature_Type.h"
#include "Creature_Subtype.h"
#include "SFML\System\Vector2.hpp"
#include "GameObject_Type.h"


class GameObject
{
public:
	virtual ~GameObject() {}

	virtual void update(GameData &gData, PlayStateData &pData) = 0;
	virtual void draw(sf::RenderWindow &win) = 0;
	
	virtual const sf::Vector2i& getPos() const = 0;
	virtual const sf::Vector2i& getTarget() const = 0;

	virtual void setPos( sf::Vector2i pos ) = 0;
	virtual void act( GameObject* obj ) = 0;
	virtual bool isAlly( GameObject* obj ) = 0;

	bool isType(Creature_Type type) const;
	bool isSubtype(Creature_Subtype subtype) const;
	void resetTypes();
	void resetSubtypes();
	void addType(Creature_Type type);
	void addSubtype(Creature_Subtype subtpe);

	virtual GameObject_Type getObjectType() = 0;
private:

	std::bitset<Creature_Type::TYPE_COUNT> mTypes;
	std::bitset<Creature_Subtype::SUBTYPE_COUNT> mSubtypes;
	
};

