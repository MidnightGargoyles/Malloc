#pragma once
namespace sf {
	class RenderWindow;
};
class StateList;
class State
{
public:
	State(StateList &owner);
	virtual ~State(){}
	virtual void update();
	virtual void draw(sf::RenderWindow &win);
protected:
	StateList &mOwner;
};

