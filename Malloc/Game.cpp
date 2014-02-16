#include "Game.h"
#include <list>
#include "World.h"
#include <iostream>

sf::Vector2f operator*(const sf::Vector2f& v0, const sf::Vector2f& v1) {
	return sf::Vector2f(v0.x*v1.x, v0.y*v1.y);
}

sf::Vector2f operator/(const sf::Vector2f& v0, const sf::Vector2f& v1) {
	return sf::Vector2f(v0.x/v1.x, v0.y/v1.y);
}

Game::Game() : 
	mWindow(sf::VideoMode(800, 600), "Malloc"),
	mView(sf::FloatRect(0, 0, 800, 600)),
	mData(),
	mStates(mData)
	
{
	mWindow.setView(mView);
	mWindow.setFramerateLimit(60);
	mWindow.setKeyRepeatEnabled(false);
	mStates.changeState(StateList::MENU);
	
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
	mData.mousePos = ((sf::Vector2f)sf::Mouse::getPosition(mWindow) * (sf::Vector2f)mView.getSize()/(sf::Vector2f)mWindow.getSize());

	

	mStates.update(mData);
	mData.events = 0;
}

void Game::draw() {
	mWindow.clear(sf::Color::Black);
	mStates.draw(mWindow);
	
	mWindow.display();
}