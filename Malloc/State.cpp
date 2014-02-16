#include "State.h"
#include "StateList.h"

State::State(StateList &owner) : mOwner(owner) {

}

void State::update(GameData *gData) {
}

void State::draw(sf::RenderWindow &win) {

}
