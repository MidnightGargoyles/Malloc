#pragma once
#include "Monster.h"
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\System\Vector2.hpp"

class DireRat : public Monster {
public:
	DireRat(const sf::Vector2i &startPos);
	~DireRat();

	virtual void update(GameData &gData, PlayStateData &pData);
	virtual void draw(sf::RenderWindow &win);
	
	virtual const sf::Vector2i& getPos() const;
	virtual const sf::Vector2i& getTarget() const;

	virtual void act( GameObject* obj );
private:
	sf::Vector2i mPos;
	sf::Sprite mSprite;
};

