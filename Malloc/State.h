#pragma once
namespace sf {
	class RenderWindow;
};
struct GameData;
class StateList;
class State
{
public:
	State(StateList &owner);
	virtual ~State(){}
	virtual void update(GameData *gData);
	virtual void draw(sf::RenderWindow &win);
protected:
	StateList &mOwner;
};

