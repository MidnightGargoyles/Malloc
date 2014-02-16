#pragma once
#include "GameObject.h"
#include "SFML\System\Vector2.hpp"
#include "SFML\Graphics\Sprite.hpp"

class Player : public GameObject {
public:
	Player(const sf::Vector2i startPos);
	~Player();

	virtual void update(GameData &gData, PlayStateData &pData);
	virtual void draw(sf::RenderWindow &win);
	
	virtual const sf::Vector2i& getPos() const;
	virtual const sf::Vector2i& getTarget() const;
private:
	sf::Vector2i mPos;
	sf::Sprite mSprite;
};

