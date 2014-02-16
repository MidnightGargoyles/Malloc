#pragma once
#include "SFML\System\Clock.hpp"
namespace sf {
	class RenderWindow;
};
struct GameData;
class Command;
#include "SFML\Graphics\Sprite.hpp"
class Shortcut {
public:
	Shortcut(const sf::Vector2f &pos, Command *command);
	~Shortcut();
	void update(GameData &gData);
	void draw(sf::RenderWindow &win);
	
private:
	sf::Sprite mIdle;
	sf::Sprite mPressed;
	sf::Sprite *mActive;
	Command *mAction;
	bool mIsActive;
	sf::Clock mDoubleTapTimer;
};

