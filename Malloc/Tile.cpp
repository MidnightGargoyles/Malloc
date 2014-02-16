#include "Tile.h"


Tile::Tile(unsigned int tileID, bool isSolid) : mID(tileID), mIsSolid(isSolid) {
	mCreature = nullptr;
	mTrap = nullptr;
	mLoot = std::vector<GameObject*>();
}


Tile::~Tile() {

}

bool Tile::isSolid() const {
	return mIsSolid;
}

unsigned int Tile::getID() const {
	return mID;
}

std::vector<GameObject*>& Tile::getLoot() {
	return mLoot;
}

GameObject* Tile::getCreature() {
	return mCreature;
}

GameObject* Tile::getTrap() {
	return mTrap;
}