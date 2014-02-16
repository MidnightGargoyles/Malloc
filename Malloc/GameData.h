#pragma once
#include "SFML\System\Vector2.hpp"
#include "SFML\Window\Event.hpp"
#include <list>
#include "Difficulty.h"


struct GameData {
public:
	sf::Vector2f mousePos;
	std::list<sf::Event>* events;
	diff::Difficulty difficulty;
};