#pragma once

class GameObject;

#include <vector>

class Tile
{
public:
	Tile(unsigned int tileID, bool isSolid);
	~Tile();
	bool isSolid() const;
	unsigned int getID() const;
private:
	unsigned int mID;
	bool mIsSolid;

	GameObject* mCreature;
	std::vector<GameObject*> mLoot;
	GameObject* mTrap;
};

