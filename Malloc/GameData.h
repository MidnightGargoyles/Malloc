#pragma once
#include "SFML\Window\Event.hpp"
#include <list>
struct GameData {
public:
	std::list<sf::Event>* events;

};