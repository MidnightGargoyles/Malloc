#include "Game.h"
#include <list>

Game::Game() : 
	mWindow(sf::VideoMode(800, 600), "Malloc"),
	mView(sf::FloatRect(0, 0, 800, 600)),
	mStates()
{
	mWindow.setView(mView);
	mStates.changeState(StateList::PLAY);
}


Game::~Game()
{
}

void Game::start() {
	loop();
}

void Game::loop() {
	while(mWindow.isOpen()) {
		update();
		draw();
	}
}

void Game::update() {
	std::list<sf::Event> events;
	mData.events = &events;
	sf::Event evt;
	while(mWindow.pollEvent(evt)) {
		switch(evt.type) {
		case sf::Event::Closed:
			mWindow.close();
			break;
		default:
			events.push_back(evt);
			break;
		}
	}
	mStates.update();
	mData.events = 0;
}

void Game::draw() {
	mWindow.clear(sf::Color::Black);

	mStates.draw(mWindow);

	mWindow.display();
}