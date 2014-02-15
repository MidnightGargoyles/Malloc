#include "Tile.h"


Tile::Tile(unsigned int tileID, bool isSolid) : mID(tileID), mIsSolid(isSolid) {

}


Tile::~Tile() {

}

bool Tile::isSolid() const {
	return mIsSolid;
}

unsigned int Tile::getID() const {
	return mID;
}