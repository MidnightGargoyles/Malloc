#include "Shortcut.h"
#include "TextureStore.h"
#include "Command.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "GameData.h"

Shortcut::Shortcut(const sf::Vector2f &pos, Command *command) : mIdle(TextureStore::getTexture("res/Malloc_jar_IDLE")), mPressed(TextureStore::getTexture("res/Malloc_jar_PRESSED")), mActive(&mIdle), mAction(command), mIsActive(false), mDoubleTapTimer() {
	mIdle.setPosition(pos);
	mPressed.setPosition(pos);
}


Shortcut::~Shortcut() {
}

void Shortcut::update(GameData &gData) {

	for(auto it = gData.events->begin(); it != gData.events->end(); ++it) {
		switch((*it).type) {
		case sf::Event::MouseButtonPressed:
			if(mActive->getGlobalBounds().contains(gData.mousePos)) {
				if(mIsActive) {
					if(mDoubleTapTimer.getElapsedTime().asMilliseconds() < 300) {
						mAction->execute();
					} else {
						mIsActive = false;
					}
				} else {
					mIsActive = true;
					mDoubleTapTimer.restart();
				}
				mActive = &mPressed;
			} else {
				mActive = &mIdle;
				mIsActive = false;
			}
		default:
			break;
		}
	}
	//}
}

void Shortcut::draw(sf::RenderWindow &win) {
	win.draw(*mActive);
}