#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "StateList.h"
#include "GameData.h"
class Game
{
public:
	Game();
	~Game();
	void start();
private:
	void loop();
	void update();
	void draw();
	sf::RenderWindow mWindow;
	sf::View mView;
	GameData mData;
	StateList mStates;
};

