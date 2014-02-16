#include "GameObject.h"

bool GameObject::isType(Creature_Type type) const {
	return mTypes[type];
}

bool GameObject::isSubtype(Creature_Subtype subtype) const {
	return mSubtypes[subtype];
}

void GameObject::resetTypes() {
	mTypes.reset();
}

void GameObject::resetSubtypes() {
	mSubtypes.reset();
}

void GameObject::addType(Creature_Type type) {
	mTypes[type] = true;
}

void GameObject::addSubtype(Creature_Subtype subtype) {
	mSubtypes[subtype] = true;
}