#pragma once
class GameObject;
class Player;
#include "World.h"
#include <vector>
struct PlayStateData {
	World w;
	std::vector<GameObject*> gameObjects;
	Player* player;
};