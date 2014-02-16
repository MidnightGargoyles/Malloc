#pragma once
namespace sf {
	class RenderWindow;
};
#include "SFML\Graphics\Sprite.hpp"
class Shortcut {
public:
	Shortcut(const sf::Vector2f &pos);
	~Shortcut();
	void draw(sf::RenderWindow &win);
	
private:
	bool mIsActive;
	sf::Sprite mIdle;
	sf::Sprite mActive;
};

