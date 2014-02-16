#include "Shortcut.h"
#include "TextureStore.h"

Shortcut::Shortcut(const sf::Vector2f &pos) : mIdle(TextureStore::getTexture("res/Mallic_jar_IDLE")), mActive(TextureStore::getTexture("res/Malloc_jar_PRESSED")) {
	mIdle.setPosition(pos);
	mActive.setPosition(pos);
}


Shortcut::~Shortcut() {
}
