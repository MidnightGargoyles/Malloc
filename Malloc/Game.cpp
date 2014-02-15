#include "Game.h"


Game::Game() : 
	mWindow(sf::VideoMode(800, 600), "Malloc"),
	mView(sf::FloatRect(0, 0, 800, 600)),
	mStates()
{
	mWindow.setView(mView);
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
	sf::Event evt;
	while(mWindow.pollEvent(evt)) {
		switch(evt.type) {
		case sf::Event::Closed:
			mWindow.close();
			break;
		default:
			break;
		}
	}
	mStates.update();
}

void Game::draw() {
	mWindow.clear(sf::Color::Black);

	mStates.draw();

	mWindow.display();
}